grammar MiniC;

@header {
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
}
@members{
    void link(ASTNode* parent, ASTNode* child) {
        parent->addChild(child);
        if (child != NULL)
            child->setParent(parent);
    }

    void link(ASTNode* parent, std::vector<ASTNode*> children) {
        for (auto iter = children.begin(); iter != children.end(); iter++)
            link(parent, *iter);
    }

    UnaryExpr* createUnaryExpr(std::string op, Expr *expr) {
        UnaryExpr *node = new UnaryExpr();
        node->setOpcode(Expr::opcodeFromString(op));
        link(node, expr);
        return node;
    }

    BinaryExpr* createBinaryExpr(std::string op, Expr *e1, Expr *e2) {
        BinaryExpr *node = new BinaryExpr();
        node->setOpcode(Expr::opcodeFromString(op));
        link(node, e1);
        link(node, e2);
        return node;
    }
}
/*Add your grammar rules in Assignment 2*/
/*Then add compiler actions in Assignment 3*/
prog returns [minicc::Program *val]
/*You may need init in Assignment 3*/
@init {$val = new Program();}
: preamble decl {
    $val->setSyslibFlag($preamble.flag);
    link($val, $decl.nodes);
    $val->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
;
preamble returns [bool flag]
: '#include' '"minicio.h"' {$flag = true;}
| {$flag = false;}
    ;
decl returns [std::vector<ASTNode*> nodes]
: vardecl {$nodes.insert($nodes.end(), $vardecl.nodes.begin(), $vardecl.nodes.end());}
| rettype funcname '(' parameters ')' scope {
    FuncDeclaration *node = new FuncDeclaration();
    link(node, $rettype.node);
    link(node, $funcname.node);
    link(node, $parameters.nodes);
    link(node, $scope.node);
    node->setHasBody(true);
    node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    $nodes.push_back(node);
}
| rettype funcname '(' parameters ')' ';' {
    FuncDeclaration *node = new FuncDeclaration();
    link(node, $rettype.node);
    link(node, $funcname.node);
    link(node, $parameters.nodes);
    node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    $nodes.push_back(node);
}
| d1=decl d2=decl {
    $nodes.insert($nodes.end(), $d1.nodes.begin(), $d1.nodes.end());
    $nodes.insert($nodes.end(), $d2.nodes.begin(), $d2.nodes.end());
}
    ;
vardecl returns [std::vector<ASTNode*> nodes]
: vartype varlist ';' {
    VarDeclaration *node = new VarDeclaration();
    link(node, $vartype.node);
    link(node, $varlist.nodes);
    node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    $nodes.push_back(node);
}
| vd1=vardecl vd2=vardecl  {
    $nodes.insert($nodes.end(), $vd1.nodes.begin(), $vd1.nodes.end());
    $nodes.insert($nodes.end(), $vd2.nodes.begin(), $vd2.nodes.end());
}
    ;
scope returns [ScopeStatement *node]
/*You may need init in Assignment 3*/
@init {
    $node = new ScopeStatement();
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
: '{' vardecl stmtlist '}' {
    $node->setNumVarDecl($vardecl.nodes.size());
    link($node, $vardecl.nodes);
    link($node, $stmtlist.nodes);
}
| '{' stmtlist '}' {link($node, $stmtlist.nodes);}
| '{' '}'
    ;
stmtlist returns [std::vector<ASTNode*> nodes]
: (stmt {$nodes.push_back($stmt.node);})*
    ;
stmt returns [Statement *node]
: expr ';' {
    $node = new ExprStatement();
    link($node, $expr.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'if' '(' expr ')' s1=stmt 'else' s2=stmt {
    $node = new IfStatement();
    link($node, $expr.node);
    link($node, $s1.node);
    link($node, $s2.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'if' '(' expr ')' stmt {
    $node = new IfStatement();
    link($node, $expr.node);
    link($node, $stmt.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'for' '(' e1=expropt ';' e2=expropt ';' e3=expropt ')' stmt {
    $node = new ForStatement();
    link($node, $e1.node);
    link($node, $e2.node);
    link($node, $e3.node);
    link($node, $stmt.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'continue' ';' {
    $node = new ContinueStatement();
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'break' ';' {
    $node = new BreakStatement();
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'return' ';' {
    $node = new ReturnStatement();
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'return' expr ';' {
    $node = new ReturnStatement();
    link($node, $expr.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| scope {$node = $scope.node;}
    ;
varlist returns [std::vector<ASTNode*> nodes]
: varname {
    VarReference *node = new VarReference();
    link(node, $varname.node);
    node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    $nodes.push_back(node);
}
| varname '[' INT ']' {
    VarReference *node = new VarReference();
    link(node, $varname.node);
    IntLiteralExpr *expr = new IntLiteralExpr(stoi($INT.text));
    expr->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    link(node, expr);
    node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    $nodes.push_back(node);
}
| vl1=varlist ',' vl2=varlist {
    $nodes.insert($nodes.end(), $vl1.nodes.begin(), $vl1.nodes.end());
    $nodes.insert($nodes.end(), $vl2.nodes.begin(), $vl2.nodes.end());
}
    ;
varlistentry
:   
    ;
vartype returns [TypeReference *node]
@after{$node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}
: 'int' {$node = new TypeReference(Type::Int);}
| 'bool' {$node = new TypeReference(Type::Bool);}
| 'char' {$node = new TypeReference(Type::Char);}
    ;
rettype returns [TypeReference *node]
: 'void' {
    $node = new TypeReference(Type::Void);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| vartype {$node = $vartype.node;}
    ;
parameters returns [std::vector<ASTNode*> nodes]
: 
| parameterlist {$nodes = $parameterlist.nodes;}
    ;
parameterlist returns [std::vector<ASTNode*> nodes]
: vartype parametername {
    Parameter *node = new Parameter();
    link(node, $vartype.node);
    link(node, $parametername.node);
    node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    $nodes.push_back(node);
}
| pl1=parameterlist ',' pl2=parameterlist {
    $nodes.insert($nodes.end(), $pl1.nodes.begin(), $pl1.nodes.end());
    $nodes.insert($nodes.end(), $pl2.nodes.begin(), $pl2.nodes.end());
}
    ;
parameterentry
:   
    ;
expropt returns [Expr *node]
: expr {$node = $expr.node;}
| {$node = NULL;}
    ;
expr returns [Expr *node]
: INT {
    $node = new IntLiteralExpr(stoi($INT.text));
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| CHAR {
    $node = new CharLiteralExpr($CHAR.text[1]);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'true' {
    $node = new BoolLiteralExpr(true);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| 'false' {
    $node = new BoolLiteralExpr(false);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| '-' expr {
    $node = createUnaryExpr("-", $expr.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| '!' expr {
    $node = createUnaryExpr("!", $expr.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| e1=expr op=('*' | '/') e2=expr {
    $node = createBinaryExpr($op.text, $e1.node, $e2.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| e1=expr op=('+' | '-') e2=expr {
    $node = createBinaryExpr($op.text, $e1.node, $e2.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| e1=expr op=('==' | '!=' | '<' | '<=' | '>' | '>=') e2=expr {
    $node = createBinaryExpr($op.text, $e1.node, $e2.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| e1=expr '&&' e2=expr {
    $node = createBinaryExpr("&&", $e1.node, $e2.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| e1=expr '||' e2=expr {
    $node = createBinaryExpr("||", $e1.node, $e2.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| var '=' expr {
    $node = new AssignmentExpr();
    link($node, $var.node);
    link($node, $expr.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| '(' expr ')' {$node = $expr.node;}
| var {
    $node = new VarExpr();
    link($node, $var.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| funcname '(' arguments ')' {
    $node = new CallExpr();
    link($node, $funcname.node);
    link($node, $arguments.nodes);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| parametername {
    $node = new VarExpr();
    link($node, $parametername.node);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    ;
var returns [VarReference *node]
@after{$node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}
: varname {
    $node = new VarReference();
    link($node, $varname.node);
}
| arrayname '[' expr ']' {
    $node = new VarReference();
    link($node, $arrayname.node);
    link($node, $expr.node);
}
    ;
arguments returns [std::vector<ASTNode*> nodes]
: argumentlist {$nodes = $argumentlist.nodes;}
|
    ;
argumentlist returns [std::vector<ASTNode*> nodes]
: expr {$nodes.push_back($expr.node);}
| al1=argumentlist ',' al2=argumentlist {
    $nodes.insert($nodes.end(), $al1.nodes.begin(), $al1.nodes.end());
    $nodes.insert($nodes.end(), $al2.nodes.begin(), $al2.nodes.end());
}
    ;
varname returns [Identifier *node]
: ID {
    $node = new Identifier($ID.text);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    ;
arrayname returns [Identifier *node]
: ID {
    $node = new Identifier($ID.text);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    ;
funcname returns [Identifier *node]
: ID {
    $node = new Identifier($ID.text);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    ;
parametername returns [Identifier *node]
: ID {
    $node = new Identifier($ID.text);
    $node->setSrcLoc($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    ;

ID:     [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*) ;
CHAR:   '\''.'\'';
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
