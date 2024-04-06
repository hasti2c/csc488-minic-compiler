#!/usr/bin/python3
#
# Assignment 6 Public tester
#
# Tests a program path and against an expected output
#

import tester

import os
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))


# Change path to minicc here
local_path = SCRIPT_DIR + '/../build/'
bcgen_path = [local_path + 'src/minicc']
llgen_path = ['llvm-dis','output.bc','-o','output.ll']
optgen_path = ['opt', '-O0', '-load', local_path + 'src/liballoca2reg.so', '-alloca2reg', 'output.bc', '-o', 'output_opt.bc', '-enable-new-pm=0']
lloptgen_path = ['llvm-dis','output_opt.bc','-o','output_opt.ll']
execgen_path = ['clang-15', 'output_opt.bc', local_path + 'minicio/libminicio.a', '-o', 'output_opt']
run_path = ['./output_opt']

my_optgen_path = ['opt', '-O0', '-load', local_path + 'src/liballoca2reg.so', '-alloca2reg', '-load', local_path + 'src/libalgsimplify.so', '-algsimplify', 'output.bc', '-o', 'my_output_opt.bc', '-enable-new-pm=0']
my_lloptgen_path = ['llvm-dis','my_output_opt.bc','-o','my_output_opt.ll']
my_execgen_path = ['clang-15', 'my_output_opt.bc', local_path + 'minicio/libminicio.a', '-o', 'my_output_opt']
my_run_path = ['./my_output_opt']

o3_optgen_path = ['opt', '-O3', 'output.bc', '-o', 'output_o3.bc', '-enable-new-pm=0']
o3_execgen_path = ['clang-15',  'output_o3.bc', local_path + 'minicio/libminicio.a', '-o', 'output_o3']
o3_run_path = ['./output_o3']

test_cases = [
    ['public_tests/conds.c', 0, b'None', b'0 ', 2],
    ['public_tests/queen.c', 1, b'5', b'0 2 4 1 3 \n0 3 1 4 2 \n1 3 0 2 4 \n1 4 2 0 3 \n2 0 3 1 4 \n2 4 1 3 0 \n3 0 2 4 1 \n3 1 4 2 0 \n4 1 3 0 2 \n4 2 0 3 1 \n', 3],
    ['public_tests/hanoi.c', 1, b'5\n', b'1 0 2 \n2 0 1 \n1 2 1 \n3 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n4 0 1 \n1 2 1 \n2 2 0 \n1 1 0 \n3 2 1 \n1 0 2 \n2 0 1 \n1 2 1 \n5 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n3 1 0 \n1 2 1 \n2 2 0 \n1 1 0 \n4 1 2 \n1 0 2 \n2 0 1 \n1 2 1 \n3 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n', 3],
]
timetest_cases = [
    # ['public_tests/queen_time.c', 1, b'13', None, 0],
    ['my_tests/sample.c', 0, b'None', b'10', 0]
]
tmp_files = ['output.bc','output_opt.bc','output_opt','output.ll','output_opt.ll', 'output_o3.bc', 'output_o3']
def main():
    test = tester.Core('Assignment 6 Public Tester', 8)
    # Public tests
    for case in test_cases:
        paths = []
        paths.append(bcgen_path + [case[0]])
        paths.append(llgen_path)
        paths.append(optgen_path)
        paths.append(lloptgen_path)
        paths.append(execgen_path)
        test.generate_exec(paths)
        datain = case[2]
        # Supply the executable and test program path
        test.exec_test(run_path, datain, case[1])
        # Check the program output against a string and assign a mark
        print("################# 1 ####################")
        test.check_output(case[3], 1)
        print("################# 2 ####################")
        test.opt_check_output('output.ll','output_opt.ll',case[4]-1)
        test.clean_up(tmp_files)
    # Public tests
    for case in test_cases:
        paths = []
        paths.append(bcgen_path + [case[0]])
        paths.append(llgen_path)
        paths.append(my_optgen_path)
        paths.append(my_lloptgen_path)
        paths.append(my_execgen_path)
        test.generate_exec(paths)
        datain = case[2]
        # Supply the executable and test program path
        test.exec_test(my_run_path, datain, case[1])
        # Check the program output against a string and assign a mark
        print("################# 1 ####################")
        test.check_output(case[3], 1)
        print("################# 2 ####################")
        test.opt_check_output('output.ll','my_output_opt.ll',case[4]-1)
        test.clean_up(tmp_files)
    # Time test
    for case in timetest_cases:
        paths = []
        paths.append(bcgen_path + [case[0]])
        paths.append(llgen_path)
        paths.append(optgen_path)
        paths.append(lloptgen_path)
        paths.append(execgen_path)

        paths.append(my_optgen_path)
        paths.append(my_lloptgen_path)
        paths.append(my_execgen_path)

        #-O3 solution time test path
        paths.append(o3_optgen_path)
        paths.append(o3_execgen_path)

        test.generate_exec(paths)
        datain = case[2]
        test.exec_timetest(50,run_path, datain, case[1])
        test.exec_timetest(50,my_run_path, datain, case[1])
        
        #-O3 time test
        test.exec_timetest(50,o3_run_path, datain, case[1])
        
        test.opt_check_output('output.ll','output_opt.ll',0)
        test.opt_check_output('output.ll','my_output_opt.ll',0)
        test.clean_up(tmp_files)
if __name__ == '__main__':
    main()
    