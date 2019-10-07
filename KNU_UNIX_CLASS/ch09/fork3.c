#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 부모 프로세스가 두 개의 자식 프로세스를 생성한다. */
int main() 
{
   int pid1, pid2, status;

   pid1 = fork();

   if(pid1 != 0){
	   wait(&status);
   }
   else if (pid1 == 0) {
      printf("[Child 1] : Hello, world ! pid=%d\n",getpid());
	  exit(1);
   }

   /** waitpid(pid1); */

   pid2 = fork();

   if(pid2 != 0){
	   wait(&status);
   }
   else if (pid2 == 0 && pid1 != 0) {
      printf("[Child 2] : Hello, world ! pid=%d\n",getpid());
	  exit(2); 
   }

   printf("pid1 : %d, pid2 : %d\n", pid1, pid2);

   return 0;

}
