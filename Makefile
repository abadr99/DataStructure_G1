CC := gcc
CCFLAGS:= -fdiagnostics-color=always -g
SRC_PATH:= -I\W:\ProgrammingGroups\G1\C_DataStructure_G1
C_SOURCES := $(wildcard *.c)
C_EXECUTABLE :=$(C_SOURCES:.c=)
CPP_EXECUTABLE :=$(CPP_SOURCES:.cpp=)

PRE_SCRIPT := $(wildcard *.py)
CC_PRE_SCRIPT := python



all:
	@$(CC_PRE_SCRIPT) $(PRE_SCRIPT)
	@$(CC) $(CCFLAGS) $(C_SOURCES) -o main.exe
	@main.exe


clean-code:
	@python CleanCode.py 

clean:
	@del -rf $(wildcard *.exe)

 