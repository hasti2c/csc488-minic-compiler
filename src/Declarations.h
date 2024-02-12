//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_DECLARATIONS_H
#define MINICC_DECLARATIONS_H

#include "ASTNode.h"
#include "Terms.h"
#include "Types.h"

namespace minicc {
    class Declaration : public ASTNode {
    protected:
        Declaration() : ASTNode() { }
    };

    class VarDeclaration : public Declaration {
    public:
        VarDeclaration() : Declaration() { }

        void accept(ASTVisitor *visitor) override {
            visitor->visitVarDecl(this);
        }

        Type::PrimitiveTypeEnum declType() {
            auto t = (TypeReference*)getChild(0);
            return t->value().primitiveType();
        }

        size_t numVarReferences() const {
            return numChildren() - 1;
        }

        VarReference *varReference(size_t i) const {
            assert( i < numChildren() - 1);
            return (VarReference*)getChild(i + 1);
        }
    };

    class FuncDeclaration : public Declaration {

        bool HasBody;

    public:
        FuncDeclaration() : Declaration(), HasBody(false) { }

        void setHasBody(bool flag) {
            HasBody = flag;
        }

        bool hasBody() const {
            return HasBody;
        }

        ScopeStatement* body() {
            assert(HasBody);
            return (ScopeStatement*)getChild(numChildren() - 1);
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitFuncDecl(this);
        }

        Type returnType() {
            auto ref = (TypeReference*) getChild(0);
            return ref->value();
        }

        std::string name() {
            auto id = (Identifier*) getChild(1);
            return id->name();
        }

        size_t numParameters() {
            size_t n = numChildren();
            if (HasBody) {
                return n - 3;
            } else
                return n - 2;
        }

        Parameter* parameter(size_t i) {
            assert (i + 2 < numChildren());
            auto para = (Parameter*)getChild(i + 2);
            return para;
        }
    };
}

#endif //MINICC_DECLARATIONS_H
