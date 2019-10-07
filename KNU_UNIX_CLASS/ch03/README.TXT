[single file: longest.c]
$ gcc longest.c
$ a.out
Hello
This is a pensil.
Do you like coffee or tea?
Long time no see!
len=26,Do you like coffee or tea?
$ a.out < input.txt
len=39,Spring has just come around the corner.
$ a.out < longest.c
len=64,/* 입력된 줄 가운데 가장 긴 줄을 프린트한다. */

[multiple files: main.c copy.h copy.c]
$ gcc -c main.c
$ gcc -c copy.c
$ gcc -o main main.o copy.o
$ main < copy.c
/* copy: from을 to에 복사, to가 충분히 크다*/
$ main < longest.c
/* 입력된 줄 가운데 가장 긴 줄을 프린트한다. */

