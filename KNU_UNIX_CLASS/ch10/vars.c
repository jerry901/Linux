#include <stdio.h>
#include <stdlib.h>

int a;
static int b;
void fun(int n);

int main()
{
    int c;
    static int d;
    char *p;
    int *ptr;     

    p = (char *) malloc(40);
    ptr = (int *)malloc(10* sizeof(int));
    printf("sizeof(int)=%d\n", sizeof(int));
    fun(5);
}
	
void fun(int n)
{
    int m = 6;
    //     ...
}
