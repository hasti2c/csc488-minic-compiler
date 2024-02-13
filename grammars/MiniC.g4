grammar MiniC;

@header {
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
#include "A3Helper.h" // TODO: okay?
}
/*Add your grammar rules in Assignment 2*/
/*Then add compiler actions in Assignment 3*/
prog returns [minicc::Program *val]
/*You may need init in Assignment 3*/
@init {$val = new Program();}
: preamble decl {
    $val->setSyslibFlag($preamble.flag);
    link($val, $decl.nodes.begin(), $decl.nodes.end());
}
;
preamble returns [bool flag]
: '#include' '"minicio.h"' {$flag = true;}
| {$flag = false;}
    ;
decl returns [std::vector<Declaration*> nodes]
: vardecl {$nodes.push_back($vardecl.node);}
| rettype funcname '(' parameters ')' scope {
    FuncDeclaration *node = new FuncDeclaration();
    link(node, $rettype.node);
    link(node, $funcname.node);
    link(node, $parameters.nodes.begin(), $parameters.nodes.end());
    link(node, $scope.node);
    node.setHasBody(true);
    $nodes.push_back(node);
}
| rettype funcname '(' parameters ')' ';' {
    FuncDeclaration *node = new FuncDeclaration();
    link(node, $rettype.node);
    link(node, $funcname.node);
    link(node, $parameters.nodes.begin(), $parameters.nodes.end());
    $nodes.push_back(node);
}
| d1=decl d2=decl {
    $nodes.insert($nodes.end(), d1.begin(), d1.end());
    $nodes.insert($nodes.end(), d2.begin(), d2.end());
}
    ;
vardecl returns [std::vector<VarDeclaration*> nodes]
: vartype varlist ';' {
    VarDeclaration *node = new VarDeclaration();
    link(node, $vartype.node);
    link(node, $varlist.nodes.begin(), $varlist.nodes.end());
    $nodes.push_back(node);
}
| vd1=vardecl vd2=vardecl  {
    $nodes.insert($nodes.end(), vd1.begin(), vd1.end());
    $nodes.insert($nodes.end(), vd2.begin(), vd2.end());
}
    ;
scope returns [ScopeStatement *node]
/*You may need init in Assignment 3*/
@init {$node = new ScopeStatement();}
: '{' vardecl stmtlist '}' {
    $node->setNumVarDecl($vardecl.nodes.size());
    link($node, $vardecl.nodes.begin(), $vardecl.nodes.end());
    link($node, $stmtlist.nodes.begin(), $stmtlist.nodes.end());
}
| '{' stmtlist '}' {link($node, $stmtlist.nodes.begin(), $stmtlist.nodes.end());}
| '{' '}'
    ;
stmtlist returns [std::vector<Statement*> nodes]
: (stmt {$nodes.push_back($stmt.node);})*
    ;
stmt returns [Statement *node]
: expr ';' {$node = $expr.node;}
| 'if' '(' expr ')' s1=stmt 'else' s2=stmt {
    $node = new IfStatement();
    link($node, $expr.node);
    link($node, s1.node);
    link($node, s2.node);
}
| 'if' '(' expr ')' stmt {
    $node = new IfStatement();
    link($node, $expr.node);
    link($node, $stmt.node);
}
| 'for' '(' e1=expropt ';' e2=expropt ';' e3=expropt ')' stmt {
    $node = new ForStatement();
    link($node, e1.node);
    link($node, e2.node);
    link($node, e3.node);
    link($node, $stmt.node);
}
| 'continue' ';' {$node = new ContinueStatement();}
| 'break' ';' {$node = new BreakStatement();}
| 'return' ';' {$node = new ReturnStatement();}
| 'return' expr ';' {
    $node = new ReturnStatement();
    link($node, $expr.node);
}
| scope {$node = $scope.node;}
    ;
