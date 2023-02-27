import sys
from subprocess import Popen, PIPE

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
# Take arguments to script : 1) executable path 
#                            2) path of inputs 
#                            3) path of outputs
program_path = str(sys.argv[1])
test_ip_path = str(sys.argv[2])
test_op_path = str(sys.argv[3])

test_ip_file = open(test_ip_path,'r')
test_op_file = open(test_op_path,'r')

input_lines  = test_ip_file.readlines()
output_lines = test_op_file.readlines()

input_lines_count  = len(input_lines)
output_lines_count = len(output_lines)

assert input_lines_count == output_lines_count,     "INPUT TEST CASES AND OUTPUT RESULTS IS NOT MATCHED"
assert '\n' in input_lines[input_lines_count-1],    "INPUT FILE LAST LINE IS NOT LINE YOU HAVE TO MAKE LAST LINE EMPTY"
assert '\n' in output_lines[output_lines_count-1],  "INPUT FILE LAST LINE IS NOT LINE YOU HAVE TO MAKE LAST LINE EMPTY"

test_ip_file.close()
test_op_file.close()

test_number = 0
print(input_lines_count , "TESTS LOADED ...... " + bcolors.ENDC)
print(bcolors.OKGREEN + "[===============================" ,input_lines_count,"===============================]" + bcolors.ENDC)
for (input_line,output_line) in zip(input_lines,output_lines) :
    test_number += 1
    p = Popen([program_path], stdout=PIPE, stdin=PIPE)
    input_line = bytes(input_line, 'ascii')
  
    
    p.stdin.write(input_line)
    p.stdin.flush()
    result = p.stdout.readline().strip()
    result = result.decode("ascii")
    result=result.strip()
    output_line=output_line.strip()
    if result == output_line :
        test_number= f'{test_number:02}'
        #test_number=test_number.rjust(2,'0')
        print(bcolors.BOLD+"[",test_number,"/",input_lines_count,"] : ", bcolors.OKGREEN +"PASS" + bcolors.ENDC,sep="")
        test_number=int(test_number)
    else :
        test_number= f'{test_number:02}'
        print(bcolors.BOLD+"[",test_number,"/",input_lines_count,"] : ", bcolors.FAIL +"FAIL"+ bcolors.ENDC,sep="")
        print(bcolors.OKCYAN +  "EXPECTED :" + bcolors.ENDC,result)
        print(bcolors.OKCYAN +  "FOUND :   " + bcolors.ENDC,output_line)
        test_number=int(test_number)
        break