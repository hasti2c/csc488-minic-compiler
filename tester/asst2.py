#!/usr/bin/python3
#
# Assignment 2 Private tester
#
# Tests a program path and against an expected output
#

import tester

test_opt = '--check-parse-tree'

abs_path = '' # Add absolute path here if necessary


# ['public_tests/queen.c', b'Number of Parse Errors: 0\nNum Stmt: 31\nNum Expr: 167\nNum Binop: 62\nNum Plus: 17\n', 3, False],

test_cases = [
    # Path, expected output, marks, isPublic test case
    ['public_tests/var.c', b'Number of Parse Errors: 0\nNum Stmt: 5\nNum Expr: 10\nNum Binop: 5\nNum Plus: 0\n', 2, True],
    ['public_tests/var_loop.c', b'Number of Parse Errors: 0\nNum Stmt: 4\nNum Expr: 15\nNum Binop: 6\nNum Plus: 1\n', 2, True],
    ['public_tests/conds.c', b'Number of Parse Errors: 0\nNum Stmt: 11\nNum Expr: 21\nNum Binop: 4\nNum Plus: 0\n', 2, True],


    ['private_tests/easy.c', b'Number of Parse Errors: 0\nNum Stmt: 8\nNum Expr: 16\nNum Binop: 5\nNum Plus: 1\n', 1, False],
    ['private_tests/coins.c', b'Number of Parse Errors: 0\nNum Stmt: 19\nNum Expr: 45\nNum Binop: 18\nNum Plus: 0\n', 2, False],  
    ['private_tests/fib.c', b'Number of Parse Errors: 0\nNum Stmt: 9\nNum Expr: 25\nNum Binop: 7\nNum Plus: 1\n', 2, False],
    ['private_tests/if-pass.c', b'Number of Parse Errors: 0\nNum Stmt: 5\nNum Expr: 14\nNum Binop: 4\nNum Plus: 2\n', 2, False],
    ['private_tests/break.c', b'Number of Parse Errors: 0\nNum Stmt: 11\nNum Expr: 25\nNum Binop: 10\nNum Plus: 2\n', 2, False],
    ['private_tests/operators.c', b'Number of Parse Errors: 0\nNum Stmt: 47\nNum Expr: 115\nNum Binop: 27\nNum Plus: 2\n', 2, False],
    ['private_tests/char.c', b'Number of Parse Errors: 0\nNum Stmt: 2\nNum Expr: 3\nNum Binop: 1\nNum Plus: 0\n', 2, False],
    ['private_tests/continue.c', b'Number of Parse Errors: 0\nNum Stmt: 4\nNum Expr: 10\nNum Binop: 4\nNum Plus: 1\n', 2, False],
]

test_parse_error_cases = [
    ['private_tests/if-error.c', b'Number of Parse Errors: 1', 2, False],
]

def partial_check_output(test, expected, mark=1):
    e = expected.decode("utf-8") 
    a = test.actual.decode("utf-8") 
    if test.verbose > 0:
        print('EXPECTING: ' + str(expected))
        # print('FOUND: ' + str(test.actual))
    if str(e) in str(a):
        test.add_mark(mark)
        test.add_private_mark(mark)
        print('PASSED CASE')
    else:
        print('FAILED CASE')
        print('COULD NOT FIND "{}" IN OUTPUT STRING'.format(e))

def main():
    test = tester.Core('Assignment 2 Private Tester', 23)

    # Try to build source code from supplied path
    test.build_submission()

    # All tests
    for case in test_cases:
        # Build test path
        test_path = [test.exec_path]
        test_path.append(test_opt)
        test_path.append(abs_path+case[0])
        # Supply the executable and test program path
        test.start_test(test_path)
        # Check the program output against a string and assign a mark
        test.check_output(case[1], case[2], case[3])
    
    # Parse Error case
    for case in test_parse_error_cases:
        # Build test path
        test_path = [test.exec_path]
        test_path.append(test_opt)
        test_path.append(abs_path+case[0])
        # Check partial output
        test.start_test(test_path)
        partial_check_output(test, case[1], case[2])

if __name__ == '__main__':
    main()
    
