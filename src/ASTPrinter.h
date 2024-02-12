//
// Created by Fan Long on 2020/12/4.
//

#ifndef MINICC_ASTPRINTER_H
#define MINICC_ASTPRINTER_H

#include <iostream>
#include "ASTVisitor.h"
#include "Program.h"
#include "Declarations.h"
#include "Exprs.h"
#include "Statements.h"
#include "Terms.h"

namespace minicc {

    class ASTPrinter : public ASTVisitor {
        size_t indent;

        std::string generateIndentString() const {
            if (indent > 2)
                return std::string(indent - 2,' ') + "|-";
            else if (indent == 2)
                return "|-";
            else
                return "";
        }
    public:
        ASTPrinter() : indent(0) { }

        void visitASTNode(ASTNode *node) override {
            std::cout << " (" << node->srcLoc().Line <<", " << node->srcLoc().Row << ")\n";
            indent += 2;
            ASTVisitor::visitASTNode(node);
            indent -= 2;
        }

        void visitProgram(Program *prog) override {
            std::cout << "MiniCProg [syslibFlag=" << prog->syslibFlag() << "]";
            ASTVisitor::visitProgram(prog);
        }

        void visitVarDecl(VarDeclaration *decl) override {
            std::cout << generateIndentString() << "VarDecl" << "";
            ASTVisitor::visitVarDecl(decl);
        }

        void visitFuncDecl(FuncDeclaration *func) override {
            std::cout << generateIndentString() << "FuncDecl [hasBody=" << func->hasBody() << "]";
            ASTVisitor::visitFuncDecl(func);
        }

        void visitExprStmt(ExprStatement *stmt) override {
            std::cout << generateIndentString() << "ExprStmt";
            ASTVisitor::visitExprStmt(stmt);
        }

        void visitIfStmt(IfStatement *stmt) override {
            std::cout << generateIndentString() << "IfStmt";
            ASTVisitor::visitIfStmt(stmt);
        }

        void visitForStmt(ForStatement *stmt) override {
            std::cout << generateIndentString() << "ForStmt";
            ASTVisitor::visitForStmt(stmt);
        }

        void visitContinueStmt(ContinueStatement *stmt) override {
            std::cout << generateIndentString() << "ContinueStmt";
            ASTVisitor::visitContinueStmt(stmt);
        }

        void visitReturnStmt(ReturnStatement *stmt) override {
            std::cout << generateIndentString() << "ReturnStmt";
            ASTVisitor::visitReturnStmt(stmt);
        }

        void visitBreakStmt(BreakStatement *stmt) override {
            std::cout << generateIndentString() << "BreakStmt";
            ASTVisitor::visitBreakStmt(stmt);
        }

        void visitScope(ScopeStatement *stmt) override {
            std::cout << generateIndentString() << "ScopeStatement";
            ASTVisitor::visitScope(stmt);
        }

        void visitUnaryExpr(UnaryExpr *expr) override {
            std::cout << generateIndentString() << "UnaryExpr [opcode='" << Expr::opcodeToString(expr->opcode()) << "']";
            ASTVisitor::visitUnaryExpr(expr);
        }

        void visitBinaryExpr(BinaryExpr *expr) override {
            std::cout << generateIndentString() << "BinaryExpr [opcode='" << Expr::opcodeToString(expr->opcode()) << "']";
            ASTVisitor::visitBinaryExpr(expr);
        }

        void visitCallExpr(CallExpr *expr) override {
            std::cout << generateIndentString() << "CallExpr";
            ASTVisitor::visitCallExpr(expr);
        }

        void visitVarExpr(VarExpr *expr) override {
            std::cout << generateIndentString() << "VarExpr";
            ASTVisitor::visitVarExpr(expr);
        }

        void visitAssignmentExpr(AssignmentExpr *expr) override {
            std::cout << generateIndentString() << "AssignmentExpr";
            ASTVisitor::visitAssignmentExpr(expr);
        }

        void visitIntLiteralExpr(IntLiteralExpr *literal) override {
            std::cout << generateIndentString() << "IntLiteralExpr [val=" << literal->value() << "]";
            ASTVisitor::visitIntLiteralExpr(literal);
        }

        void visitBoolLiteralExpr(BoolLiteralExpr *literal) override {
            std::cout << generateIndentString() << "BoolLiteralExpr [val=" << literal->value() << "]";
            ASTVisitor::visitBoolLiteralExpr(literal);
        }

        void visitCharLiteralExpr(CharLiteralExpr *literal) override {
            std::cout << generateIndentString() << "CharLiteralExpr [val=" << literal->value() << "]";
            ASTVisitor::visitCharLiteralExpr(literal);
        }

        void visitVarRef(VarReference *var) override {
            std::cout << generateIndentString() << "VarRef";
            ASTVisitor::visitVarRef(var);
        }

        void visitIdentifier(Identifier *id) override {
            std::cout << generateIndentString() << "Identifier [name=" << id->name() << "]";
            ASTVisitor::visitIdentifier(id);
        }

        void visitTypeReference(TypeReference *type) override {
            std::cout << generateIndentString() << "TypeReference: [val=" << type->value().toString() << "]";
            ASTVisitor::visitTypeReference(type);
        }

        void visitParameter(Parameter *para) override {
            std::cout << generateIndentString() << "Parameter";
            ASTVisitor::visitParameter(para);
        }
    };

}

#endif //MINICC_ASTPRINTER_H
