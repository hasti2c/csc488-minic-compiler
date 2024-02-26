#!/usr/bin/python3
#
# Assignment 3 Public tester
#
# Tests a program path and against an expected output
#

import tester
import re
import os, sys
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# Change path to minicc here
exec_path = [SCRIPT_DIR + '/../build/src/minicc', '--print-ast']

test_cases = [
    ['public_tests/var.c', b'MiniCProg [syslibFlag=0] (3, 0)\n|-VarDecl (3, 0)\n  |-TypeReference: [val=int] (3, 0)\n  |-VarRef (3, 4)\n    |-Identifier [name=alice] (3, 4)\n  |-VarRef (3, 11)\n    |-Identifier [name=bob] (3, 11)\n  |-VarRef (3, 16)\n    |-Identifier [name=charlie] (3, 16)\n|-VarDecl (4, 0)\n  |-TypeReference: [val=bool] (4, 0)\n  |-VarRef (4, 5)\n    |-Identifier [name=zeta] (4, 5)\n|-VarDecl (5, 0)\n  |-TypeReference: [val=char] (5, 0)\n  |-VarRef (5, 5)\n    |-Identifier [name=asterisk] (5, 5)\n|-FuncDecl [hasBody=1] (7, 0)\n  |-TypeReference: [val=void] (7, 0)\n  |-Identifier [name=main] (7, 5)\n  |-ScopeStatement (7, 12)\n    |-ExprStmt (8, 4)\n      |-AssignmentExpr (8, 4)\n        |-VarRef (8, 4)\n          |-Identifier [name=alice] (8, 4)\n        |-IntLiteralExpr [val=1] (8, 12)\n    |-ExprStmt (9, 4)\n      |-AssignmentExpr (9, 4)\n        |-VarRef (9, 4)\n          |-Identifier [name=bob] (9, 4)\n        |-IntLiteralExpr [val=2] (9, 10)\n    |-ExprStmt (10, 4)\n      |-AssignmentExpr (10, 4)\n        |-VarRef (10, 4)\n          |-Identifier [name=charlie] (10, 4)\n        |-IntLiteralExpr [val=3] (10, 14)\n    |-ExprStmt (11, 4)\n      |-AssignmentExpr (11, 4)\n        |-VarRef (11, 4)\n          |-Identifier [name=zeta] (11, 4)\n        |-BoolLiteralExpr [val=0] (11, 11)\n    |-ExprStmt (12, 4)\n      |-AssignmentExpr (12, 4)\n        |-VarRef (12, 4)\n          |-Identifier [name=asterisk] (12, 4)\n        |-CharLiteralExpr [val=*] (12, 15)\n', 1],
    ['public_tests/var_loop.c', b"MiniCProg [syslibFlag=0] (3, 0)\n|-VarDecl (3, 0)\n  |-TypeReference: [val=int] (3, 0)\n  |-VarRef (3, 4)\n    |-Identifier [name=x] (3, 4)\n|-VarDecl (4, 0)\n  |-TypeReference: [val=int] (4, 0)\n  |-VarRef (4, 4)\n    |-Identifier [name=arr] (4, 4)\n    |-IntLiteralExpr [val=10] (4, 4)\n|-FuncDecl [hasBody=1] (6, 0)\n  |-TypeReference: [val=int] (6, 0)\n  |-Identifier [name=main] (6, 4)\n  |-ScopeStatement (6, 11)\n    |-ExprStmt (7, 4)\n      |-AssignmentExpr (7, 4)\n        |-VarRef (7, 4)\n          |-Identifier [name=x] (7, 4)\n        |-IntLiteralExpr [val=5] (7, 8)\n    |-ForStmt (8, 4)\n      |-AssignmentExpr (8, 9)\n        |-VarRef (8, 9)\n          |-Identifier [name=x] (8, 9)\n        |-IntLiteralExpr [val=0] (8, 13)\n      |-BinaryExpr [opcode='<'] (8, 16)\n        |-VarExpr (8, 16)\n          |-VarRef (8, 16)\n            |-Identifier [name=x] (8, 16)\n        |-IntLiteralExpr [val=10] (8, 20)\n      |-AssignmentExpr (8, 24)\n        |-VarRef (8, 24)\n          |-Identifier [name=x] (8, 24)\n        |-BinaryExpr [opcode='+'] (8, 28)\n          |-VarExpr (8, 28)\n            |-VarRef (8, 28)\n              |-Identifier [name=x] (8, 28)\n          |-IntLiteralExpr [val=1] (8, 32)\n      |-ExprStmt (9, 8)\n        |-AssignmentExpr (9, 8)\n          |-VarRef (9, 8)\n            |-Identifier [name=arr] (9, 8)\n            |-VarExpr (9, 12)\n              |-VarRef (9, 12)\n                |-Identifier [name=x] (9, 12)\n          |-VarExpr (9, 17)\n            |-VarRef (9, 17)\n              |-Identifier [name=x] (9, 17)\n    |-ReturnStmt (10, 4)\n      |-IntLiteralExpr [val=0] (10, 11)\n", 2],
    ['public_tests/conds.c', b"MiniCProg [syslibFlag=1] (3, 0)\n|-FuncDecl [hasBody=1] (5, 0)\n  |-TypeReference: [val=bool] (5, 0)\n  |-Identifier [name=isTen] (5, 5)\n  |-Parameter (5, 11)\n    |-TypeReference: [val=int] (5, 11)\n    |-Identifier [name=a] (5, 15)\n  |-ScopeStatement (5, 18)\n    |-IfStmt (6, 4)\n      |-BinaryExpr [opcode='!='] (6, 8)\n        |-VarExpr (6, 8)\n          |-VarRef (6, 8)\n            |-Identifier [name=a] (6, 8)\n        |-IntLiteralExpr [val=10] (6, 13)\n      |-ReturnStmt (7, 8)\n        |-BoolLiteralExpr [val=0] (7, 15)\n    |-ReturnStmt (8, 4)\n      |-BoolLiteralExpr [val=1] (8, 11)\n|-FuncDecl [hasBody=1] (11, 0)\n  |-TypeReference: [val=int] (11, 0)\n  |-Identifier [name=main] (11, 4)\n  |-ScopeStatement (11, 11)\n    |-VarDecl (12, 4)\n      |-TypeReference: [val=int] (12, 4)\n      |-VarRef (12, 8)\n        |-Identifier [name=myScore] (12, 8)\n      |-VarRef (12, 17)\n        |-Identifier [name=yourScore] (12, 17)\n    |-ExprStmt (13, 4)\n      |-AssignmentExpr (13, 4)\n        |-VarRef (13, 4)\n          |-Identifier [name=myScore] (13, 4)\n        |-IntLiteralExpr [val=10] (13, 14)\n    |-ExprStmt (14, 4)\n      |-AssignmentExpr (14, 4)\n        |-VarRef (14, 4)\n          |-Identifier [name=yourScore] (14, 4)\n        |-UnaryExpr [opcode='-'] (14, 16)\n          |-IntLiteralExpr [val=10] (14, 17)\n    |-IfStmt (16, 4)\n      |-BinaryExpr [opcode='&&'] (16, 8)\n        |-CallExpr (16, 8)\n          |-Identifier [name=isTen] (16, 8)\n          |-VarExpr (16, 14)\n            |-VarRef (16, 14)\n              |-Identifier [name=myScore] (16, 14)\n        |-CallExpr (16, 26)\n          |-Identifier [name=isTen] (16, 26)\n          |-VarExpr (16, 32)\n            |-VarRef (16, 32)\n              |-Identifier [name=yourScore] (16, 32)\n      |-ScopeStatement (16, 44)\n        |-ExprStmt (17, 8)\n          |-CallExpr (17, 8)\n            |-Identifier [name=putint] (17, 8)\n            |-IntLiteralExpr [val=1] (17, 15)\n        |-ReturnStmt (18, 8)\n          |-IntLiteralExpr [val=1] (18, 15)\n    |-ExprStmt (20, 4)\n      |-CallExpr (20, 4)\n        |-Identifier [name=putint] (20, 4)\n        |-IntLiteralExpr [val=0] (20, 11)\n    |-ReturnStmt (21, 4)\n      |-IntLiteralExpr [val=0] (21, 11)\n", 2],
]

def main():
    test = tester.Core('Assignment 3 Public Tester', 5)

    # Public tests
    for case in test_cases:
        test_path = exec_path + [case[0]]
        # Supply the executable and test program path
        test.start_test(test_path)
        # Check the program output against a string and assign a mark
        if test.actual:
            # Ignore anything in brackets for A3 AST
            test.actual = re.sub(r"\(.*?\)","", str(test.actual))
            test.check_output(re.sub(r"\(.*?\)","", str(case[1])), case[2])

if __name__ == '__main__':
    main()