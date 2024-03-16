//
// Created by Fan Long on 2020/12/4.
//

//Add necessary headers you want
#include "VerifyAndBuildSymbols.h"
#include "Declarations.h"
#include "Terms.h"
#include "Types.h"
#include "Exprs.h"
#include "Statements.h"
#include "Program.h"
#include <string>
#include <sstream>
#include <set>

namespace minicc {

    void VerifyAndBuildSymbols::visitASTNode(ASTNode *node) {
        //start your code here
        //Hint: set root of the node before visiting children
        node->setRoot(VisitingProgram);
        ASTVisitor::visitASTNode(node);
    }

    void VerifyAndBuildSymbols::visitProgram(Program *prog) {
        //start your code here
        VisitingProgram = prog;
        if (prog->syslibFlag()) {
            // Manually populate the function symbol table
            prog->funcTable()->insert("getint", FuncSymbolEntry(Type(Type::PrimitiveTypeEnum::Int), std::vector<Type>(), true));
            prog->funcTable()->insert("putint", FuncSymbolEntry(Type(Type::PrimitiveTypeEnum::Void), std::vector<Type>{Type(Type::PrimitiveTypeEnum::Int)}, true));
            prog->funcTable()->insert("putcharacter", FuncSymbolEntry(Type(Type::PrimitiveTypeEnum::Void), std::vector<Type>{Type(Type::PrimitiveTypeEnum::Char)}, true));
            prog->funcTable()->insert("putnewline", FuncSymbolEntry(Type(Type::PrimitiveTypeEnum::Void), std::vector<Type>(), true));
        }
        ASTVisitor::visitProgram(prog);
    }

    void VerifyAndBuildSymbols::visitVarDecl(VarDeclaration *decl) {
        //start your code here
        ASTVisitor::visitVarDecl(decl);
        //Hint: Check that same variable cannot be declared twice in the same scope
        ASTNode *scope = decl->getParentScope();
        if (scope == nullptr)
            scope = decl->root();
        VarSymbolTable *varTable = scope->scopeVarTable();

        TypeReference *typeRef = (TypeReference*) decl->getChild(0);
        for (int i = 0; i < decl->numVarReferences(); i++) {
            VarReference *ref = (VarReference*) decl->varReference(i);
            std::string name = ref->identifier()->name();
            if (varTable->contains(name)) {
                Errors.push_back(ErrorMessage("Redefinition of variable/parameter \"" + name + "\" in the same scope!", ref->srcLoc()));
                continue;
            }
            
            size_t arrayBound = 0;
            if (ref->isArray()) {
                IntLiteralExpr *indexExpr = (IntLiteralExpr*) ref->indexExpr();
                arrayBound = (size_t) indexExpr->value();
            }
            Type type = Type(typeRef->value().primitiveType(), arrayBound);
            varTable->insert(name, VarSymbolEntry(type));
        }
    }

    void VerifyAndBuildSymbols::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
        //Hint: Check return type of the function does not match with each other
        //      Check number of parameters should match with each other
        //      Check each parameter type should match with each other
        //      Check there should be only one definition of the function
        //      Check parameters cannot have the same name
        //      Check the last statement a function body must be return if the return type is not void
        
        std::string name = func->name();        
        FuncSymbolTable *funcTable = VisitingProgram->funcTable();
        if (funcTable->contains(name)) {
            FuncSymbolEntry entry = funcTable->get(name);
            if (entry.ReturnType != func->returnType()) 
                Errors.push_back(ErrorMessage("Definition of function \"" + name + "()\" with different return type!", func->srcLoc()));
            if (entry.ParameterTypes.size() != func->numParameters()) 
                Errors.push_back(ErrorMessage("Definition of function \"" + name + "()\" with different number of parameters!", func->srcLoc()));
            else 
                for (int i = 0; i < entry.ParameterTypes.size(); i++)
                    if (entry.ParameterTypes[i] != func->parameter(i)->type()) 
                        Errors.push_back(ErrorMessage("Definition of function \"" + name + "()\" with different parameter type at position " + std::to_string(i) + "!", func->srcLoc()));
            
            if (func->hasBody()) {
                if (entry.HasBody)
                    Errors.push_back(ErrorMessage("Redefinition of function \"" + name + "()\"!", func->srcLoc()));
                funcTable->setHasBody(name, true);
            }
        } else {
            std::vector<Type> parameterTypes;
            std::set<std::string> parameterNames;
            for (int i = 0; i < func->numParameters(); i++) {
                Parameter *parameter = func->parameter(i);
                parameterTypes.push_back(parameter->type());
                std::string name = parameter->name();
                if (parameterNames.find(name) != parameterNames.end()) 
                    Errors.push_back(ErrorMessage("Redefinition of variable/parameter " + name + " in the same scope!", func->srcLoc()));
                parameterNames.insert(name);
            }
            funcTable->insert(name, FuncSymbolEntry(func->returnType(), parameterTypes, func->hasBody()));
        }

