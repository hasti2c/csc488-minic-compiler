
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/hasti2c/Documents/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MiniCListener.h"


namespace minicc {

/**
 * This class provides an empty implementation of MiniCListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MiniCBaseListener : public MiniCListener {
public:

  virtual void enterProg(MiniCParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(MiniCParser::ProgContext * /*ctx*/) override { }

  virtual void enterPreamble(MiniCParser::PreambleContext * /*ctx*/) override { }
  virtual void exitPreamble(MiniCParser::PreambleContext * /*ctx*/) override { }

  virtual void enterDecl(MiniCParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(MiniCParser::DeclContext * /*ctx*/) override { }

  virtual void enterVardecl(MiniCParser::VardeclContext * /*ctx*/) override { }
  virtual void exitVardecl(MiniCParser::VardeclContext * /*ctx*/) override { }

  virtual void enterScope(MiniCParser::ScopeContext * /*ctx*/) override { }
  virtual void exitScope(MiniCParser::ScopeContext * /*ctx*/) override { }

  virtual void enterStmtlist(MiniCParser::StmtlistContext * /*ctx*/) override { }
  virtual void exitStmtlist(MiniCParser::StmtlistContext * /*ctx*/) override { }

  virtual void enterStmt(MiniCParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(MiniCParser::StmtContext * /*ctx*/) override { }

  virtual void enterVarlist(MiniCParser::VarlistContext * /*ctx*/) override { }
  virtual void exitVarlist(MiniCParser::VarlistContext * /*ctx*/) override { }

  virtual void enterVarlistentry(MiniCParser::VarlistentryContext * /*ctx*/) override { }
  virtual void exitVarlistentry(MiniCParser::VarlistentryContext * /*ctx*/) override { }

  virtual void enterVartype(MiniCParser::VartypeContext * /*ctx*/) override { }
  virtual void exitVartype(MiniCParser::VartypeContext * /*ctx*/) override { }

  virtual void enterRettype(MiniCParser::RettypeContext * /*ctx*/) override { }
  virtual void exitRettype(MiniCParser::RettypeContext * /*ctx*/) override { }

  virtual void enterParameters(MiniCParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(MiniCParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParameterlist(MiniCParser::ParameterlistContext * /*ctx*/) override { }
  virtual void exitParameterlist(MiniCParser::ParameterlistContext * /*ctx*/) override { }

  virtual void enterParameterentry(MiniCParser::ParameterentryContext * /*ctx*/) override { }
  virtual void exitParameterentry(MiniCParser::ParameterentryContext * /*ctx*/) override { }

  virtual void enterExpropt(MiniCParser::ExproptContext * /*ctx*/) override { }
  virtual void exitExpropt(MiniCParser::ExproptContext * /*ctx*/) override { }

  virtual void enterExpr(MiniCParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(MiniCParser::ExprContext * /*ctx*/) override { }

  virtual void enterVar(MiniCParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(MiniCParser::VarContext * /*ctx*/) override { }

  virtual void enterArguments(MiniCParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(MiniCParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArgumentlist(MiniCParser::ArgumentlistContext * /*ctx*/) override { }
  virtual void exitArgumentlist(MiniCParser::ArgumentlistContext * /*ctx*/) override { }

  virtual void enterVarname(MiniCParser::VarnameContext * /*ctx*/) override { }
  virtual void exitVarname(MiniCParser::VarnameContext * /*ctx*/) override { }

  virtual void enterArrayname(MiniCParser::ArraynameContext * /*ctx*/) override { }
  virtual void exitArrayname(MiniCParser::ArraynameContext * /*ctx*/) override { }

  virtual void enterFuncname(MiniCParser::FuncnameContext * /*ctx*/) override { }
  virtual void exitFuncname(MiniCParser::FuncnameContext * /*ctx*/) override { }

  virtual void enterParametername(MiniCParser::ParameternameContext * /*ctx*/) override { }
  virtual void exitParametername(MiniCParser::ParameternameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace minicc
