#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static int signal_flag = 0; 
void signalHandler(int signo); 

main() 
{ 
    struct sigaction act;

    /* �θ� ���μ����� */
    if (fork()) { 
       printf("a parent process begins\n"); 
       act.sa_handler = signalHandler;
       sigemptyset(&act.sa_mask);
       act.sa_flags = 0;
       /* SIGINT�� ���� act �ൿ�� �ϵ��� ���� */
       sigaction(SIGINT, &act, NULL);
       /* �ñ׳��� ������ ������ ������ �ߴ� */
       printf("the parent waits for a signal from the child\n");
       pause(); 
       if (signal_flag) 
          printf("signal fired in the parent process\n"); 
       exit(0); 
    /* �ڽ� ���μ����� */
    } else { 
       sleep(5);
       /* �θ� ���μ����� SIGINT �ñ׳� ���� */
       printf("a child process sends the parent a SIGINT signal\n");
       kill(getppid(), SIGINT);   /* getppid�� �θ� ���μ����� ���μ��� ID�� ��ȯ */
       exit(0); 
    } 
}
 
void signalHandler(int signo) 
{ 
    signal_flag = 1; 
}
