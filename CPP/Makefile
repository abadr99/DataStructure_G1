CC := g++
CCFLAGS:= -fdiagnostics-color=always -g -Wall #-c 

DIRS := $(shell cat ./DataStructures)

#Stack/Stack.cpp
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.cpp)) 
INC :=  $(foreach dir,$(DIRS), -I$(dir))

all:
	@$(CC) $(CCFLAGS) $(SOURCES) $(INC) main.cpp -o main.exe
	@./main.exe

clean:
	@echo CLEANING ..........
	@rm -rf *.o
	@rm -rf *.bin
	@rm -rf *.exe
	@rm -rf *.dot
	@echo DONE ..........

help:
	@echo "make 	   -->  build the cpp project and run the output"
	@echo "make clean -->  clean all executables, binaries and dot files"
	@echo "make build -->  build ONLY without running" 