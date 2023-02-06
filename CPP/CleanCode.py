"""
Clean code rules :
1) For header files:
    1) Check if the guard macros exsist

2) Check for files names

3) [TO-DO] : check for comments and remove it {adding options if the comment is very necessary we have to add # before it e.g. // #Comment}
"""

import os

FILE_NAME_COLOR = '\033[94m'
CLEAN_CODE_COLOR = '\033[93m'
BOLD = '\033[1m'
UNDERLINE = '\033[4m'
DEFAULT = '\033[0m'

# structure path
dir_path = os.getcwd()
def PRINT_MSG(msg_id , file):
    if msg_id == "header guard macros not found":
         print(BOLD + CLEAN_CODE_COLOR + "[CLEAN_CODE]: " + DEFAULT +"No header guard macros found or in wrong postion (make sure it's at first line) in " + FILE_NAME_COLOR + file + DEFAULT)
    
    elif msg_id == "First letter is not uppercase":
        print(BOLD + CLEAN_CODE_COLOR + "[CLEAN_CODE]: " + DEFAULT +"Violating naming rules where ", end = '')
        print(FILE_NAME_COLOR + file + DEFAULT + " have to start with " + UNDERLINE +  "uppercase" + DEFAULT + " letter " + DEFAULT, end = '')
        print("and the file name starts with lowercase")
    
    elif msg_id == "not a Config file": 
        print(BOLD + CLEAN_CODE_COLOR + "[CLEAN_CODE]: " + DEFAULT +"Violating naming rules where ", end = '')
        print(FILE_NAME_COLOR + file + DEFAULT + " have _ which used with " +  UNDERLINE + "Config files" + DEFAULT + " only")


def CheckGuardMacros(PATH):
    for PATH, dirs, files in os.walk("."): 
     for filename in files:
      fname = os.path.join(PATH,filename)
      if fname.endswith('.h'):
    
            
            f = open(fname,'r') 
            line1 = f.readline()
            line2 = f.readline()
           
            if(line1[0:6] != "#ifndef" and line2[0:7] != "#define"):
                PRINT_MSG("header guard macros not found" , filename)
            
            


def CheckFilesName(PATH):
        for PATH, dirs, files in os.walk("."): 
         for filename in files:
          
          if (filename.endswith(".cpp") or filename.endswith(".h")) and(filename!="main.cpp"):
            if(filename[0].islower()):
                PRINT_MSG("First letter is not uppercase" , filename)
            index =  filename.find('_')
            if(index > -1 and filename!="STD_TYPES.h"):
             
              if(not filename.endswith("Config.h",index+1) and not filename.endswith("config.h",index+1)):
                PRINT_MSG("not a Config file", filename)



def main():
    CheckGuardMacros(dir_path)
    CheckFilesName(dir_path)



if __name__ == "__main__":
    main()
