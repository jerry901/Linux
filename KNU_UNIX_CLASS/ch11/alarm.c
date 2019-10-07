#include <unistd.h> 
#include <stdio.h>

/* 알람 시그널을 보여주는 프로그램 */
int main( )
{
    int sec = 0;

    alarm(5);
    printf("infinite loop \n");
    while (1) {
        sleep(1);
        printf("%d sec passed\n", ++sec);
    }
    printf("not run \n");
}
