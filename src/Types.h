//
// Created by Fan Long on 2020/12/4.
//

#ifndef MINICC_TYPES_H
#define MINICC_TYPES_H
#include <string>

namespace minicc {

    class Type {
    public:
        enum PrimitiveTypeEnum {
            Void = 0,
            Int,
            Bool,
            Char
        };
    private:
        PrimitiveTypeEnum PrimitiveType;
        // Zero means it is not an array
        size_t ArrayBound;
    public:

        Type() : PrimitiveType(Void), ArrayBound(0) { }

        explicit Type(PrimitiveTypeEnum value) : PrimitiveType(value), ArrayBound(0) { }

        Type(PrimitiveTypeEnum value, size_t arrayBound) : PrimitiveType(value), ArrayBound(arrayBound) { }

        static std::string typeToString(PrimitiveTypeEnum t) {
            switch (t) {
                case Void:
                    return "void";
                case Int:
                    return "int";
                case Bool:
                    return "bool";
                case Char:
                    return "char";
            }
        }

        bool operator== (const Type &a) const {
            if (ArrayBound != a.ArrayBound)
                return false;
            else
                return PrimitiveType == a.PrimitiveType;
        }

        bool operator!= (const Type &a) const {
            return !(*this == a);
        }

        PrimitiveTypeEnum primitiveType() const {
            return PrimitiveType;
        }

        size_t arrayBound() const {
            return ArrayBound;
        }

        void setIsArray(size_t arrayBound) {
            ArrayBound = arrayBound;
        }

        std::string toString() {
            if (ArrayBound)
                return typeToString(PrimitiveType) + "[" + std::to_string(ArrayBound) + "]";
            else
                return typeToString(PrimitiveType);
        }

        bool isBool() const {
            return (ArrayBound == 0) && (PrimitiveType == Type::Bool);
        }

        bool isVoid() {
            return (ArrayBound == 0) && (PrimitiveType == Type::Void);
        }

        bool isInt() {
            return (ArrayBound == 0) && (PrimitiveType == Type::Int);
        }

        bool isChar() {
            return (ArrayBound == 0) && (PrimitiveType == Type::Char);
        }

        Type getIndexedType() {
            return Type(PrimitiveType);
        }
    };
}
#endif //MINICC_TYPES_H
