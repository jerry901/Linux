shell : shell.o exFg.o argTok.o
	gcc -g -o shell shell.o exFg.o argTok.o
shell.o : shell.c shell.h
	gcc -g -c shell.c shell.h
argTok.o : argTok.c
	gcc -g -c argTok.c
exFg.o : exFg.c
	gcc -g -c exFg.c

