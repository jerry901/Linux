#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;
void alarmHandler();

/* 명령줄 인수로 받은 명령어 실행에 제한 시간을 둔다. */
int main(int argc, char *argv[])
{  
    int child, status, limit;

    signal(SIGALRM,alarmHandler);
    sscanf(argv[1], "%d", &limit);	
    alarm(limit);  /* 알람 시간 설정 */

    pid = fork( );
    if (pid == 0) {
        execvp(argv[2], &argv[2]);
        fprintf(stderr, "%s:실행 불가\n",argv[1]);
    } else {
	printf("[parent] Parent waits for alarm signal.\n"); 
        child = wait(&status);
        printf("[parent:%d] The child process %d was killed.\n", getpid(), pid);
    }
}

void alarmHandler()
{
    printf("[alarm] alarm is on\n");
    printf("[parent] send the child process %d the SIGKILL signal.\n", pid);
    kill(pid, SIGKILL);  /* SIGINT 자식 프로세스 강제 종료 */
}