varlist returns [std::vector<VarReference*> nodes]
: varname {
    VarReference *node = new VarReference();
    link(node, $varname.node);
    $nodes.push_back(node);
}
| varname '[' INT ']' {
    VarReference *node = new VarReference();
    link(node, $varname.node);
    link(node, stoi($INT.text));
    $nodes.push_back(node);
}
| vl1=varlist ',' vl2=varlist {
    $nodes.insert($nodes.end(), vl1.begin(), vl1.end());
    $nodes.insert($nodes.end(), vl2.begin(), vl2.end());
}
    ;
varlistentry
:   
    ;
vartype returns [TypeReference *node]
: 'int' {$node = new TypeReference(Type::Int);}
| 'bool' {$node = new TypeReference(Type::Bool);}
| 'char' {$node = new TypeReference(Type::Char);}
    ;
rettype returns [TypeReference *node]
: 'void' {$node = new TypeReference(Type::Void);}
| vartype {$node = $vartype.node;}
    ;
parameters returns [std::vector<Parameter*> nodes]
: 
| parameterlist {$nodes = $parameterlist.nodes;}
    ;
parameterlist returns [std::vector<Parameter*> nodes]
: vartype parametername {
    Parameter *node = new Parameter();
    link(node, $vartype.node);
    link(node, $parametername.node);
    $nodes.push_back(node);
}
| pl1=parameterlist ',' pl2=parameterlist {
    $nodes.insert($nodes.end(), pl1.begin(), pl1.end());
    $nodes.insert($nodes.end(), pl2.begin(), pl2.end());
}
    ;
parameterentry
:   
    ;
expropt returns [Expr *node]
: expr {$node = $expr.node;}
| 
    ;
expr returns [Expr *node]
: INT {$node = IntLiteralExpr(stoi($INT.text));}
| CHAR {$node = CharLiteralExpr($CHAR.text[1]);}
| 'true' {$node = BoolLiteralExpr(true);}
| 'false' {$node = BoolLiteralExpr(false);}
| '-' expr {$node = createUnaryExpr("-", $expr);}
| '!' expr {$node = createUnaryExpr("!", $expr);}
| e1=expr op=('*' | '/') e2=expr {$node = createBinaryExpr(op, e1, e2);}
| e1=expr op=('+' | '-') e2=expr {$node = createBinaryExpr(op, e1, e2);}
| e1=expr op=('==' | '!=' | '<' | '<=' | '>' | '>=') e2=expr {$node = createBinaryExpr(op, e1, e2);}
| e1=expr '&&' e2=expr {$node = createBinaryExpr("&&", e1, e2);}
| e1=expr '||' e2=expr {$node = createBinaryExpr("||", e1, e2);}
| var '=' expr {
    $node = new AssignmentExpr();
    link($node, $var.node);
    link($node, $expr.node);
}
| '(' expr ')' {$node = $expr.node;}
| var {
    $node = new VarExpr();
    link($node, $var.node);
}
| funcname '(' arguments ')' {
    $node = new CallExpr();
    link($node, $funcname.node);
    link($node, $arguments.nodes.begin(), $arguments.nodes.end());
}
| parametername {
    $node = new VarExpr();
    link($node, $parametername.node);
}
    ;
var returns [VarReference *node]
: varname {
    $node = new VarReference();
    link($node, $varname.node);
}
| arrayname '[' expr ']' {
    $node = new VarReference();
    link($node, $varname.node);
    link($node, $expr.node);
}
    ;
arguments returns [std::vector<Expr*> nodes]
: argumentlist {$nodes = $argumentlist.nodes;}
|
    ;
argumentlist [std::vector<Expr*> nodes]
: expr {$nodes.push_back($expr.node);}
| al1=argumentlist ',' al2=argumentlist {
    $nodes.insert($nodes.end(), al1.nodes.begin(), al1.nodes.end());
    $nodes.insert($nodes.end(), al2.nodes.begin(), al2.nodes.end());
}
    ;
varname returns [Identifier *node]
: ID {$node = new Identifier($ID.text);}
    ;
arrayname
: ID {$node = new Identifier($ID.text);}
    ;
funcname
: ID {$node = new Identifier($ID.text);}
    ;
parametername
: ID {$node = new Identifier($ID.text);}
    ;

ID:     [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*) ;
CHAR:   '\''.'\'';
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