        if (func->hasBody()) {
            ScopeStatement *scope = func->body();
            for (int i = 0; i < func->numParameters(); i++) {
                Parameter *parameter = func->parameter(i);
                std::string name = parameter->name();
                if (!scope->scopeVarTable()->contains(name)) 
                    scope->scopeVarTable()->insert(name, VarSymbolEntry(parameter->type()));
            }

            if (!func->returnType().isVoid() && (scope->numChildren() == 0 || dynamic_cast<ReturnStatement*> (scope->getChild(scope->numChildren() - 1)) == nullptr))
                Errors.push_back(ErrorMessage("The function \"" + name + "()\" need to return a value at its end!", func->srcLoc()));
        }

        ASTVisitor::visitFuncDecl(func);
    }

    void VerifyAndBuildSymbols::visitIfStmt(IfStatement *stmt) {
        //start your code here
        ASTVisitor::visitIfStmt(stmt);
        //Hint: Check the conditional expression must have bool type
        Expr *condExpr = stmt->condExpr();
        if (condExpr != nullptr && !condExpr->exprType().isBool())
            Errors.push_back(ErrorMessage("Conditional expression in if statement has non-bool type!", condExpr->srcLoc()));
    }

    void VerifyAndBuildSymbols::visitForStmt(ForStatement *stmt) {
        //start your code here
        ASTVisitor::visitForStmt(stmt);
        //Hint: Check the second expression in for must be either null or bool type
        Expr *condExpr = stmt->condExpr();
        if (condExpr != nullptr && !condExpr->exprType().isBool())
            Errors.push_back(ErrorMessage("Conditional expression in for statement has non-bool type!", stmt->srcLoc()));
    }

    void VerifyAndBuildSymbols::visitContinueStmt(ContinueStatement *stmt) {
        //start your code here
        ASTVisitor::visitContinueStmt(stmt);
        //Hint: Check Continue statement must appear inside a for statement
        if (stmt->getParentForStatement() == nullptr)
            Errors.push_back(ErrorMessage("Continue statement must appear inside a for statement!", stmt->srcLoc()));
    }

    void VerifyAndBuildSymbols::visitReturnStmt(ReturnStatement *stmt) {
        //start your code here
        ASTVisitor::visitReturnStmt(stmt);
        //Hint: Check void function must have no expression to return
        //      Check Non-Void function must have an expression to return
        //      Check the return type and the returned expression type must match
        FuncDeclaration *func = stmt->getParentFunction();
        if (func->returnType().isVoid()) {
            if (stmt->hasReturnExpr())
                Errors.push_back(ErrorMessage("Function has void return type, but the return statement has a returned expression!", stmt->srcLoc()));
        } else if (!stmt->hasReturnExpr())
            Errors.push_back(ErrorMessage("Function has non-void return type, but the return statement has no returned expression!", stmt->srcLoc()));
        else if (stmt->returnExpr()->exprType() != func->returnType()) { 
            Type::PrimitiveTypeEnum expected = func->returnType().primitiveType();
            Type::PrimitiveTypeEnum actual = stmt->returnExpr()->exprType().primitiveType();
            Errors.push_back(ErrorMessage("Function has return type \"" + Type::typeToString(expected) + "\", but the returned expression has type \"" + Type::typeToString(actual) + "\"!", stmt->srcLoc()));
        }
    }

    void VerifyAndBuildSymbols::visitBreakStmt(BreakStatement *stmt) {
        //start your code here
        ASTVisitor::visitBreakStmt(stmt);
        //Hint: Check Break statement must appear inside a for statement
        if (stmt->getParentForStatement() == nullptr)
            Errors.push_back(ErrorMessage("Break statement must appear inside a for statement!", stmt->srcLoc()));
    }

    void VerifyAndBuildSymbols::visitUnaryExpr(UnaryExpr *expr) {
        //start your code here
        ASTVisitor::visitUnaryExpr(expr);
        //Hint: Check Negate opcode must have int operand!
        //      Check Not opcode must have bool operand
        Expr::ExprOpcode opcode = expr->opcode();
        Type type = ((Expr*) expr->getChild(0))->exprType();
        if (opcode == Expr::ExprOpcode::Sub) {
            if (!type.isInt())
                Errors.push_back(ErrorMessage("Negate \"-\" opcode must have int operand!", expr->srcLoc()));
        } else {
            assert(opcode == Expr::ExprOpcode::Not);
            if (!type.isBool())
                Errors.push_back(ErrorMessage("Not \"!\" opcode must have bool operand!", expr->srcLoc()));
        }
        expr->setExprType(type);
    }

    void VerifyAndBuildSymbols::visitBinaryExpr(BinaryExpr *expr) {
        //start your code here
        ASTVisitor::visitBinaryExpr(expr);
        //Hint: Check that for logical opcode, both operand need to be bool
        //      Check that for equal and not equal opcode, both operand need to be the same primitive types
        //      Check that for arithmetic and other comparison operand, both operand need to be int
        Expr::ExprOpcode opcode = expr->opcode();
        Type leftType = ((Expr*) expr->getChild(0))->exprType();
        Type rightType = ((Expr*) expr->getChild(1))->exprType();
        if (opcode == Expr::ExprOpcode::Equal || opcode == Expr::ExprOpcode::NotEqual) {
            if (leftType != rightType || leftType.arrayBound() != 0 || rightType.arrayBound() != 0)
                Errors.push_back(ErrorMessage("\"==\"/\"!=\" opcode must have same primitive type operand!", expr->srcLoc()));
            
            expr->setExprType(Type(Type::PrimitiveTypeEnum::Bool));
        } else if (opcode == Expr::ExprOpcode::And || opcode == Expr::ExprOpcode::Or) {
            if (!leftType.isBool() || !rightType.isBool()) 
                Errors.push_back(ErrorMessage("\"&&\"/\"||\" opcode must have bool operand!", expr->srcLoc()));

            expr->setExprType(leftType);
        } else {
            if (!leftType.isInt() || !rightType.isInt())
                Errors.push_back(ErrorMessage("\"" + Expr::opcodeToString(opcode) + "\" opcode must have int type operand!", expr->srcLoc()));
            
            if (opcode == Expr::ExprOpcode::Less || opcode == Expr::ExprOpcode::LessEqual || opcode == Expr::ExprOpcode::Greater || opcode == Expr::ExprOpcode::GreaterEqual)
                expr->setExprType(Type(Type::PrimitiveTypeEnum::Bool));
            else
                expr->setExprType(leftType);
        }
    }

    void VerifyAndBuildSymbols::visitCallExpr(CallExpr *expr) {
        //start your code here
        ASTVisitor::visitCallExpr(expr);
        //Hint: Check Call undeclared function
        //      Check the number of arguments must match the number of parameters
        //      Check the type of each parameter must match the argument
        FuncSymbolTable *funcTable = expr->root()->funcTable();
        std::string name = expr->callee()->name();

        if (!funcTable->contains(name)) {
            Errors.push_back(ErrorMessage("Function " + name + "() is not declared before use!", expr->srcLoc()));
            expr->setExprType(Type(Type::Void));
        } else {
            FuncSymbolEntry entry = funcTable->get(name);
            size_t expected = entry.ParameterTypes.size();
            size_t actual = expr->numArgs();
            if (actual != expected) 
                Errors.push_back(ErrorMessage("Function " + name + "() is declared with " + std::to_string(expected) + " parameters but called with " + std::to_string(actual) + " arguments!", expr->srcLoc()));
            else
                for (int i = 0; i < entry.ParameterTypes.size(); i++) 
                    if (expr->arg(i)->exprType() != entry.ParameterTypes[i]) 
                        Errors.push_back(ErrorMessage("Function " + name + "() does not match the type of the call argument at position " + std::to_string(i) + "!", expr->srcLoc()));
            expr->setExprType(entry.ReturnType);
        }
    }

    static Type verifyVarReference(std::vector<ErrorMessage> & Errors, Expr* expr, VarReference *ref) {
        //start your code here
        //Hint: Check the vairable which is reference must be declared before
        //      Check index expression must have int type
        //      Check variable must be declared as an array for indexing
        //return ref Type
        Identifier *id = ref->identifier();
        VarSymbolTable *varTable = expr->locateDeclaringTableForVar(id->name());
        std::string name = id->name();
        
        if (varTable == nullptr) {
            Errors.push_back(ErrorMessage("Variable " + name + " is not declared before use!", ref->srcLoc()));
            return Type(Type::Void);
        }
        Type varType = varTable->get(name).VarType;
        
        if (ref->isArray()) {
            if (!ref->indexExpr()->exprType().isInt()) 
                Errors.push_back(ErrorMessage("Array index expressions must have int operand!", ref->srcLoc()));
            if (varType.arrayBound() == 0)
                Errors.push_back(ErrorMessage("Indexing an non-array variable!", ref->srcLoc()));
            return Type(varType.primitiveType());
        }

        return varType;
    }

    void VerifyAndBuildSymbols::visitVarExpr(VarExpr *expr) {
        //start your code here
        ASTVisitor::visitVarExpr(expr);
        //Hint: invoke verifyVarReference to verify
        VarReference *ref = (VarReference*) expr->getChild(0);
        Type varType = verifyVarReference(Errors, expr, ref);
        
        expr->setExprType(varType);
    }

    void VerifyAndBuildSymbols::visitAssignmentExpr(AssignmentExpr *expr) {
        //start your code here
        ASTVisitor::visitAssignmentExpr(expr);
        //Hint: invoke verifyVarReference to verify
        //      Also, check var and assigned expression must have the same type
        VarReference *ref = (VarReference*) expr->getChild(0);
        Expr *childExpr = (Expr*) expr->getChild(1);

        Type varType = verifyVarReference(Errors, expr, ref);
        if (!varType.isVoid() && varType != childExpr->exprType())
            Errors.push_back(ErrorMessage("Variable and the assignment expression do not have the same type!", expr->srcLoc()));
        
        expr->setExprType(varType);
    }

    void VerifyAndBuildSymbols::visitIntLiteralExpr(IntLiteralExpr *literal) {
        //start your code here
        ASTVisitor::visitIntLiteralExpr(literal);
        //Hint: Check Integer literal must be inside the range of int
        if (literal->exprType().isVoid()) {
            Errors.push_back(ErrorMessage("Integer literal must be inside the range of int!", literal->srcLoc()));
            literal->setExprType(Type(Type::PrimitiveTypeEnum::Int));
        } else
            assert(literal->exprType().isInt());
    }

    void VerifyAndBuildSymbols::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        //start your code here
        ASTVisitor::visitBoolLiteralExpr(literal);
        assert(literal->exprType().isBool());
    }

    void VerifyAndBuildSymbols::visitCharLiteralExpr(CharLiteralExpr *literal) {
        //start your code here
        ASTVisitor::visitCharLiteralExpr(literal);
        assert(literal->exprType().isChar());
    }

    //print collected error messages
    std::string VerifyAndBuildSymbols::genErrorMessages() {
        std::stringbuf buf;
        std::ostream os(&buf);

        for (size_t i = 0; i < Errors.size(); i++) {
            os << Errors[i].Msg << " (" << Errors[i].SrcLoc.Line << ":" << Errors[i].SrcLoc.Row << ")\n";
        }

        return buf.str();
    }

}