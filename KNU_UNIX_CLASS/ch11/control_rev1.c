#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void stopHandler();
void contHandler();

int pid1, pid2;

/* 시그널을 이용하여 자식 프로세스들을 제어한다. */
int main( )
{
   //int pid1, pid2, count1 = 0, count2 = 0;
   int count1 = 0, count2 = 0;

   signal(SIGSTOP, stopHandler);
   signal(SIGCONT, contHandler);

   pid1 = fork( );
   if (pid1 == 0) {
      while (1) {
         sleep(1);
         printf("child[1:%d] runs: %d\n", getpid(), ++count1);
      }
   }

   pid2 = fork( );
   if (pid2 == 0) {
      while (1) {
         sleep(1);
         printf("child[2:%d] runs: %d\n", getpid(), ++count2);
      }
   }

   sleep(2);
   kill(pid1, SIGSTOP);
   sleep(2);
   kill(pid1, SIGCONT);
   sleep(2);
   kill(pid2, SIGSTOP);
   sleep(2);
   kill(pid2, SIGCONT);
   sleep(5);
   kill(pid1, SIGKILL);
   kill(pid2, SIGKILL);
}

void stopHandler()
{
   printf("[STOP] child process %d stops\n", getpid());
}

void contHandler()
{
   printf("[CONT] child process %d continues\n", getpid());
}
