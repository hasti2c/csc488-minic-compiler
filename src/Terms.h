//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_TERMS_H
#define MINICC_TERMS_H

#include "ASTNode.h"
#include "Types.h"

namespace minicc {
    class Identifier;

    class VarReference : public ASTNode {
    public:
        VarReference() : ASTNode() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitVarRef(this);
        }

        Identifier* identifier() const {
            return (Identifier*)getChild(0);
        }

        bool isArray() const {
            return numChildren() > 1;
        }


        Expr* indexExpr() {
            assert( numChildren() == 2 );
            return (Expr*)getChild(1);
        }
    };

    class Identifier : public ASTNode {
        std::string Name;
    public:
        explicit Identifier(const std::string &name) : ASTNode(), Name(name) { }

        std::string name() const {
            return Name;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitIdentifier(this);
        }
    };

    class TypeReference : public ASTNode {
        Type Value;
    public:
        explicit TypeReference(Type::PrimitiveTypeEnum value) : ASTNode(), Value(value) { }

        Type value() const {
            return Value;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitTypeReference(this);
        }
    };

    class Parameter : public ASTNode {
    public:
        Parameter() : ASTNode() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitParameter(this);
        }

        Type type() {
            auto ref = (TypeReference*)getChild(0);
            return ref->value();
        }

        std::string name() {
            auto id = (Identifier*)getChild(1);
            return id->name();
        }
    };
}
#endif //MINICC_TERMS_H
