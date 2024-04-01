#!/usr/bin/python3
#
# Assignment 2 Public tester
#
# Tests a program path and against an expected output
#

import tester
import os, sys
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# Change path to minicc here
exec_path = [SCRIPT_DIR + '/../build/src/minicc', '--check-parse-tree']

test_cases = [
    ['public_tests/var.c', b'Number of Parse Errors: 0\nNum Stmt: 5\nNum Expr: 10\nNum Binop: 5\nNum Plus: 0\n', 1],
    ['public_tests/var_loop.c', b'Number of Parse Errors: 0\nNum Stmt: 4\nNum Expr: 15\nNum Binop: 6\nNum Plus: 1\n', 2],
    ['public_tests/conds.c', b'Number of Parse Errors: 0\nNum Stmt: 11\nNum Expr: 21\nNum Binop: 4\nNum Plus: 0\n', 2]
]

def main():
    test = tester.Core('Assignment 2 Public Tester', 5)

    # Public tests
    for case in test_cases:
        test_path = exec_path + [case[0]]
        # Supply the executable and test program path
        test.start_test(test_path)
        # Check the program output against a string and assign a mark
        test.check_output(case[1], case[2])

if __name__ == '__main__':
    main()
    
