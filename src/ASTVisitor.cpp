//
// Created by Fan Long on 2020/12/3.
//

#include "ASTVisitor.h"
#include "ASTNode.h"
#include "Program.h"
#include "Declarations.h"
#include "Exprs.h"
#include "Statements.h"
#include "Terms.h"

namespace minicc {
    void ASTVisitor::visitASTNode(ASTNode *node) {
        for (size_t i = 0; i < node->numChildren(); i++) {
            auto child = node->getChild(i);
            if (child)
                child->accept(this);
        }
    }

    void ASTVisitor::visitProgram(Program *prog) {
        this->visitASTNode(prog);
    }

    void ASTVisitor::visitDecl(Declaration *decl) {
        this->visitASTNode(decl);
    }

    void ASTVisitor::visitVarDecl(VarDeclaration *decl) {
        this->visitDecl(decl);
    }

    void ASTVisitor::visitFuncDecl(FuncDeclaration *decl) {
        this->visitDecl(decl);
    }

    void ASTVisitor::visitStmt(Statement *stmt) {
        this->visitASTNode(stmt);
    }

    void ASTVisitor::visitExprStmt(ExprStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitIfStmt(IfStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitForStmt(ForStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitContinueStmt(ContinueStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitReturnStmt(ReturnStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitBreakStmt(BreakStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitScope(ScopeStatement *stmt) {
        this->visitStmt(stmt);
    }

    void ASTVisitor::visitExpr(Expr *expr) {
        this->visitASTNode(expr);
    }

    void ASTVisitor::visitConstantLiteralExpr(ConstantLiteralExpr *expr) {
        this->visitExpr(expr);
    }

    void ASTVisitor::visitUnaryExpr(UnaryExpr *expr) {
        this->visitExpr(expr);
    }

    void ASTVisitor::visitBinaryExpr(BinaryExpr *expr) {
        this->visitExpr(expr);
    }

    void ASTVisitor::visitCallExpr(CallExpr *expr) {
        this->visitExpr(expr);
    }

    void ASTVisitor::visitVarExpr(VarExpr *expr) {
        this->visitExpr(expr);
    }

    void ASTVisitor::visitAssignmentExpr(AssignmentExpr *expr) {
        this->visitExpr(expr);
    }

    void ASTVisitor::visitIntLiteralExpr(IntLiteralExpr *literal) {
        this->visitConstantLiteralExpr(literal);
    }

    void ASTVisitor::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        this->visitConstantLiteralExpr(literal);
    }

    void ASTVisitor::visitCharLiteralExpr(CharLiteralExpr *literal) {
        this->visitConstantLiteralExpr(literal);
    }

    void ASTVisitor::visitVarRef(VarReference *var) {
        this->visitASTNode(var);
    }

    void ASTVisitor::visitIdentifier(Identifier *id) {
        this->visitASTNode(id);
    }

    void ASTVisitor::visitTypeReference(TypeReference *type) {
        this->visitASTNode(type);
    }

    void ASTVisitor::visitParameter(Parameter *para) {
        this->visitASTNode(para);
    }
}