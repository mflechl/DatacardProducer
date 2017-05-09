import subprocess as sp
import shlex
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('-t', dest='test', help='run test', action='store_true')
parser.add_argument('-m', dest='minimal', help='run minimal test', action='store_true')
args = parser.parse_args()

print 'Compiling...'
proc = sp.Popen(shlex.split('make -B') , stdout=sp.PIPE, stderr=sp.PIPE)
(out, err) = proc.communicate()
print err
if err != '':
    print 'Compiling Error... aborting'
    sys.exit()

cmd = "./makeHTTDatacards"
if args.test:
	cmd += " test"
if args.minimal:
	cmd += " minimal"
p = sp.Popen(shlex.split(cmd),stdout = sys.__stdout__, stderr = sys.__stderr__, shell=False)
p.communicate()