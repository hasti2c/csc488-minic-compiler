#!/usr/bin/python3
#
# tester.py
#
# Core tester framework for tester
#

import sys, os
import argparse
import subprocess
import time
class Base:
    def __init__(self, message, total):
        parser = argparse.ArgumentParser(description='TestUnit')
        parser.add_argument('-v', '--verbose', action='store_true',
                            help='verbose mode')
        args = vars(parser.parse_args())
        if (args['verbose']):
            self.verbose = 1
        else:
            self.verbose = 0
        self.message = message
        print(message)
        self.mark = 0
        self.total = total
        
    def __del__(self):
        if not hasattr(self, 'mark'):
            return
        if self.mark < 0:
            self.mark = 0
        if self.mark > self.total:
            print('mark = ' + str(self.mark) + ' is greater than ' \
                        'total = ' + str(self.total))
            print('\nPLEASE REPORT THIS TO THE INSTRUCTOR OR A TA\n')
        print('Mark for ' + self.message + ' is ' + \
              str(self.mark) + ' out of ' + str(self.total))
        marker = open('tester.out', 'a')
        marker.write(self.message + ', ' + str(self.mark) + \
                     ', ' + str(self.total) + '\n')
        marker.close()
        if self.mark == self.total:
            print('PASS')
        else:
            print('FAIL')        

    def add_mark(self, mark):
        self.mark += int(mark)

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
            sys.exit(1)
    
    def __init__(self, message, total):
        super().__init__(message=message, total=total)

    def __del__(self):
        super().__del__()

    def check_output(self, expected, mark=1):
        if self.verbose > 0:
            print('EXPECTING: ' + str(expected))
            print('FOUND: ' + str(self.actual))
        if self.actual == expected:
            self.add_mark(mark)
        else:
            print('FAILED CASE: -{} mark(s)'.format(mark))

    def command_run(self, path, timeout=5):
        if self.verbose > 0:
            print('RUNNING COMMAND: ' + str(path))
        try:            
            subprocess.call(path, timeout=timeout)
        except Exception as e:
            print("ERROR: " + str(e))
            sys.exit(1)

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
            sys.exit(1)

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
        #line number check. Comment it out if you want to check total line
        # l = self.line_number(f)
        # optl = self.line_number(optf)
        # if self.verbose > 0:
        #     print('alloca count: line number: ' + str(l) + ' opt line number: ' + str(optl))
        # if l < optl:
        #     print('FAILED CASE: -{} mark(s)'.format(mark))

        #alloca instr removement check
        countsf = open(f, 'r').read().count("alloca")
        countsoptf = open(optf, 'r').read().count("alloca")
        if self.verbose > 0:
            print('alloca count: nonopt: ' + str(countsf) + ' opt: ' + str(countsoptf))
        if countsf > countsoptf:
            self.add_mark(mark)
        else:
            print('FAILED CASE: -{} mark(s)'.format(mark))

    def exec_timetest(self, iter, path, datain, getinput=False):
        print('Time Test:' + str(path))
        start = time.time()
        for i in range(iter):
            try:
                process = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
                if getinput:
                    process.stdin.write(datain)
                _ = process.communicate()[0]
                process.stdin.close()
            except Exception as e:
                print("ERROR: " + str(e))
                sys.exit(1)
        end = time.time()
        print("Time Result:", end - start, "seconds")
       