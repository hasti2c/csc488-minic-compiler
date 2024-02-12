//
// Created by Fan Long on 2020/12/4.
//

#include <iostream>
#include "antlr4-runtime.h"
#include "grammars/MiniC/MiniCLexer.h"
#include "grammars/MiniC/MiniCParser.h"

using namespace minicc;
using namespace antlr4;

minicc::Program* buildAST(const std::string &InputFile) {
    std::ifstream stream;
    stream.open(InputFile);

    ANTLRInputStream input(stream);
    MiniCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MiniCParser parser(&tokens);

    MiniCParser::ProgContext *tree = parser.prog();

    int num_errors = parser.getNumberOfSyntaxErrors();
    if (num_errors)
        return nullptr;
    else
        return tree->val;
}