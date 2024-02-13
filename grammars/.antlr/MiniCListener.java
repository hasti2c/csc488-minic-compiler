// Generated from /Users/hasti/Documents/UofT/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.13.1

#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MiniCParser}.
 */
public interface MiniCListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MiniCParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(MiniCParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(MiniCParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#preamble}.
	 * @param ctx the parse tree
	 */
	void enterPreamble(MiniCParser.PreambleContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#preamble}.
	 * @param ctx the parse tree
	 */
	void exitPreamble(MiniCParser.PreambleContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#decl}.
	 * @param ctx the parse tree
	 */
	void enterDecl(MiniCParser.DeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#decl}.
	 * @param ctx the parse tree
	 */
	void exitDecl(MiniCParser.DeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#vardecl}.
	 * @param ctx the parse tree
	 */
	void enterVardecl(MiniCParser.VardeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#vardecl}.
	 * @param ctx the parse tree
	 */
	void exitVardecl(MiniCParser.VardeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#scope}.
	 * @param ctx the parse tree
	 */
	void enterScope(MiniCParser.ScopeContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#scope}.
	 * @param ctx the parse tree
	 */
	void exitScope(MiniCParser.ScopeContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#stmtlist}.
	 * @param ctx the parse tree
	 */
	void enterStmtlist(MiniCParser.StmtlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#stmtlist}.
	 * @param ctx the parse tree
	 */
	void exitStmtlist(MiniCParser.StmtlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(MiniCParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(MiniCParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#varlist}.
	 * @param ctx the parse tree
	 */
	void enterVarlist(MiniCParser.VarlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#varlist}.
	 * @param ctx the parse tree
	 */
	void exitVarlist(MiniCParser.VarlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#varlistentry}.
	 * @param ctx the parse tree
	 */
	void enterVarlistentry(MiniCParser.VarlistentryContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#varlistentry}.
	 * @param ctx the parse tree
	 */
	void exitVarlistentry(MiniCParser.VarlistentryContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#vartype}.
	 * @param ctx the parse tree
	 */
	void enterVartype(MiniCParser.VartypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#vartype}.
	 * @param ctx the parse tree
	 */
	void exitVartype(MiniCParser.VartypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#rettype}.
	 * @param ctx the parse tree
	 */
	void enterRettype(MiniCParser.RettypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#rettype}.
	 * @param ctx the parse tree
	 */
	void exitRettype(MiniCParser.RettypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#parameters}.
	 * @param ctx the parse tree
	 */
	void enterParameters(MiniCParser.ParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#parameters}.
	 * @param ctx the parse tree
	 */
	void exitParameters(MiniCParser.ParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#parameterlist}.
	 * @param ctx the parse tree
	 */
	void enterParameterlist(MiniCParser.ParameterlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#parameterlist}.
	 * @param ctx the parse tree
	 */
	void exitParameterlist(MiniCParser.ParameterlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#parameterentry}.
	 * @param ctx the parse tree
	 */
	void enterParameterentry(MiniCParser.ParameterentryContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#parameterentry}.
	 * @param ctx the parse tree
	 */
	void exitParameterentry(MiniCParser.ParameterentryContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#expropt}.
	 * @param ctx the parse tree
	 */
	void enterExpropt(MiniCParser.ExproptContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#expropt}.
	 * @param ctx the parse tree
	 */
	void exitExpropt(MiniCParser.ExproptContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(MiniCParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(MiniCParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#var}.
	 * @param ctx the parse tree
	 */
	void enterVar(MiniCParser.VarContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#var}.
	 * @param ctx the parse tree
	 */
	void exitVar(MiniCParser.VarContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(MiniCParser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(MiniCParser.ArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#argumentlist}.
	 * @param ctx the parse tree
	 */
	void enterArgumentlist(MiniCParser.ArgumentlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#argumentlist}.
	 * @param ctx the parse tree
	 */
	void exitArgumentlist(MiniCParser.ArgumentlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#varname}.
	 * @param ctx the parse tree
	 */
	void enterVarname(MiniCParser.VarnameContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#varname}.
	 * @param ctx the parse tree
	 */
	void exitVarname(MiniCParser.VarnameContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#arrayname}.
	 * @param ctx the parse tree
	 */
	void enterArrayname(MiniCParser.ArraynameContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#arrayname}.
	 * @param ctx the parse tree
	 */
	void exitArrayname(MiniCParser.ArraynameContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#funcname}.
	 * @param ctx the parse tree
	 */
	void enterFuncname(MiniCParser.FuncnameContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#funcname}.
	 * @param ctx the parse tree
	 */
	void exitFuncname(MiniCParser.FuncnameContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#parametername}.
	 * @param ctx the parse tree
	 */
	void enterParametername(MiniCParser.ParameternameContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#parametername}.
	 * @param ctx the parse tree
	 */
	void exitParametername(MiniCParser.ParameternameContext ctx);
}