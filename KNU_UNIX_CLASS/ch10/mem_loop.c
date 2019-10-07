#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[32]="Do you like Linux?";
    char *ptr,*p;
    int i;

    ptr = (char *) malloc(32);
    for (i=0; i<32; i++)
	printf("%d,", ptr[i]);
    printf("\n%s\n", ptr);

    printf("strlen(str)=%d\n", strlen(str));
    memcpy(ptr, str, strlen(str));  
    for (i=0; i<32; i++)
	printf("%d %d %c,", i, ptr[i], ptr[i]);
//    printf("%s\n", ptr);
    printf("\n");
    memset(ptr+12,'l',1);
//    printf("%s\n", ptr);
    for (i=0; i<32; i++)
	printf("%d%c", i, ptr[i]);
    printf("\n");

    p = (char *) memchr(ptr,'l',18);
    printf("%s\n", p);
    memmove(str+12,str+7,11); 
    printf("%s\n", str);
}
