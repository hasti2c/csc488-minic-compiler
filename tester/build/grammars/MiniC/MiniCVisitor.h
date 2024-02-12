
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/hasti2c/Documents/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MiniCParser.h"


namespace minicc {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MiniCParser.
 */
class  MiniCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MiniCParser.
   */
    virtual std::any visitProg(MiniCParser::ProgContext *context) = 0;

    virtual std::any visitPreamble(MiniCParser::PreambleContext *context) = 0;

    virtual std::any visitDecl(MiniCParser::DeclContext *context) = 0;

    virtual std::any visitVardecl(MiniCParser::VardeclContext *context) = 0;

    virtual std::any visitScope(MiniCParser::ScopeContext *context) = 0;

    virtual std::any visitStmtlist(MiniCParser::StmtlistContext *context) = 0;

    virtual std::any visitStmt(MiniCParser::StmtContext *context) = 0;

    virtual std::any visitVarlist(MiniCParser::VarlistContext *context) = 0;

    virtual std::any visitVarlistentry(MiniCParser::VarlistentryContext *context) = 0;

    virtual std::any visitVartype(MiniCParser::VartypeContext *context) = 0;

    virtual std::any visitRettype(MiniCParser::RettypeContext *context) = 0;

    virtual std::any visitParameters(MiniCParser::ParametersContext *context) = 0;

    virtual std::any visitParameterlist(MiniCParser::ParameterlistContext *context) = 0;

    virtual std::any visitParameterentry(MiniCParser::ParameterentryContext *context) = 0;

    virtual std::any visitExpropt(MiniCParser::ExproptContext *context) = 0;

    virtual std::any visitExpr(MiniCParser::ExprContext *context) = 0;

    virtual std::any visitVar(MiniCParser::VarContext *context) = 0;

    virtual std::any visitArguments(MiniCParser::ArgumentsContext *context) = 0;

    virtual std::any visitArgumentlist(MiniCParser::ArgumentlistContext *context) = 0;

    virtual std::any visitVarname(MiniCParser::VarnameContext *context) = 0;

    virtual std::any visitArrayname(MiniCParser::ArraynameContext *context) = 0;

    virtual std::any visitFuncname(MiniCParser::FuncnameContext *context) = 0;

    virtual std::any visitParametername(MiniCParser::ParameternameContext *context) = 0;


};

}  // namespace minicc
