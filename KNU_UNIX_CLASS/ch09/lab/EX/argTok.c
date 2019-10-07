#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** #define DEBUG */

int argTok(char *fromArg, char *toArg[], const char *delim){

	char *pBuf;
	char *pSave;
	int argIndex = 0;

	for (pBuf = strtok_r(fromArg, delim, &pSave); pBuf;	pBuf = strtok_r(NULL, delim, &pSave)){
		toArg[argIndex++] = pBuf;
	}

#ifdef DEBUG

	char *s;
	int i = 0;

	s = toArg[i];

	while(s){

		printf("toArg[%d] = %s\n",i, s);
		i++;
		s = toArg[i];

	}

#endif

		return 0;

}
