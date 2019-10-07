#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

void  p1();
void intHandler();
jmp_buf env;

int main() 
{

    signal(SIGINT, intHandler);

    if (setjmp(env) == 1) {
		printf("Due to longjmp() it returned to main(), then exit.\n");
		exit(0);
    }
    else printf("setjmp(): the first call:it proceeds\n");

    p1(); 
} 

void  p1()
{ 
    while (1) {
        printf("in infinite loop\n");
        sleep(1);
    }
}

void intHandler() 
{

    printf(" entered Ctl+C, calls intHandler() which then calls longjmp(). It runs.\n");
    longjmp(env, 1);
}
