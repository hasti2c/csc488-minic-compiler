#!/usr/bin/python3
#
# marker.py
#
# Core tester framework for marker
#

import sys, os
import argparse
import subprocess

class Base:
    def __init__(self, message, total):
        #For A1 Markus Testing, comment parser things and set self.verbose = 0 and self.path = ""
        parser = argparse.ArgumentParser(description='TestUnit')
        parser.add_argument("path", type=str,
                    help="path of source code")
        parser.add_argument('-v', '--verbose', action='store_true',
                            help='verbose mode')
        args = vars(parser.parse_args())
        if (args['verbose']):
            self.verbose = 1
        else:
            self.verbose = 0
        self.path = args['path']
        self.message = message
        print(message)
        self.public_mark = 0
        self.private_mark = 0
        self.mark = 0
        self.total = float(total)
        
    def __del__(self):
        if not hasattr(self, 'mark'):
            return
        if self.mark < 0:
            self.mark = 0
        if self.mark > self.total:
            print('mark = ' + str(self.mark) + ' is greater than ' \
                        'total = ' + str(self.total))
            print('\nPLEASE REPORT THIS TO THE INSTRUCTOR OR A TA\n')
        print('Mark for ' + self.message + ' Public cases is ' + \
              str(self.public_mark) + ' out of ' + str(self.total))
        print('Mark for ' + self.message + ' Private cases is ' + \
              str(self.private_mark) + ' out of ' + str(self.total))
        print('Mark for ' + self.message + ' is ' + \
              str(self.mark) + ' out of ' + str(self.total))
        # marker = open('tester.out', 'a')
        # marker.write(self.message + ', ' + str(self.mark) + \
                    #  ', ' + str(self.total) + '\n')
        # marker.close()
        if self.mark == self.total:
            print('PASS')
        else:
            print('FAIL')        

    def add_mark(self, mark):
        self.mark += float(mark)

    def add_public_mark(self, mark):
        self.public_mark += float(mark)
        
    def add_private_mark(self, mark):
        self.private_mark += float(mark)

    def reset_mark(self):
        self.mark = 0

    def get_mark(self):
        return self.mark

class Core(Base):
    def set_timeout(self, timeout):
        self.program.timeout = timeout
        if self.verbose > 0:
            print('This test has a timeout of ' + str(timeout) + ' seconds')

    def start_test(self, path, timeout=5):
        if self.verbose > 0:
            print('STARTING PROGRAM: ' + str(path))
        try:            
            self.actual = subprocess.check_output(path, stderr=subprocess.STDOUT, timeout=timeout)   
        except subprocess.CalledProcessError as exc:
            self.actual = exc.output      
        except Exception as e:
            print("ERROR: " + str(e))
            #sys.exit(1)
    
    def __init__(self, message, total):
        super().__init__(message=message, total=total)

    def __del__(self):
        super().__del__()

    # Checks output against expected string
    def check_output(self, expected, mark=1, isPublic=True):
        if self.verbose > 0:
            print('EXPECTING: ' + str(expected))
            print('FOUND: ' + str(self.actual))
        if self.actual == expected:
            self.add_mark(mark)
            if isPublic:
                self.add_public_mark(mark)
            else:
                self.add_private_mark(mark)
            print('PASSED CASE')
        else:
            print('FAILED CASE')

    def command_run(self, path, timeout=5):
        if self.verbose > 0:
            print('RUNNING COMMAND: ' + str(path))
        try:            
            subprocess.call(path, timeout=timeout)
        except Exception as e:
            print("ERROR: " + str(e))
            #sys.exit(1)

    def generate_exec(self, paths):
        for path in paths:
            self.command_run(path)

    def exec_test(self, path, datain, getinput=False, timeout=5):
        if self.verbose > 0:
            print('STARTING PROGRAM: ' + str(path))
        try:
            process = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
            if getinput:
                process.stdin.write(datain)
            self.actual = process.communicate()[0]
            process.stdin.close()
        except Exception as e:
            print("ERROR: " + str(e))
            #sys.exit(1)

    def clean_up (self, files):
        for f in files:
            self.command_run(['rm','-rf',f])

    def line_number(self,f):
        file = open(f, "r")
        nonempty_lines = [line.strip("\n") for line in file if line != "\n"]
        line_count = len(nonempty_lines)
        file.close()
        return line_count

    def opt_check_output(self, f, optf, mark=1):
        #line number check
        l = self.line_number(f)
        optl = self.line_number(optf)
        if self.verbose > 0:
            print('alloca count: line number: ' + str(l) + ' opt line number: ' + str(optl))
        if l < optl:
            print('FAILED CASE: -{} mark(s)'.format(mark))
        countsf = open(f, 'r').read().count("alloca")
        countsoptf = open(optf, 'r').read().count("alloca")
        if self.verbose > 0:
            print('alloca count: nonopt: ' + str(countsf) + ' opt: ' + str(countsoptf))
        if countsf > countsoptf:
            self.add_mark(mark)
        else:
            print('FAILED CASE: -{} mark(s)'.format(mark))

    def build_submission(self):
        curr_dir = os.getcwd()
        build_dir = str(curr_dir + '/build')
        # Clean up local build directory
        self.clean_up([build_dir])

        # Try to build submission
        self.command_run(['mkdir', build_dir])
        self.command_run(['cmake', (self.path), '-B', build_dir], timeout=30)
        self.command_run(['make', '-C', build_dir], timeout=200)
        self.exec_path = build_dir + '/src/minicc'
        self.build_dir = build_dir

    def init_wo_build(self):
        self.exec_path = self.path + '/build/src/minicc'
        self.build_dir = self.path + '/build'
        
    def command_run_with_marks(self, paths, mark=1, timeout=5):
        for path in paths:
            if self.verbose > 0:
                print('RUNNING COMMAND: ' + str(path))
            try:            
                subprocess.check_output(path, timeout=timeout)
            except subprocess.CalledProcessError as exc:
                print('FAILED CASE: -{} mark(s)'.format(mark))
                self.add_mark(-mark)
                break
        self.add_mark(mark)
