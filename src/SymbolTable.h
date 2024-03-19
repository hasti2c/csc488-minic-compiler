//
// Created by Fan Long on 2020/12/5.
//

#ifndef MINICC_SYMBOLTABLE_H
#define MINICC_SYMBOLTABLE_H

//add more header files if your want
//You may need assert function
#include <cassert>
#include "Types.h"
#include <map>

namespace llvm {
    class Value;
}

namespace minicc {


    struct VarSymbolEntry {
        Type VarType;
        llvm::Value *LLVMValue;

        explicit VarSymbolEntry(Type varType) : VarType(varType), LLVMValue(nullptr) { }
    };

    class VarSymbolTable {

        std::map<std::string, VarSymbolEntry> Table;

    public:
        //define your member variables and functions
        bool contains(const std::string &name) {
            return Table.find(name) != Table.end();
        }

        VarSymbolEntry get(const std::string &name) {
            return Table.at(name);
        }

        void insert(const std::string &name, VarSymbolEntry entry) {
            Table.insert(std::make_pair(name, VarSymbolEntry(entry)));
        }

        void update(const std::string &name, VarSymbolEntry entry) {
            Table.insert_or_assign(name, VarSymbolEntry(entry));
        }

        void updateWithValue(const std::string &name, llvm::Value *value) {
            VarSymbolEntry entry = get(name);
            entry.LLVMValue = value;
            update(name, entry);
        }
    };

    struct FuncSymbolEntry {
        Type ReturnType;
        std::vector<Type> ParameterTypes;
        bool HasBody;

        FuncSymbolEntry(Type retType, const std::vector<Type> &paraTypes, bool hasBody) : ReturnType(retType), ParameterTypes(paraTypes), HasBody(hasBody) { }
    };

    class FuncSymbolTable {
        std::map<std::string, FuncSymbolEntry> Table;
    public:
        //define your member variables and functions
        bool contains(const std::string &name) {
            return Table.find(name) != Table.end();
        }

        FuncSymbolEntry get(const std::string &name) {
            return Table.at(name);
        }

        void insert(const std::string &name, FuncSymbolEntry entry) {
            Table.insert(std::make_pair(name, FuncSymbolEntry(entry)));
        }

        void setHasBody(const std::string &name, bool hasBody) {
            Table.at(name).HasBody = hasBody;
        }
    };
}

#endif //MINICC_SYMBOLTABLE_H
