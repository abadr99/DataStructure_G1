# NOTES:\
	1) SourceFiles (.c) ---[Compiler]---> ObjectFiles(.O) ---[Linker]---> .exe\
# -------------------------------------------------------------------------------------------------------

CC := gcc
CCFLAGS:= -fdiagnostics-color=always -g #-c 
#INCLUDES:= -Iinc\01_Stack -Iinc\02_Queue\01_CircularQueue -Iinc\02_Queue\02_PriorityQueue -Iinc\03_LinkedList\02_DoublyLinkedList -IUtils       


# ---------------- Header Files ---------------
#TODO (@Badr) : Generalize depth of directory 
# ----------------------------------------------
INC := Utils
INCLDIR := inc
INC += $(wildcard $(INCLDIR)/*)
INCLDIR := inc/*
INC += $(wildcard $(INCLDIR)/*[!.h][!.md]) #to exclude all files (actuallty we want paths only)
INCLUDES := $(addprefix -I,$(INC))
# -----------------------------------------------


# ---------------- Source Files ---------------
#TODO (@Badr) : Generalize depth of directory 
# ----------------------------------------------
SOURCES := $(wildcard *.c)

SOURCEDIR+= src/*
SOURCES += $(wildcard $(SOURCEDIR)/*.c)

SOURCEDIR:= src/*/*
SOURCES += $(wildcard $(SOURCEDIR)/*.c)
# -----------------------------------------------

# -------------------- SCRIPTS ------------------
CLEAN_CODE_PATH := ./Utils/Scripts/CleanCode.py
PRE_SCRIPT := $(wildcard $(SCRIPT_PATH)/*.py)
CC_PRE_SCRIPT := python
# -----------------------------------------------

ifeq (1,$(linux))
all: #clean-code
	@echo "[LINUX] : Bulding for and Running ......"
	@$(CC) $(CCFLAGS) $(SOURCES) $(INCLUDES) -o main.exe
	@./main.exe

build:
	@echo "[LINUX] : Bulding ................................"
	@$(CC) $(CCFLAGS) $(SOURCES) $(INC_PATH) -o main.exe

clean-code:
	@echo "[LINUX] : Checking for WTFs ......"
	@python $(CLEAN_CODE_PATH)

clean:
	@echo "[LINUX] : Cleaning ......"
	@rm -rf $(wildcard *.o)
	@rm -rf $(wildcard *.exe)
else
all: clean-code
	@echo "[WIN] : Bulding and Running ......"
	@$(CC) $(CCFLAGS) $(SOURCES) $(INCLUDES) -o main.exe
	@main.exe

build:
	@echo "[WIN] : Bulding ............................."
	@$(CC) $(CCFLAGS) $(SOURCES) $(INC_PATH) -o main.exe

clean-code:
	@echo "[WIN] : Checking for WTFs ......"
	@python $(CLEAN_CODE_PATH)

clean:
	@echo "[WIN] : Cleaning ......"
	@del -rf $(wildcard *.o)
	@del -rf $(wildcard *.exe)
endif
 