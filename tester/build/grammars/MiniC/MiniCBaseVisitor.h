
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/hasti2c/Documents/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MiniCVisitor.h"


namespace minicc {

/**
 * This class provides an empty implementation of MiniCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MiniCBaseVisitor : public MiniCVisitor {
public:

  virtual std::any visitProg(MiniCParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreamble(MiniCParser::PreambleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(MiniCParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVardecl(MiniCParser::VardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScope(MiniCParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtlist(MiniCParser::StmtlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(MiniCParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarlist(MiniCParser::VarlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarlistentry(MiniCParser::VarlistentryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVartype(MiniCParser::VartypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRettype(MiniCParser::RettypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(MiniCParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterlist(MiniCParser::ParameterlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterentry(MiniCParser::ParameterentryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpropt(MiniCParser::ExproptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(MiniCParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(MiniCParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(MiniCParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentlist(MiniCParser::ArgumentlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarname(MiniCParser::VarnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayname(MiniCParser::ArraynameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncname(MiniCParser::FuncnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParametername(MiniCParser::ParameternameContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace minicc
