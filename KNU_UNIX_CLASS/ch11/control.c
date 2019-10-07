#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* 시그널을 이용하여 자식 프로세스들을 제어한다. */
int main( )
{
   int pid1, pid2, count1 = 0, count2 = 0;
   int pid1_done = -1;

   pid1 = fork( );
   if (pid1 == 0) {
      while (1) {
         sleep(1);
         printf("child[1] runs: %d\n", ++count1);
      }
   }
   else
	   pid1_done = 0;

   pid2 = fork( );
   if (pid2 == 0) {
      while (1) {
		  if(pid1_done == 0){
			sleep(1);
			printf("child[2] runs: %d\n", ++count2);
			printf("pid1_done c2 : %d\n", pid1_done);
		  }
      }
   }

	printf("pid1_done pp : %d\n", pid1_done);
   sleep(2);
   kill(pid1, SIGSTOP);
   sleep(2);
   kill(pid1, SIGCONT);
   sleep(2);
   kill(pid2, SIGSTOP);
   sleep(2);
   kill(pid2, SIGCONT);
   sleep(2);
   kill(pid1, SIGKILL);
   kill(pid2, SIGKILL);
}
