#include <stdio.h>
#include <signal.h>

struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo);
int good = -1;

int main(void)
{
   newact.sa_handler = sigint_handler; // 시그널 처리기 지정
   sigfillset(&newact.sa_mask);         // 모든 시그널 봉쇄 

                                           
   // SIGINT를 지정하면서 oldact에 기존 처리기 정보를 저장한다.   
   sigaction(SIGTSTP, &newact, &oldact); 

   while(1)
   {
	   if(good == -1)
		   printf("press Ctrl-Z\n");
	   else if(good == 0)
		   printf("press Ctrl-C to kill this process\n");

       sleep(1);
   }
}

void sigint_handler(int signo)
{
	good = 0;
   printf("good : %d\n", good);
   printf("signal no: %d \n", signo);
   printf("This will end if you press Ctrl-C\n");
   sigaction(SIGINT, &oldact, NULL);
}


