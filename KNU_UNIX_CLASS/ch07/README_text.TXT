<getc(fp)/putc(c, stdout)>
$ gcc cat.c
$ a.out cat.c
#include <stdio.h>

/* 텍스트 파일 내용을 표준출력에 프린트 */
int main(int argc, char *argv[])
{
...

<fgetc(fp1)/fputc(fp2)>
$ gcc copy.c
$ a.out copy.c copy2.c
$ ls -l copy*
-rw-r--r--   1 shcho    prof         461  5월 16일  17:06 copy2.c
-rw-r--r--   1 shcho    prof         461 2016년  9월  6일 copy.c

<fgets(buffer, MAXLINE, ft)>
$ gcc line.c
$ a.out line.c
  1 #include <stdio.h>
  2 #define MAXLINE 80
  3
...

<fprintf(fp, ...)>
$ gcc fprint.c
$ a.out test.txt
학번    이름  점수
1401002 Kim   80  	# user inputs
1401003 Lee   90
1401006 Park  70
$ cat test.txt		# test.txt: user inputs were stored
1401002 Kim 80 1401003 Lee 90 1401006 Park 70 

<fscanf(fp, ...)>
$ gcc fscan.c
$ a.out test.txt
학번    이름  점수
1401002 Kim 80		# standard output
1401003 Lee 90
1401006 Park 70
