CC := g++
CCFLAGS:= -fdiagnostics-color=always -g -Wall #-c 

DIRS := $(shell cat ./build.dir)

#Stack/Stack.cpp
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.cpp)) 
INC :=  $(foreach dir,$(DIRS), -I$(dir))

Command := $(firstword $(MAKECMDGOALS))
Arguments := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

all:
	@$(CC) $(CCFLAGS) $(SOURCES) $(INC) main.cpp -o main.exe
	@./main.exe

build:
	@$(CC) $(CCFLAGS) $(SOURCES) $(INC) main.cpp -o main.exe

clean:
	@echo CLEANING ..........
	@rm -rf *.o
	@rm -rf *.bin
	@rm -rf *.exe
	@rm -rf *.dot
	@echo DONE ..........

test:
	@python3 Utils/TestCompare.py $(args) 

help:
	@echo "make 	   -->  build the cpp project and run the output"
	@echo "make clean -->  clean all executables, binaries and dot files"
	@echo "make build -->  build ONLY without running" 
	@echo "make test args=\"VAR1 VAR2 VAR3\" -->  used to run the test where :"
	@echo "		VAR1 : Path of the executable" 
	@echo "		VAR2 : Path of input file" 
	@echo "		VAR3 : Path of output file" 