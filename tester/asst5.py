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

    ['private_tests/test_continue.c', 0, b'None', b'15 16 17 18 19 \n1 2 3 4 5 ', 1, 0],
    ['private_tests/nest_break4.c', 1, b'10\n100\n7\n', b'10 12 14 16 18 20 22 ', 2, 0],
    ['private_tests/lazy.c', 0, b'None', b'0 \n0 1 2 3 4 5 6 7 8 9 \n', 2, 0],
    ['private_tests/getput1.c', 1, b'123456789\n', b'123456789 ', 1, 0],
    ['private_tests/getput2.c', 1, b'123456789\n123456790\n', b'123456789 ', 2, 0],
    ['private_tests/getput3.c', 1, b'100\n50\n', b'101 ', 2, 0],
    ['private_tests/radixsort.c', 1, b'170\n45\n75\n90\n802\n24\n2\n66\n', b'2 24 45 66 75 90 170 802 ', 2, 0],
    ['private_tests/quicksort.c', 1, b'10\n10\n3\n6\n1\n7\n56\n2\n5\n11\n4\n', b'1 2 3 4 5 6 7 10 11 56 ', 3, 0],

]
tmp_files = ['output.bc','output']

def main():
    test = tester.Core('Assignment 5 Public Tester', 20)
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