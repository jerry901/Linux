#include <stdio.h>
#include <string.h>

void tok_1(char *pBuf, const char *pDel, char **pArg){

	char *save;
	char *s;
	int index = 0;

    s = strtok_r(pBuf, pDel, &save);
    while(s) {
       pArg[index++] = s;
       s = strtok_r(NULL, pDel, &save);
    }
       
    pArg[index] = (char *)0;
}
