#include <stdio.h>


/* copy: from을 to에 복사, to가 충분히 크다*/
void copy(char from[], char to[])
{
   int j;

   j = 0;
   while ((to[j] = from[j]) != '\0')
       ++j;
}  
