//
// Created by Fan Long on 12/2/20.
//

#ifndef MINICC_GRAMMARSTATVISITOR_H
#define MINICC_GRAMMARSTATVISITOR_H

#include "grammars/MiniC/MiniCBaseVisitor.h"

namespace minicc {
    class GrammarStatVisitor : public MiniCBaseVisitor {
    public:
        int StmtCnt;
        int ExprCnt;
        int BinopCnt;
        int PlusCnt;

        GrammarStatVisitor() : StmtCnt(0), ExprCnt(0), BinopCnt(0), PlusCnt(0) { }

        antlrcpp::Any visitStmt(MiniCParser::StmtContext *stmtContext) override;

        antlrcpp::Any visitExpr(MiniCParser::ExprContext *exprContext) override;
    };
}
#endif //MINICC_GRAMMARSTATVISITOR_H