#include <stdio.h>
#include <stdlib.h>
 
/* 모든 명령줄 인수와 환경 변수를 프린트한다. */
int main(int argc, char *argv[])
{
   char    **ptr;
   extern char  **environ;
   int i;

   for (i = 0;environ[i] != 0; i++) /* 모든 환경 변수 값 프린트*/
       printf("%s \n",environ[i]);

   exit(0);
}
