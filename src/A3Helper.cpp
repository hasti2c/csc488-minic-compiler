#include "A3Helper.h"

using namespace minicc;

void link(ASTNode* parent, ASTNode* child) {
    parent->addChild(child);
    if (child != nullptr)
        child->setParent(parent);
}

void link(ASTNode* parent, std::vector<ASTNode*>::iterator start, std::vector<ASTNode*>::iterator end) {
    for (auto iter = start; iter != end; iter++)
        link(parent, *iter);
}

UnaryExpr* createUnaryExpr(std::string op, Expr *expr) {
    UnaryExpr *node = new UnaryExpr();
    node->setOpcode(Expr::opcodeFromString(op));
    link(node, expr);
    return node;
}

BinaryExpr* createBinaryExpr(std::string op, Expr *e1, Expr *e2) {
    BinaryExpr *node = new BinaryExpr();
    node->setOpcode(Expr::opcodeFromString(op));
    link(node, e1);
    link(node, e2);
    return node;
}