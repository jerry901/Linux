#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void intHandler(int signo);

/* 인터럽트 시그널을 처리한다. */
int main( )
{
    signal(SIGTSTP,intHandler); 

    while (1)
        pause();

    printf("실행되지 않음 \n");
}

void intHandler(int signo)
{
    printf("SIGTSTP signal processed\n");
    printf("signal no: %d\n", signo);
    exit(0);
}
