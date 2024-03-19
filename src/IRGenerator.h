//
// Created by Fan Long on 2020/12/6.
//

#ifndef MINICC_IRGENERATOR_H
#define MINICC_IRGENERATOR_H

//add more header files if your want
#include "ASTVisitor.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "Program.h"

namespace minicc {

    class IRGenerator : public ASTVisitor {
        std::unique_ptr<llvm::LLVMContext> TheContext;
        std::unique_ptr<llvm::Module> TheModule;
        std::unique_ptr<llvm::IRBuilder<>> TheBuilder;
        std::string ModuleName;

        //add your variables and member functions
        std::map<Expr*, llvm::Value*> ExprValues;
        std::map<ForStatement*, llvm::BasicBlock*> ForStmtStepBBs;
        std::map<ForStatement*, llvm::BasicBlock*> ForStmtExitBBs;

        llvm::Type *toLLVMType(Type type);

        llvm::Value *declareVar(Type type, std::string name, bool global);

        llvm::Function *declareFunc(Type retType, std::vector<Type> paramTypes, std::string name);

        llvm::Value *getGEP(std::string name, VarSymbolTable *table, llvm::ConstantInt *index);

        void visitThisNode(ASTNode *node);

    public:
        //modify if needed
        explicit IRGenerator(const std::string moduleName) : ASTVisitor(), TheModule(), TheBuilder(), ModuleName(moduleName){
            TheContext = std::make_unique<llvm::LLVMContext>();
        }

        std::unique_ptr<llvm::Module> getModule() {
            TheBuilder.reset();
            return std::move(TheModule);
        }

        void visitProgram(Program* prog) override;

        void visitVarDecl(VarDeclaration *decl) override;

        void visitFuncDecl(FuncDeclaration *func) override;

        void visitIfStmt(IfStatement *stmt) override;

        void visitForStmt(ForStatement *stmt) override;

        void visitContinueStmt(ContinueStatement *stmt) override;

        void visitReturnStmt(ReturnStatement *stmt) override;

        void visitBreakStmt(BreakStatement *stmt) override;

        void visitScope(ScopeStatement *stmt) override;

        void visitUnaryExpr(UnaryExpr *expr) override;

        void visitBinaryExpr(BinaryExpr *expr) override;

        void visitCallExpr(CallExpr *expr) override;

        void visitVarExpr(VarExpr *expr) override;

        void visitAssignmentExpr(AssignmentExpr *expr) override;

        void visitIntLiteralExpr(IntLiteralExpr *literal) override;

        void visitBoolLiteralExpr(BoolLiteralExpr *literal) override;

        void visitCharLiteralExpr(CharLiteralExpr *literal) override;
    };
}

#endif //MINICC_IRGENERATOR_H
