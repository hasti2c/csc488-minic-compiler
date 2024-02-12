//
// Created by Fan Long on 12/2/20.
//
#include <iostream>
#include "antlr4-runtime.h"
#include "grammars/MiniC/MiniCLexer.h"
#include "grammars/MiniC/MiniCParser.h"
#include "GrammarStatVisitor.h"

using namespace minicc;
using namespace antlr4;

void checkASTStatus(const std::string &InputFile) {
    std::ifstream stream;
    stream.open(InputFile);

    ANTLRInputStream input(stream);
    MiniCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MiniCParser parser(&tokens);

    MiniCParser::ProgContext *tree = parser.prog();

    GrammarStatVisitor visitor;
    visitor.visitProg(tree);

    int num_errors = parser.getNumberOfSyntaxErrors();
    std::cout << "Number of Parse Errors: " << num_errors << "\n";
    if (!num_errors) {
        std::cout << "Num Stmt: " << visitor.StmtCnt << "\n";
        std::cout << "Num Expr: " << visitor.ExprCnt << "\n";
        std::cout << "Num Binop: " << visitor.BinopCnt << "\n";
        std::cout << "Num Plus: " << visitor.PlusCnt << "\n";
    }
}