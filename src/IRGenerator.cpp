//
// Created by Fan Long on 2020/12/6.
//

//add more header files if your want
#include "IRGenerator.h"
#include "llvm/IR/Module.h"
#include "Declarations.h"
#include "Program.h"
#include "Exprs.h"
#include "Statements.h"

namespace minicc {
    //add your member helper functions
    llvm::Type *IRGenerator::toLLVMType(Type type) {
        llvm::Type *primType;
        switch (type.primitiveType()) {
            case Type::Int:
                primType = llvm::Type::getInt32Ty(*TheContext);
                break;
            case Type::Bool:
                primType = llvm::Type::getInt1Ty(*TheContext);
                break;
            case Type::Char:
                primType = llvm::Type::getInt8Ty(*TheContext);
                break;
            default:
                primType = llvm::Type::getVoidTy(*TheContext);
        }
        if (type.arrayBound() > 0)
            return llvm::ArrayType::get(primType, type.arrayBound());
        else
            return primType;
    }

    llvm::Value *IRGenerator::declareVar(Type type, std::string name, bool global) {
        llvm::Type *llvmType = toLLVMType(type);
        llvm::Constant *init;
        llvm::Value *arraySizeVal = nullptr;

        if (type.arrayBound() > 0){
            init = llvm::ConstantAggregateZero::get(llvmType);
            arraySizeVal = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), type.arrayBound(), false);
        } else {
            init = llvm::ConstantInt::get(llvmType, 0, type.isInt());
        }

        if (global) {
            return new llvm::GlobalVariable(*TheModule, llvmType, false, llvm::GlobalVariable::CommonLinkage, init, name);
        } else
            return TheBuilder->CreateAlloca(llvmType, arraySizeVal, name);
    }

    llvm::Function *IRGenerator::declareFunc(Type retType, std::vector<Type> paramTypes, std::string name) {
        llvm::Type *llvmRetType = toLLVMType(retType);
        std::vector<llvm::Type*> llvmParamTypes; 
        for (size_t i = 0; i < paramTypes.size(); i++) 
            llvmParamTypes.push_back(toLLVMType(paramTypes[i]));
        llvm::FunctionType *funcType = llvm::FunctionType::get(llvmRetType, llvmParamTypes, false);
        return llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, TheModule.get());
    }

    llvm::Value *IRGenerator::getGEP(std::string name, VarSymbolTable *table, llvm::ConstantInt *idx) {
        llvm::Value *val = table->get(name).LLVMValue;
        Type varType = table->get(name).VarType;
        llvm::Type *type = toLLVMType(Type(varType.primitiveType()));
        llvm::Type *arrayType = toLLVMType(varType);
        llvm::Type *pointerType = llvm::PointerType::get(type, 0);

        llvm::Value *fst = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0, false);
        llvm::Value *gep = TheBuilder->CreateGEP(arrayType, val, std::vector<llvm::Value*>{fst, idx});
        return gep;
    }

    void IRGenerator::visitThisNode(ASTNode *node) {
        node->accept(this);
    }

    void IRGenerator::visitProgram(Program *prog) {
        //Initlize llvm module and builder
        TheModule = std::make_unique<llvm::Module>(ModuleName, *TheContext);
        TheBuilder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
        //start your code here
        std::vector<std::string> names{"getint", "putint", "putcharacter", "putnewline"};
        FuncSymbolTable *table = prog->funcTable();
        for (int i = 0; i < names.size(); i++)
            if (table->contains(names[i])) {
                FuncSymbolEntry entry = table->get(names[i]);
                declareFunc(entry.ReturnType, entry.ParameterTypes, names[i]);
            }

        ASTVisitor::visitASTNode(prog);
    }

    void IRGenerator::visitVarDecl(VarDeclaration *decl) {
        //start your code here
        ASTVisitor::visitASTNode(decl);

        for (size_t i = 0; i < decl->numVarReferences(); i++) {
            std::string name = decl->varReference(i)->identifier()->name();
            VarSymbolTable *table = decl->locateDeclaringTableForVar(name);

            llvm::Value* val = declareVar(table->get(name).VarType, name, decl->getParent()->isProgram());
            table->updateWithValue(name, val);
        }
    }

    void IRGenerator::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
        std::vector<Type> paramTypes;
        for (size_t i = 0; i < func->numParameters(); i++) 
            paramTypes.push_back(func->parameter(i)->type());
        llvm::Function *funcObj = declareFunc(func->returnType(), paramTypes, func->name());

        if (func->hasBody()) {
            llvm::BasicBlock *bb = llvm::BasicBlock::Create(*TheContext, func->name() + "_entry", funcObj);
            TheBuilder->SetInsertPoint(bb);

            ScopeStatement *scope = func->body();
            VarSymbolTable *table = scope->scopeVarTable();
            for (size_t i = 0; i < func->numParameters(); i++) {
                Parameter *param = func->parameter(i);
                llvm::Value *arg = funcObj->getArg(i);

                llvm::Value *argVar = TheBuilder->CreateAlloca(toLLVMType(param->type()), nullptr, param->name());
                llvm::Value *storeVal = TheBuilder->CreateStore(arg, argVar);
                table->updateWithValue(param->name(), argVar);
            }

            ASTVisitor::visitASTNode(func);

            llvm::Value *term = TheBuilder->GetInsertBlock()->getTerminator();
            if (term == nullptr)
                llvm::Value *ret = TheBuilder->CreateRetVoid();
        }
    }

    void IRGenerator::visitIfStmt(IfStatement *stmt) {
        //start your code here

        llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(*TheContext, "then", TheBuilder->GetInsertBlock()->getParent());
        llvm::BasicBlock *elseBB;
        if (stmt->hasElse())
            elseBB = llvm::BasicBlock::Create(*TheContext, "else", TheBuilder->GetInsertBlock()->getParent());
        llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(*TheContext, "after", TheBuilder->GetInsertBlock()->getParent());

        // current BB
        visitThisNode(stmt->condExpr());
        llvm::Value *cond = ExprValues[stmt->condExpr()];
        if (TheBuilder->GetInsertBlock()->getTerminator() == nullptr)
            llvm::Value *condBr = TheBuilder->CreateCondBr(cond, thenBB, stmt->hasElse() ? elseBB : afterBB);

        // then BB
        TheBuilder->SetInsertPoint(thenBB);
        visitThisNode(stmt->thenStmt());
        if (TheBuilder->GetInsertBlock()->getTerminator() == nullptr)
            TheBuilder->CreateBr(afterBB);

        // else BB
        if (stmt->hasElse()) {
            TheBuilder->SetInsertPoint(elseBB);
            visitThisNode(stmt->elseStmt());
            if (TheBuilder->GetInsertBlock()->getTerminator() == nullptr)
                TheBuilder->CreateBr(afterBB);
        }

        TheBuilder->SetInsertPoint(afterBB);
    }

    void IRGenerator::visitForStmt(ForStatement *stmt) {
        //start your code here
        llvm::BasicBlock *condBB = llvm::BasicBlock::Create(*TheContext, "cond", TheBuilder->GetInsertBlock()->getParent());
        llvm::BasicBlock *bodyBB = llvm::BasicBlock::Create(*TheContext, "body", TheBuilder->GetInsertBlock()->getParent());
        llvm::BasicBlock *stepBB = llvm::BasicBlock::Create(*TheContext, "step", TheBuilder->GetInsertBlock()->getParent());
        llvm::BasicBlock *exitBB = llvm::BasicBlock::Create(*TheContext, "after", TheBuilder->GetInsertBlock()->getParent());
        ForStmtStepBBs[stmt] = stepBB;
        ForStmtExitBBs[stmt] = exitBB;

        // current BB
        if (stmt->initExpr() != nullptr)
            visitThisNode(stmt->initExpr());
        TheBuilder->CreateBr(condBB);

        // cond BB
        TheBuilder->SetInsertPoint(condBB);
        visitThisNode(stmt->condExpr());
        llvm::Value *cond = ExprValues[stmt->condExpr()];
        TheBuilder->CreateCondBr(cond, bodyBB, exitBB);

        // body BB
        TheBuilder->SetInsertPoint(bodyBB);
        visitThisNode(stmt->body());
        if (TheBuilder->GetInsertBlock()->getTerminator() == nullptr)
            TheBuilder->CreateBr(stepBB);
        
        // step BB
        TheBuilder->SetInsertPoint(stepBB);
        if (stmt->iterExpr() != nullptr)
            visitThisNode(stmt->iterExpr());
        if (TheBuilder->GetInsertBlock()->getTerminator() == nullptr)
            TheBuilder->CreateBr(condBB);

        TheBuilder->SetInsertPoint(exitBB);
    }

    void IRGenerator::visitContinueStmt(ContinueStatement *stmt) {
        //start your code here
        ForStatement *forStmt = stmt->getParentForStatement();
        llvm::BasicBlock *stepBB = ForStmtStepBBs[forStmt];
        TheBuilder->CreateBr(stepBB);
    }

    void IRGenerator::visitReturnStmt(ReturnStatement *stmt) {
        //start your code here
        ASTVisitor::visitASTNode(stmt);

        if (stmt->hasReturnExpr()) {
            llvm::Value *ret = ExprValues[stmt->returnExpr()];
            TheBuilder->CreateRet(ret);
        } else
            TheBuilder->CreateRetVoid();
    }

    void IRGenerator::visitBreakStmt(BreakStatement *stmt) {
        //start your code here
        ForStatement *forStmt = stmt->getParentForStatement();
        llvm::BasicBlock *exitBB = ForStmtExitBBs[forStmt];
        TheBuilder->CreateBr(exitBB);
    }


    void IRGenerator::visitUnaryExpr(UnaryExpr *expr) {
        //start your code here
        ASTVisitor::visitASTNode(expr);

        llvm::Value *subVal = ExprValues[(Expr*) expr->getChild(0)];
        switch (expr->opcode()) {
            case Expr::ExprOpcode::Sub:
                ExprValues[expr] = TheBuilder->CreateNeg(subVal);
                break;
            case Expr::ExprOpcode::Not:
                ExprValues[expr] = TheBuilder->CreateNot(subVal);
        }
    }

    void IRGenerator::visitBinaryExpr(BinaryExpr *expr) {
        //start your code here
        if (expr->opcode() != Expr::ExprOpcode::And && expr->opcode() != Expr::ExprOpcode::Or) {
            ASTVisitor::visitASTNode(expr);
            llvm::Value *left = ExprValues[(Expr*) expr->getChild(0)];
            llvm::Value *right = ExprValues[(Expr*) expr->getChild(1)];

            switch (expr->opcode()) {
                case Expr::ExprOpcode::Add:
                    ExprValues[expr] = TheBuilder->CreateAdd(left, right);
                    break;
                case Expr::ExprOpcode::Sub:
                    ExprValues[expr] = TheBuilder->CreateSub(left, right);
                    break;
                case Expr::ExprOpcode::Mul:
                    ExprValues[expr] = TheBuilder->CreateMul(left, right);
                    break;
                case Expr::ExprOpcode::Div:
                    ExprValues[expr] = TheBuilder->CreateSDiv(left, right);
                    break;
                case Expr::ExprOpcode::Equal:
                    ExprValues[expr] = TheBuilder->CreateICmpEQ(left, right);
                    break;
                case Expr::ExprOpcode::NotEqual:
                    ExprValues[expr] = TheBuilder->CreateICmpNE(left, right);
                    break;
                case Expr::ExprOpcode::Less:
                    ExprValues[expr] = TheBuilder->CreateICmpSLT(left, right);
                    break;
                case Expr::ExprOpcode::LessEqual:
                    ExprValues[expr] = TheBuilder->CreateICmpSLE(left, right);
                    break;
                case Expr::ExprOpcode::Greater:
                    ExprValues[expr] = TheBuilder->CreateICmpSGT(left, right);
                    break;
                case Expr::ExprOpcode::GreaterEqual:
                    ExprValues[expr] = TheBuilder->CreateICmpSGE(left, right);
            }
        } else {
            visitThisNode(expr->getChild(0));
            llvm::Value *left = ExprValues[(Expr*) expr->getChild(0)];

            llvm::BasicBlock *current = TheBuilder->GetInsertBlock();
            llvm::BasicBlock *slow = llvm::BasicBlock::Create(*TheContext, "slow", TheBuilder->GetInsertBlock()->getParent());
            llvm::BasicBlock *out = llvm::BasicBlock::Create(*TheContext, "out", TheBuilder->GetInsertBlock()->getParent());
            
            // current BB
            if (expr->opcode() == Expr::ExprOpcode::And)
                TheBuilder->CreateCondBr(left, slow, out);
            else
                TheBuilder->CreateCondBr(left, out, slow);

            // slow BB
            TheBuilder->SetInsertPoint(slow);
            visitThisNode(expr->getChild(1));
            llvm::Value *right = ExprValues[(Expr*) expr->getChild(1)];
            TheBuilder->CreateBr(out);

            // out BB
            TheBuilder->SetInsertPoint(out);
            llvm::Type *type = toLLVMType(Type(Type::PrimitiveTypeEnum::Bool));
            llvm::PHINode *phi = TheBuilder->CreatePHI(type, 2);
            phi->addIncoming(left, current);
            phi->addIncoming(right, slow);

            ExprValues[expr] = phi;
        }
    }

    void IRGenerator::visitCallExpr(CallExpr *expr) {
        //start your code here
        ASTVisitor::visitASTNode(expr);
        llvm::Function* func = TheModule->getFunction(expr->callee()->name());

        std::vector<llvm::Value*> args;
        for (size_t i = 0; i < expr->numArgs(); i++)
            args.push_back(ExprValues[(Expr*) expr->arg(i)]);

        llvm::Value *val = TheBuilder->CreateCall(func, std::vector<llvm::Value*>(args));
        ExprValues[expr] = val;
    }

    void IRGenerator::visitVarExpr(VarExpr *expr) {
        //start your code here
        ASTVisitor::visitASTNode(expr);

        VarReference *varref = (VarReference*) expr->getChild(0);
        std::string name = varref->identifier()->name();

        VarSymbolTable *table = expr->locateDeclaringTableForVar(name);
        Type varType = table->get(name).VarType;
        llvm::Type *type = toLLVMType(Type(varType.primitiveType()));
        llvm::Value *val;

        if (varref->isArray()) {
            llvm::Value *idx = ExprValues[varref->indexExpr()];
            val = getGEP(name, table, (llvm::ConstantInt*) idx);
        } else
            val = table->get(name).LLVMValue;
        
        llvm::Value *loadVal = TheBuilder->CreateLoad(type, val);
        ExprValues[expr] = loadVal;
    }

    void IRGenerator::visitAssignmentExpr(AssignmentExpr *expr) {
        //start your code here
        ASTVisitor::visitASTNode(expr);

        VarReference *varref = (VarReference*) expr->getChild(0);
        std::string name = varref->identifier()->name();
        VarSymbolTable *table = expr->locateDeclaringTableForVar(name);
        llvm::Value *varVal;

        if (varref->isArray()) {
            llvm::Value *idx = ExprValues[varref->indexExpr()];
            varVal = getGEP(name, table, (llvm::ConstantInt*) idx);
        } else
            varVal = table->get(name).LLVMValue;

        llvm::Value *exprVal = ExprValues[(Expr*) expr->getChild(1)];
        TheBuilder->CreateStore(exprVal, varVal);
    }

    void IRGenerator::visitIntLiteralExpr(IntLiteralExpr *literal) {
        //start your code here
        llvm::Value *val = llvm::ConstantInt::get(toLLVMType(Type(Type::PrimitiveTypeEnum::Int)), literal->value(), true);
        ExprValues[literal] = val;
    }

    void IRGenerator::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        //start your code here
        llvm::Value *val = llvm::ConstantInt::get(toLLVMType(Type(Type::PrimitiveTypeEnum::Bool)), literal->value(), false);
        ExprValues[literal] = val;
    }

    void IRGenerator::visitCharLiteralExpr(CharLiteralExpr *literal) {
        //start your code here
        llvm::Value *val = llvm::ConstantInt::get(toLLVMType(Type(Type::PrimitiveTypeEnum::Char)), literal->value(), false);
        ExprValues[literal] = val;
    }

    void IRGenerator::visitScope(ScopeStatement *stmt) {
        //start your code here
        for (size_t i = 0; i < stmt->numChildren(); i++) {
            if (TheBuilder->GetInsertBlock()->getTerminator() != nullptr)
                return;
            visitThisNode(stmt->getChild(i));
        }
    }

}