
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
 * This interface defines an abstract listener for a parse tree produced by MiniCParser.
 */
class  MiniCListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(MiniCParser::ProgContext *ctx) = 0;
  virtual void exitProg(MiniCParser::ProgContext *ctx) = 0;

  virtual void enterPreamble(MiniCParser::PreambleContext *ctx) = 0;
  virtual void exitPreamble(MiniCParser::PreambleContext *ctx) = 0;

  virtual void enterDecl(MiniCParser::DeclContext *ctx) = 0;
  virtual void exitDecl(MiniCParser::DeclContext *ctx) = 0;

  virtual void enterVardecl(MiniCParser::VardeclContext *ctx) = 0;
  virtual void exitVardecl(MiniCParser::VardeclContext *ctx) = 0;

  virtual void enterScope(MiniCParser::ScopeContext *ctx) = 0;
  virtual void exitScope(MiniCParser::ScopeContext *ctx) = 0;

  virtual void enterStmtlist(MiniCParser::StmtlistContext *ctx) = 0;
  virtual void exitStmtlist(MiniCParser::StmtlistContext *ctx) = 0;

  virtual void enterStmt(MiniCParser::StmtContext *ctx) = 0;
  virtual void exitStmt(MiniCParser::StmtContext *ctx) = 0;

  virtual void enterVarlist(MiniCParser::VarlistContext *ctx) = 0;
  virtual void exitVarlist(MiniCParser::VarlistContext *ctx) = 0;

  virtual void enterVarlistentry(MiniCParser::VarlistentryContext *ctx) = 0;
  virtual void exitVarlistentry(MiniCParser::VarlistentryContext *ctx) = 0;

  virtual void enterVartype(MiniCParser::VartypeContext *ctx) = 0;
  virtual void exitVartype(MiniCParser::VartypeContext *ctx) = 0;

  virtual void enterRettype(MiniCParser::RettypeContext *ctx) = 0;
  virtual void exitRettype(MiniCParser::RettypeContext *ctx) = 0;

  virtual void enterParameters(MiniCParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(MiniCParser::ParametersContext *ctx) = 0;

  virtual void enterParameterlist(MiniCParser::ParameterlistContext *ctx) = 0;
  virtual void exitParameterlist(MiniCParser::ParameterlistContext *ctx) = 0;

  virtual void enterParameterentry(MiniCParser::ParameterentryContext *ctx) = 0;
  virtual void exitParameterentry(MiniCParser::ParameterentryContext *ctx) = 0;

  virtual void enterExpropt(MiniCParser::ExproptContext *ctx) = 0;
  virtual void exitExpropt(MiniCParser::ExproptContext *ctx) = 0;

  virtual void enterExpr(MiniCParser::ExprContext *ctx) = 0;
  virtual void exitExpr(MiniCParser::ExprContext *ctx) = 0;

  virtual void enterVar(MiniCParser::VarContext *ctx) = 0;
  virtual void exitVar(MiniCParser::VarContext *ctx) = 0;

  virtual void enterArguments(MiniCParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(MiniCParser::ArgumentsContext *ctx) = 0;

  virtual void enterArgumentlist(MiniCParser::ArgumentlistContext *ctx) = 0;
  virtual void exitArgumentlist(MiniCParser::ArgumentlistContext *ctx) = 0;

  virtual void enterVarname(MiniCParser::VarnameContext *ctx) = 0;
  virtual void exitVarname(MiniCParser::VarnameContext *ctx) = 0;

  virtual void enterArrayname(MiniCParser::ArraynameContext *ctx) = 0;
  virtual void exitArrayname(MiniCParser::ArraynameContext *ctx) = 0;

  virtual void enterFuncname(MiniCParser::FuncnameContext *ctx) = 0;
  virtual void exitFuncname(MiniCParser::FuncnameContext *ctx) = 0;

  virtual void enterParametername(MiniCParser::ParameternameContext *ctx) = 0;
  virtual void exitParametername(MiniCParser::ParameternameContext *ctx) = 0;


};

}  // namespace minicc
