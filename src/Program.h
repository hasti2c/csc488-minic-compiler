//
// Created by Fan Long on 2020/12/3.
//

#ifndef MINICC_PROGRAM_H
#define MINICC_PROGRAM_H

#include "ASTNode.h"
#include "SymbolTable.h"
#include <vector>

namespace minicc {
    class Program : public ASTNode {
        bool SyslibFlag;
        FuncSymbolTable* ProgramFuncTable;
    public:
        Program() : ASTNode(), SyslibFlag(false) {
            this->ScopeVarTable = new VarSymbolTable();
            this->ProgramFuncTable = new FuncSymbolTable();
        }

        ~Program() override {
            if (ProgramFuncTable != nullptr)
                delete ProgramFuncTable;
        }

        void accept(ASTVisitor *visitor) override {
            visitor->visitProgram(this);
        }

        void setSyslibFlag(bool flag) {
            SyslibFlag = flag;
        }

        bool syslibFlag() {
            return SyslibFlag;
        }

        FuncSymbolTable* funcTable() {
            return ProgramFuncTable;
        }
    };
}

#endif //MINICC_PROGRAM_H
