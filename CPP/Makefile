CC:= g++
CCFLAGS:= -fdiagnostics-color=always -g -Wall -std=c++17

UNIT_TEST_OPT:= uTest
TARGET:= DSA

DIRS := $(shell cat ./build.dir)
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.cpp))
SOURCES_COUNT:= $(words $(SOURCES))
SOURCES_CTR:=0
SOURCES += ./main.cpp
INC:=  $(foreach dir,$(DIRS), -I$(dir))
OBJS:= $(SOURCES:.cpp=.o)


.PHONY: all clean build utests test

all:build

build: $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(TARGET)
	@echo "\n[Makefile] : Compiled successfully."

utests:build
	./$(TARGET) $(UNIT_TEST_OPT)

%.o : %.cpp
	@$(CC) $(CCFLAGS) $(INC) -c $< -o $@
	@$(eval SOURCES_CTR=$(shell echo $$(($(SOURCES_CTR)+1))))
	@printf '\033[2K\r%s' "[Makefile] : [$(SOURCES_CTR)/$(words $(SOURCES))] $<"
	
clean:
	@find . -name "*.o" -type f -delete
	@rm -rf build
	@rm -rf *.o
	@rm -rf *.bin
	@rm -rf *.exe
	@rm -rf *.dot
	@echo [Makefile] : Cleaning done successfully.

test:
	@python3 Utils/TestCompare.py $(args) 

help:
	@echo "make 	   -->  build the cpp project and run the output"
	@echo "make clean -->  clean all executables, binaries and dot files"
	@echo "make build -->  build ONLY without running" 
	@echo "make utests -->  build and run all unit-tests" 
	@echo "make test args=\"VAR1 VAR2 VAR3\" -->  used to run the test where :"
	@echo "		VAR1 : Path of the executable" 
	@echo "		VAR2 : Path of input file" 
	@echo "		VAR3 : Path of output file" 