#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler();

/* 알람 시그널을 처리한다. */
int main( )
{
    int sec = 0;

    signal(SIGALRM, SIG_DFL);
    alarm(5);  /* 알람 시간 설정 */
    printf("infinite loop \n");
    while (1) {
        sleep(1);
        printf("%d sec passed \n", ++sec);
    }
	printf("실행되지 않음");
}

void alarmHandler()
{
    printf("Get up please!\n");
    exit(0);
}
