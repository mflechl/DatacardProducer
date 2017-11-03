import subprocess as sp
import multiprocessing as mp
import shlex
import os
import argparse
import sys

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('-t', dest='test', help='run test', action='store_true')
	parser.add_argument('-q', dest='quicktest', help='run test on one sample', action='store_true')
	parser.add_argument('-m', dest='minimal', help='run minimal test', action='store_true')
	parser.add_argument('-n', dest='nlo', help='run NLO signal', action='store_true')
	parser.add_argument('-s', dest='special', help='run with control cuts', action='store_true')
	parser.add_argument('-c', dest='channel', help='datacard channel',choices = ['mt','et','tt','all'], default = 'mt')
	args = parser.parse_args()

	print 'Compiling... (only what has changed... not fully tested yet!)'
#	proc = sp.Popen(shlex.split('make -B') , stdout=sp.PIPE, stderr=sp.PIPE)
	proc = sp.Popen(shlex.split('make') , stdout=sp.PIPE, stderr=sp.PIPE)
	(out, err) = proc.communicate()
	print err
	if err != '':
	    print 'Compiling Error... aborting'
	    sys.exit()

	testEnv = "nom"
	if args.nlo:
		testEnv = "nlo"
	elif args.test:
		testEnv = "test"
	elif args.quicktest:
		testEnv = "quicktest"
	elif args.minimal:
		testEnv = "minimal"



	if args.channel != "all" and not args.special:
		cmd = "./makeHTTDatacards {0} {1}".format(testEnv, args.channel)
		p = sp.Popen(shlex.split(cmd),stdout = sys.__stdout__, stderr = sys.__stderr__, shell=False)
		p.communicate()

	elif args.special:
		cmdList = []
		for s in ["1p","3p","pt_l50","pt_5080","pt_g80","pt_g80_1p","pt_g80_3p","pt_g100","pt_g120"]:
			cmdList.append("./makeHTTDatacards {0} {1}".format(s, args.channel) )


		applyCmdMulti(cmdList)		
	else:
		cmdList = []
		for c in ["et","mt","tt"]:
			cmdList.append("./makeHTTDatacards {0} {1}".format("nom", c) )
			cmdList.append("./makeHTTDatacards {0} {1}".format("nlo", c) )

		applyCmdMulti(cmdList)


def exec_cmd(cmd, q):
    #print cmd
    shlCmd = shlex.split(cmd)
    print "-\033[93mrunning\033[0m- {0} datacard with option {1}".format(shlCmd[2], shlCmd[1])
    filename = 'log/{0}_{1}.log'.format(shlCmd[2],shlCmd[1])
 
    if not os.path.exists('log'):
        os.mkdir('log')

    with open(filename, 'w') as log:
        p = sp.Popen(shlCmd,stdout = log, stderr = log, shell=False)
        p.communicate()

    print "-\033[92mfinished\033[0m- {0} datacard with option {1}".format(shlCmd[2], shlCmd[1])
    q.put(object)

def applyCmdMulti(cmd_list, max_proc=8):

    done_queue = mp.Queue()

    for i, cmd in enumerate(cmd_list):
        if i >= max_proc:
            done_queue.get(block=True)
        proc = mp.Process(target=exec_cmd, args=(cmd, done_queue ) )
        proc.start()


if __name__ == '__main__':
	main()
