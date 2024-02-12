grammar MiniC;

@header {
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
}
/*Add your grammar rules in Assignment 2*/
/*Then add compiler actions in Assignment 3*/
prog returns [minicc::Program *val]
/*You may need init in Assignment 3*/
@init {}
: preamble decl	
;
preamble
: '#include' '"minicio.h"' 
| 
    ;
decl
: vardecl
| rettype funcname '(' parameters ')' scope
| rettype funcname '(' parameters ')' ';'
| decl decl
    ;
vardecl
: vartype varlist ';'
| vardecl vardecl 
    ;
scope
/*You may need init in Assignment 3*/
@init {}
: '{' vardecl stmtlist '}'
| '{' stmtlist '}'
| '{' '}'
    ;
stmtlist
: stmt*
    ;
stmt
: expr ';'
| 'if' '(' expr ')' stmt 'else' stmt
| 'if' '(' expr ')' stmt
| 'for' '(' expropt ';' expropt ';' expropt ')' stmt
| 'continue;'
| 'break' ';'
| 'return' ';'
| 'return' expr ';'
| scope
    ;
varlist
: varname
| varname '[' INT ']'
| varlist ',' varlist
    ;
varlistentry
:   
    ;
vartype
: 'int'
| 'bool'
| 'char' 
    ;
rettype
: 'void'
| vartype
    ;
parameters
: 
| parameterlist
    ;
parameterlist
: vartype parametername
| parameterlist ',' parameterlist  
    ;
parameterentry
:   
    ;
expropt
: expr
| 
    ;
expr
: INT
| CHAR
| 'true'
| 'false'
| '-' expr
| '!' expr
| expr ('*' | '/') expr
| expr ('+' | '-') expr
| expr ('==' | '!=' | '<' | '<=' | '>' | '>=') expr
| expr '&&' expr
| expr '||' expr
| var '=' expr
| '(' expr ')'
| var
| funcname '(' arguments ')'
| parametername
    ;
var
: varname
| arrayname '[' expr ']' 
    ;
arguments
: argumentlist
|
    ;
argumentlist
: expr
| argumentlist ',' argumentlist   
    ;
varname
: ID
    ;
arrayname
: ID
    ;
funcname
: ID
    ;
parametername
: ID 
    ;

ID:     [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*) ;
CHAR:   '\''.'\'';
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
