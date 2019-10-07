shell : shell.o procSort.o argTok.o exFg.o exBg.o
	gcc -o shell shell.o procSort.o argTok.o exFg.o exBg.o
shell.o : shell.c shell.h
	gcc -c shell.c shell.h
procSort.o : procSort.c
	gcc -c procSort.c
argTok.o : argTok.c 
	gcc -c argTok.c 
exBg.o : exBg.c 
	gcc -c exBg.c 
exFg.o : exFg.c 
	gcc -c exFg.c 
