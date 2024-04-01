#!/usr/bin/python3
#
# Assignment 4 Public tester
#
# Tests a program path and against an expected output
#

import tester
import re
import os, sys
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# Change path to minicc here
exec_path = [SCRIPT_DIR + '/../build/src/minicc']

test_cases = [
    ['public_tests/var.c', b'', 1],
    ['public_tests/bool_fail.c', b'Redefinition of variable/parameter "z" in the same scope! (4:5)\nVariable and the assignment expression do not have the same type! (9:4)\n"+" opcode must have int type operand! (11:4)\n"&&"/"||" opcode must have bool operand! (13:8)\nFunction has return type "bool", but the returned expression has type "int"! (14:8)\nConditional expression in if statement has non-bool type! (13:8)\n', 2],
    ['public_tests/index_fail.c', b'Indexing an non-array variable! (7:4)\nBreak statement must appear inside a for statement! (12:8)\nThe function "main()" need to return a value at its end! (6:0)\n', 2],

    ['private_tests/easy.c', b'', 1],
    ['private_tests/easy_fail.c', b'Negate "-" opcode must have int operand! (9:5)\nNot "!" opcode must have bool operand! (10:)\n', 2],
    ['private_tests/pizza_fail1.c', b'Function has return type "int", but the returned expression has type "bool"! (27:8)\n', 1],
    ['private_tests/pizza_fail2.c',b'Integer literal must be inside the range of int! (33:8)\nFunction has return type "int", but the returned expression has type "bool"! (35:4)\n', 2],
    ['private_tests/pizza_fail3.c', b'Function has return type "int", but the returned expression has type "bool"! (29:8)\n', 1],
    ['private_tests/pizza_fail4.c', b'Function whichTop() is declared with 1 parameters but called with 0 arguments! (30:4)\n', 1],
    ['private_tests/pizza_fail5.c', b'Array index expressions must have int operand! (12:11)\n', 1],
    ['private_tests/counting_fail1.c', b'Conditional expression in for statement has non-bool type! (12', 2],
    ['private_tests/counting_fail2.c',  b'Function dumy() is not declared before use! (18:4)\nRedefinition of function "main()"! (24:0)\n', 2],
    ['private_tests/ops_fail1.c', b'"+" opcode must have int type operand! (7:4)\n', 1],
    ['private_tests/ops_fail2.c', b'Variable gamma is not declared before use! (7:4)\n', 1],
    ['private_tests/char_idx_fail.c', b'Array index expressions must have int operand! (3:5)\n', 1],
    ['private_tests/continue_fail.c', b'Continue statement must appear inside a for statement! (7:1)\n', 1],
]

tmp_files = ['output.bc']

def convert_str_to_set(s):
    ss = s.split('\n')
    ss = set(ss)
    if '' in ss:
        ss.remove('')
    return ss

def main():
    test = tester.Core('Assignment 4 Public Tester', 22)

    # Public tests
    for case in test_cases:
        test_path = exec_path + [case[0]]
        # Supply the executable and test program path
        test.start_test(test_path)
        # Check the program output against a string and assign a mark
        test.actual = re.sub(r":.*?\)", "", (test.actual).decode("utf-8"))
        test.actual = convert_str_to_set(test.actual)
        expected_output = case[1]
        expected_output = re.sub(r":.*?\)", "", expected_output.decode("utf-8"))
        expected_output = convert_str_to_set(expected_output)
        test.check_output(expected_output, case[2])
        test.clean_up(tmp_files)

if __name__ == '__main__':
    main()
    
