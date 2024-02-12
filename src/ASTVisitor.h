//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_ASTVISITOR_H
#define MINICC_ASTVISITOR_H

namespace minicc {

    class ASTNode;
    class Program;
    class Declaration;
    class VarDeclaration;
    class FuncDeclaration;
    class Statement;
    class ExprStatement;
    class IfStatement;
    class ForStatement;
    class ContinueStatement;
    class ReturnStatement;
    class BreakStatement;
    class ScopeStatement;
    class Expr;
    class ConstantLiteralExpr;
    class UnaryExpr;
    class BinaryExpr;
    class CallExpr;
    class VarExpr;
    class AssignmentExpr;
    class IntLiteralExpr;
    class BoolLiteralExpr;
    class CharLiteralExpr;
    class VarReference;
    class Identifier;
    class TypeReference;
    class Parameter;

    class ASTVisitor {
    public:
        virtual void visitASTNode(ASTNode* node);

        virtual void visitProgram(Program* prog);

        virtual void visitDecl(Declaration* decl);

        virtual void visitVarDecl(VarDeclaration* decl);

        virtual void visitFuncDecl(FuncDeclaration* func);

        virtual void visitStmt(Statement* stmt);

        virtual void visitExprStmt(ExprStatement* stmt);

        virtual void visitIfStmt(IfStatement* stmt);

        virtual void visitForStmt(ForStatement* stmt);

        virtual void visitContinueStmt(ContinueStatement* stmt);

        virtual void visitReturnStmt(ReturnStatement* stmt);

        virtual void visitBreakStmt(BreakStatement* stmt);

        virtual void visitScope(ScopeStatement* stmt);

        virtual void visitExpr(Expr* expr);

        virtual void visitConstantLiteralExpr(ConstantLiteralExpr* expr);

        virtual void visitUnaryExpr(UnaryExpr* expr);

        virtual void visitBinaryExpr(BinaryExpr* expr);

        virtual void visitCallExpr(CallExpr* expr);

        virtual void visitVarExpr(VarExpr* expr);

        virtual void visitAssignmentExpr(AssignmentExpr* expr);

        virtual void visitIntLiteralExpr(IntLiteralExpr* literal);

        virtual void visitBoolLiteralExpr(BoolLiteralExpr* literal);

        virtual void visitCharLiteralExpr(CharLiteralExpr* literal);

        virtual void visitVarRef(VarReference* var);

        virtual void visitIdentifier(Identifier* id);

        virtual void visitTypeReference(TypeReference* type);

        virtual void visitParameter(Parameter *para);
    };

}

#endif //MINICC_ASTVISITOR_H
