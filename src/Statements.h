//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_STATEMENTS_H
#define MINICC_STATEMENTS_H

#include "ASTNode.h"

namespace minicc {
    class Statement : public ASTNode {
    protected:
        Statement() : ASTNode() { }
    };

    class ExprStatement: public Statement {
    public:
        ExprStatement() : Statement() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitExprStmt(this);
        }
    };

    class IfStatement : public Statement {
    public:
        IfStatement() : Statement() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitIfStmt(this);
        }

        Expr* condExpr() {
            return (Expr*) getChild(0);
        }

        Statement* thenStmt() {
            return (Statement*) getChild(1);
        }

        bool hasElse() {
            return numChildren() > 2;
        }

        Statement* elseStmt() {
            assert( numChildren() > 2);
            return (Statement*) getChild(2);
        }
    };

    class ContinueStatement : public Statement {
    public:
        ContinueStatement() : Statement() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitContinueStmt(this);
        }
    };
    
    class ForStatement : public Statement {
    public:
        ForStatement() : Statement() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitForStmt(this);
        }

        Expr *initExpr() {
            return (Expr*)getChild(0);
        }

        Expr *condExpr() {
            return (Expr*)getChild(1);
        }

        Expr *iterExpr() {
            return (Expr*)getChild(2);
        }

        Statement *body() {
            return (Statement*)getChild(3);
        }
    };

    class ReturnStatement : public Statement {
    public:
        ReturnStatement() : Statement() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitReturnStmt(this);
        }

        bool hasReturnExpr() {
            return numChildren() > 0;
        }

        Expr *returnExpr() {
            assert( hasReturnExpr());
            return (Expr*)getChild(0);
        }
    };

    class BreakStatement : public Statement {
    public:
        BreakStatement() : Statement() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitBreakStmt(this);
        }
    };

    class ScopeStatement : public Statement {
        size_t NumVarDecl;
    public:
        ScopeStatement() : Statement() {
            this->ScopeVarTable = new VarSymbolTable();
        }

        void setNumVarDecl(size_t num) {
            NumVarDecl = num;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitScope(this);
        }
    };
}

#endif //MINICC_STATEMENTS_H
