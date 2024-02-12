//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_EXPRS_H
#define MINICC_EXPRS_H

#include "ASTNode.h"
#include <string>
#include "Types.h"

namespace minicc {
    class Expr : public ASTNode {
        Type ExprType;
    protected:
        Expr() : ASTNode() { }
    public:
        enum ExprOpcode {
            Add = 0,
            Sub,
            Mul,
            Div,
            Equal,
            NotEqual,
            Less,
            LessEqual,
            Greater,
            GreaterEqual,
            Not,
            And,
            Or,
            Invalid = -1,
        };

        static ExprOpcode opcodeFromString(const std::string &str) {
            if (str == "+")
                return Add;
            else if (str == "-")
                return Sub;
            else if (str == "*")
                return Mul;
            else if (str == "/")
                return Div;
            else if (str == "==")
                return Equal;
            else if (str == "!=")
                return NotEqual;
            else if (str == "<")
                return Less;
            else if (str == "<=")
                return LessEqual;
            else if (str == ">")
                return Greater;
            else if (str == ">=")
                return GreaterEqual;
            else if (str == "!")
                return Not;
            else if (str == "&&")
                return And;
            else if (str == "||")
                return Or;
            else
                return Invalid;
        }

        static std::string opcodeToString(ExprOpcode op) {
            switch (op) {
                case Add:
                    return "+";
                case Sub:
                    return "-";
                case Mul:
                    return "*";
                case Div:
                    return "/";
                case Equal:
                    return "==";
                case NotEqual:
                    return "!=";
                case Less:
                    return "<";
                case LessEqual:
                    return "<=";
                case Greater:
                    return ">";
                case GreaterEqual:
                    return ">=";
                case Not:
                    return "!";
                case And:
                    return "&&";
                case Or:
                    return "||";
                default:
                    return "";
            }
        }

        Type exprType() {
            return ExprType;
        }

        void setExprType(Type type) {
            ExprType = type;
        }
    };

    class ConstantLiteralExpr : public Expr {
    public:
        ConstantLiteralExpr() : Expr() { }

        static ConstantLiteralExpr* fromString(const std::string &str, bool minus_flag=false);

        void accept(ASTVisitor *visitor) override {
            visitor->visitConstantLiteralExpr(this);
        }
    };

    class IntLiteralExpr : public ConstantLiteralExpr {
        int Value;
    public:
        explicit IntLiteralExpr(int val) : ConstantLiteralExpr(), Value(val) {
            setExprType(Type(Type::Int));
        }

        int value() const {
            return Value;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitIntLiteralExpr(this);
        }
    };

    class BoolLiteralExpr : public ConstantLiteralExpr {
        bool Value;
    public:
        explicit BoolLiteralExpr(bool val) : ConstantLiteralExpr(), Value(val) {
            setExprType(Type(Type::Bool));
        }

        bool value() const {
            return Value;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitBoolLiteralExpr(this);
        }
    };

    class CharLiteralExpr : public ConstantLiteralExpr {
        char Value;
    public:
        explicit CharLiteralExpr(char val) : ConstantLiteralExpr(), Value(val) {
            setExprType(Type(Type::Char));
        }

        char value() const {
            return Value;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitCharLiteralExpr(this);
        }
    };

    class UnaryExpr : public Expr {
        ExprOpcode Opcode;
    public:
        UnaryExpr() : Expr(), Opcode() { }

        void setOpcode(ExprOpcode opcode) {
            Opcode = opcode;
        }

        ExprOpcode opcode() const {
            return Opcode;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitUnaryExpr(this);
        }
    };

    class BinaryExpr : public Expr {
        ExprOpcode Opcode;
    public:
        BinaryExpr() : Expr(), Opcode() { }

        void setOpcode(ExprOpcode opcode) {
            Opcode = opcode;
        }

        ExprOpcode opcode() const {
            return Opcode;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitBinaryExpr(this);
        }
    };

    class CallExpr : public Expr {
    public:
        CallExpr() : Expr() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitCallExpr(this);
        }

        Identifier* callee() {
            return (Identifier*) getChild(0);
        }

        size_t numArgs() {
            assert( numChildren() > 0);
            return numChildren() - 1;
        }

        Expr *arg(size_t i) {
            assert ( i + 1 < numChildren());
            return (Expr*)getChild(i + 1);
        }
    };

    class VarExpr: public Expr {
    public:
        VarExpr() : Expr() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitVarExpr(this);
        }
    };

    class AssignmentExpr: public Expr {
    public:
        AssignmentExpr() : Expr() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitAssignmentExpr(this);
        }
    };
}

#endif //MINICC_EXPRS_H
