#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void  p1(), p2();
jmp_buf env;

int main() 
{
    if (setjmp(env) != 0) {
	printf("setjmp() returned due to error\n");
	exit(0);
    } 
    else printf("the first call of setjmp() returns 0 and proceeds.\n");

    p1(); 
} 

void  p1()
{ 
    longjmp(env, 0);
    p2();
}

void p2() 
{
    int error;

    error = 1;
    if (error) {
        printf("Error, then longjmp runs and jumps to setjmp().\n");
        longjmp(env, 0);
    }
}
