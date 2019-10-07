#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100]="Artificial Intelligence and Machine Learning";
    char *ptr,*p;

    ptr = (char *) malloc(100);

    printf("strlen(str)=%ld\n", strlen(str));

    memcpy(ptr, str, strlen(str));  
	printf("ptr = ");
    puts(ptr);

    /** memset(ptr+49,'K',1); */
	/** printf("memset() ptr = "); */
    /** puts(ptr); */

    p = (char *) memchr(ptr,'A',100);
    memset(p,'a',1);
	printf("changed 'A' to 'a' = ");
    puts(p);

	p = (char *) memchr(ptr,'I',100);
    memset(p,'i',1);
	printf("changed 'I' to 'i' = ");
    puts(p);

    p = (char *) memchr(ptr,'M',100);
    memset(p,'m',1);
	printf("changed 'M' to 'm' = ");
    puts(p);

    p = (char *) memchr(ptr,'L',100);
    memset(p,'l',1);
	printf("changed 'L' to 'l' = ");
    puts(p);

    puts(ptr);

	p = (char *) memchr(ptr,'m',100);
    puts(p);
	memmove(p, ptr, strlen(ptr)+1);
	printf("copied = ");
    puts(ptr);
}
