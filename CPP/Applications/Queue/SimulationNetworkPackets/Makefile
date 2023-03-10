CC := g++
CCFLAGS:= -fdiagnostics-color=always -g -Wall #-c 

SOURCES  :=  $(wildcard *.cpp)

all:
	@$(CC) $(CCFLAGS) $(SOURCES) -o main.exe
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