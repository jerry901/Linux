#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* 인터럽트 시그널을 기본 처리한다. */
int main( )
{
    signal(SIGINT,SIG_DFL); 

    while (1)
        pause();

    printf("실행되지 않음 \n");
}
