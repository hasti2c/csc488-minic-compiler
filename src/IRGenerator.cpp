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

    void IRGenerator::visitProgram(Program *prog) {
        //Initlize llvm module and builder
        TheModule = std::make_unique<llvm::Module>(ModuleName, *TheContext);
        TheBuilder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
        //start your code here
    }

    void IRGenerator::visitVarDecl(VarDeclaration *decl) {
        //start your code here
    }

    void IRGenerator::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
    }

    void IRGenerator::visitIfStmt(IfStatement *stmt) {
        //start your code here
    }

    void IRGenerator::visitForStmt(ForStatement *stmt) {
        //start your code here
    }

    void IRGenerator::visitContinueStmt(ContinueStatement *stmt) {
        //start your code here
    }

    void IRGenerator::visitReturnStmt(ReturnStatement *stmt) {
        //start your code here
    }

    void IRGenerator::visitBreakStmt(BreakStatement *stmt) {
        //start your code here
    }


    void IRGenerator::visitUnaryExpr(UnaryExpr *expr) {
        //start your code here
    }

    void IRGenerator::visitBinaryExpr(BinaryExpr *expr) {
        //start your code here
    }

    void IRGenerator::visitCallExpr(CallExpr *expr) {
        //start your code here
    }

    void IRGenerator::visitVarExpr(VarExpr *expr) {
        //start your code here
    }

    void IRGenerator::visitAssignmentExpr(AssignmentExpr *expr) {
        //start your code here
    }

    void IRGenerator::visitIntLiteralExpr(IntLiteralExpr *literal) {
        //start your code here
    }

    void IRGenerator::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        //start your code here
    }

    void IRGenerator::visitCharLiteralExpr(CharLiteralExpr *literal) {
        //start your code here
    }

    void IRGenerator::visitScope(ScopeStatement *stmt) {
        //start your code here
    }

}