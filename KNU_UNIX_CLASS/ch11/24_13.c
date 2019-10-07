#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static int signal_flag = 0; 
void signalHandler(int signo); 

main() 
{ 
    struct sigaction act;

    /* 부모 프로세스는 */
    if (fork()) { 
       printf("a parent process begins\n"); 
       act.sa_handler = signalHandler;
       sigemptyset(&act.sa_mask);
       act.sa_flags = 0;
       /* SIGINT에 대해 act 행동을 하도록 설정 */
       sigaction(SIGINT, &act, NULL);
       /* 시그널이 도착할 때까지 실행을 중단 */
       printf("the parent waits for a signal from the child\n");
       pause(); 
       if (signal_flag) 
          printf("signal fired in the parent process\n"); 
       exit(0); 
    /* 자식 프로세스는 */
    } else { 
       sleep(5);
       /* 부모 프로세스에 SIGINT 시그널 보냄 */
       printf("a child process sends the parent a SIGINT signal\n");
       kill(getppid(), SIGINT);   /* getppid는 부모 프로세스의 프로세스 ID를 반환 */
       exit(0); 
    } 
}
 
void signalHandler(int signo) 
{ 
    signal_flag = 1; 
}
