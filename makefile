# Makefile for dates

CC = gcc

IN_FILE = dates.dat
OUT_FILE = outFile.txt

PROG1 = dateValidator.c 
PROG2 = dateConverter.c 

PROG1_EXE =  dateV.out
PROG2_EXE =  dateC.out

OUT_EXE = dateV.out dateC.out outFile.txt

#---


build: compile1 compile2

compile1: $(PROG1)
	$(CC) $(PROG1) -o $(PROG1_EXE) 

compile2: $(PROG2)
	$(CC) $(PROG2) -o $(PROG2_EXE)

clean:	
	rm -rf *o $(OUT_EXE)

rebuild: clean build
