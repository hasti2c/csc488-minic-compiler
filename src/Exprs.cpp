//
// Created by Fan Long on 2020/12/3.
//

#include "Exprs.h"
#include <climits>
#include <sstream>

namespace minicc {
    ConstantLiteralExpr *ConstantLiteralExpr::fromString(const std::string &str, bool minus_flag) {
        if (str == "true") {
            return new BoolLiteralExpr(true);
        } else if (str == "false") {
            return new BoolLiteralExpr(false);
        } else if (str.size() == 3 && str[0] == '\'' && str[2] == '\'') {
            char ch = str[1];
            return new CharLiteralExpr(ch);
        } else {
            if (str.size() > 10) {
                ConstantLiteralExpr* expr = new IntLiteralExpr(0);
                // this is to mark invalid literal
                expr->setExprType(Type(Type::Void));
                return expr;
            }
            int64_t res;
            std::istringstream iss(str);
            iss >> res;
            int64_t res_flagged = minus_flag? -res : res;
            if (res_flagged < INT_MIN || res_flagged > INT_MAX) {
                ConstantLiteralExpr* expr = new IntLiteralExpr(0);
                // this is to mark invalid literal
                expr->setExprType(Type(Type::Void));
                return expr;
            }
            return new IntLiteralExpr((int)res);
        }
    }
}
