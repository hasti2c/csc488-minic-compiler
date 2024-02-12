//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_ASTNODE_H
#define MINICC_ASTNODE_H

#include <vector>
#include "ASTVisitor.h"
#include "SymbolTable.h"

namespace minicc {
    class ASTVisitor;
    class Program;

    struct SourceLocation {
        int Line, Row;
        SourceLocation() : Line(0), Row(0) { }
        SourceLocation(unsigned int line, unsigned int row) : Line(line), Row(row) { }
    };

    class ASTNode {
        std::vector<ASTNode*> Children;
        ASTNode* Parent;
        SourceLocation SrcLoc;

        // These fields are filled after the parsing
        Program* Root;
    protected:
        VarSymbolTable *ScopeVarTable;
        ASTNode() : Children(), Parent(nullptr), SrcLoc(), Root(nullptr), ScopeVarTable(nullptr) { }
    public:
        virtual void accept(ASTVisitor *visitor) = 0;

        virtual ~ASTNode() {
            for (size_t i = 0; i < Children.size(); i++)
                delete Children[i];
            if (ScopeVarTable != nullptr)
                delete ScopeVarTable;
        }

        //=======================================
        // AST Construction functions:
        // Should only be invoked during the execution
        // of the ANTLR parser.
        void addChild(ASTNode *child) {
            Children.push_back(child);
            if (child != nullptr)
                child->setParent(this);
        }

        void setParent(ASTNode *parent) {
            Parent = parent;
        }

        void setSrcLoc(int line, int row) {
            SrcLoc = SourceLocation(line, row);
        }
        //=======================================

        void setRoot(Program* program) {
            Root = program;
        }

        Program* root() {
            return Root;
        }

        ASTNode* getParent() const {
            return Parent;
        }

        ASTNode* getParentScope() const {
            ASTNode* now = Parent;
            while (now != nullptr) {
                if (now->isScope())
                    return now;
                now = now->Parent;
            }
            return nullptr;
        }
        //You may need this function in Assigment 4
        FuncDeclaration* getParentFunction() const {
            ASTNode* now = Parent;
            while (now != nullptr) {
                if (now->isFuncDecl())
                    return (FuncDeclaration*)now;
                now = now->Parent;
            }
            return nullptr;
        }
        //You may need this function in Assigment 4
        ForStatement* getParentForStatement() const {
            ASTNode* now = Parent;
            while (now != nullptr) {
                if (now->isForStatement())
                    return (ForStatement*)now;
                if (now->isFuncDecl())
                    break;
                now = now->Parent;
            }
            return nullptr;
        }

        //You may need this function in Assigment 4
        //The function returns variable symbol table which contains variable "name"
        VarSymbolTable *locateDeclaringTableForVar(const std::string &name) {
            //start your code here
            return nullptr;
        }

        ASTNode* getChild(size_t index) const {
            assert(index < Children.size());
            return Children[index];
        }

        size_t numChildren() const {
            return Children.size();
        }

        SourceLocation srcLoc() const {
            return SrcLoc;
        }

        bool isScope();

        //You may need this function in Assigment 4
        VarSymbolTable* scopeVarTable() {
            return ScopeVarTable;
        }

        bool isForStatement();

        bool isContinueStatement();
        
        bool isFuncDecl();

        bool isProgram();

        bool isReturn();
    };
}

#endif //MINICC_ASTNODE_H
