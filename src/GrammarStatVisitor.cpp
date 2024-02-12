//
// Created by Fan Long on 12/2/20.
//
#include "GrammarStatVisitor.h"
#include "antlr4-runtime.h"
#include "grammars/MiniC/MiniCLexer.h"
#include "grammars/MiniC/MiniCParser.h"
#include "GrammarStatVisitor.h"

using namespace antlr4;

namespace minicc {
    antlrcpp::Any GrammarStatVisitor::visitExpr(minicc::MiniCParser::ExprContext *exprContext) {
        ExprCnt++;
        if (exprContext->children.size() == 3) {
            auto firstexp = exprContext->children[0];
            auto thirdexp = exprContext->children[2];
            if (firstexp->getText() != "(" && thirdexp->getText() != ")")
                BinopCnt++;
            auto binop = exprContext->children[1];
            if (binop->getText() == "+")
                PlusCnt++;
        }
        return MiniCBaseVisitor::visitExpr(exprContext);
    }

    antlrcpp::Any GrammarStatVisitor::visitStmt(MiniCParser::StmtContext *stmtContext) {
        StmtCnt++;
        return MiniCBaseVisitor::visitStmt(stmtContext);
    }
}