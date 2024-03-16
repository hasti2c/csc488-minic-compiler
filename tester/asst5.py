#!/usr/bin/python3
#
# Assignment 5 Public tester
#
# Tests a program path and against an expected output
#

import tester

import os, sys
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# Change path to minicc here
local_path = SCRIPT_DIR + '/../build/'
bcgen_path = [local_path + 'src/minicc']
execgen_path = ['clang-15', 'output.bc', local_path + 'minicio/libminicio.a',  '-o', 'output']
run_path = ['./output']
test_cases = [
    ['public_tests/conds.c', 0, b'None', b'0 ', 1],
    ['public_tests/queen.c', 1, b'5', b'0 2 4 1 3 \n0 3 1 4 2 \n1 3 0 2 4 \n1 4 2 0 3 \n2 0 3 1 4 \n2 4 1 3 0 \n3 0 2 4 1 \n3 1 4 2 0 \n4 1 3 0 2 \n4 2 0 3 1 \n', 2],
    ['public_tests/hanoi.c', 1, b'5\n', b'1 0 2 \n2 0 1 \n1 2 1 \n3 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n4 0 1 \n1 2 1 \n2 2 0 \n1 1 0 \n3 2 1 \n1 0 2 \n2 0 1 \n1 2 1 \n5 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n3 1 0 \n1 2 1 \n2 2 0 \n1 1 0 \n4 1 2 \n1 0 2 \n2 0 1 \n1 2 1 \n3 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n', 2],
]
tmp_files = ['output.bc','output']

def main():
    test = tester.Core('Assignment 5 Public Tester', 5)
    # Public tests
    for case in test_cases:
        paths = []
        paths.append(bcgen_path + [case[0]])
        paths.append(execgen_path)
        test.generate_exec(paths)
        datain = case[2]
        #Supply the executable and test program path
        test.exec_test(run_path, datain, case[1])
        # Check the program output against a string and assign a mark
        test.check_output(case[3], case[4])
        test.clean_up(tmp_files)

if __name__ == '__main__':
    main()