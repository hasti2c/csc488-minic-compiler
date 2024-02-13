#include <vector>
#include "ASTNode.h"
#include "Exprs.h"

using namespace minicc;

void link(ASTNode* parent, ASTNode* child);
void link(ASTNode* parent, std::vector<ASTNode*>::iterator start, std::vector<ASTNode*>::iterator end);

UnaryExpr* createUnaryExpr(char op, Expr *expr);
BinaryExpr* createBinaryExpr(std::string op, Expr *e1, Expr *e2);