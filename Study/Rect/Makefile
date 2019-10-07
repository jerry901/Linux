main : main.o inputArea.o findOne.o
	gcc -g -o main findOne.o main.o inputArea.o -lm
main.o : main.c
	gcc -g -c main.c
inputArea.o : inputArea.c
	gcc -g -c inputArea.c
findOne.o : findOne.c
	gcc -g -c findOne.c
