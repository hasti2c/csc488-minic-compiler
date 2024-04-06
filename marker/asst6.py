#!/usr/bin/python3
#
# Assignment 6 Private tester
#
# Tests a program path and against an expected output
#

import marker

# Change path to minicc here
#local_path = '/Users/zandent/Files/csc488/minicc-internal/build/'
#bcgen_path = [local_path + 'src/minicc']
llgen_path = ['llvm-dis','output.bc','-o','output.ll']
#optgen_path = ['opt', '-load', local_path + 'src/liballoca2reg.so', '--alloca2reg', 'output.bc', '-o', 'output_opt.bc']
lloptgen_path = ['llvm-dis','output_opt.bc','-o','output_opt.ll']
#execgen_path = ['clang-15', local_path + 'minicio/libminicio.a', 'output_opt.bc', '-o', 'output_opt']
run_path = ['./output_opt']
test_cases = [
    ['public_tests/conds.c', 0, b'None', b'0 ', 2],
    ['public_tests/queen.c', 1, b'5', b'0 2 4 1 3 \n0 3 1 4 2 \n1 3 0 2 4 \n1 4 2 0 3 \n2 0 3 1 4 \n2 4 1 3 0 \n3 0 2 4 1 \n3 1 4 2 0 \n4 1 3 0 2 \n4 2 0 3 1 \n', 2],
    ['public_tests/hanoi.c', 1, b'5\n', b'1 0 2 \n2 0 1 \n1 2 1 \n3 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n4 0 1 \n1 2 1 \n2 2 0 \n1 1 0 \n3 2 1 \n1 0 2 \n2 0 1 \n1 2 1 \n5 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n3 1 0 \n1 2 1 \n2 2 0 \n1 1 0 \n4 1 2 \n1 0 2 \n2 0 1 \n1 2 1 \n3 0 2 \n1 1 0 \n2 1 2 \n1 0 2 \n', 2],
    ['private_tests/radixsort.c', 1, b'170\n45\n75\n90\n802\n24\n2\n66\n', b'2 24 45 66 75 90 170 802 ', 6],
    ['private_tests/quicksort.c', 1, b'10\n10\n3\n6\n1\n7\n56\n2\n5\n11\n4\n', b'1 2 3 4 5 6 7 10 11 56 ', 6],
]
tmp_files = ['output.bc','output_opt.bc','output_opt','output.ll','output_opt.ll']
tmp_dir = ['build/']
def main():
    test = marker.Core('Assignment 6 Private Tester', 18)
    # Try to build source code from supplied path
    test.build_submission()
    bcgen_path = [test.exec_path]
    execgen_path = ['clang-15', 'output_opt.bc', test.build_dir + '/' + 'minicio/libminicio.a', '-o', 'output_opt']
    optgen_path = ['opt', '-load', test.build_dir + '/' + 'src/liballoca2reg.so', '--alloca2reg', 'output.bc', '-o', 'output_opt.bc', '-enable-new-pm=0']
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
        #Supply the executable and test program path
        test.exec_test(run_path, datain, case[1])
        # Check the program output against a string and assign a mark
        test.check_output(case[3], 1)
        test.opt_check_output('output.ll','output_opt.ll',case[4]-1)
        test.clean_up(tmp_files)
    test.clean_up(tmp_dir)
if __name__ == '__main__':
    main()
    