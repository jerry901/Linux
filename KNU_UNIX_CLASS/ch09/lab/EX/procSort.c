#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

char *procSort(char *args, char *ptr, const char delim,  int length)
{
	char *p = ptr;

	strncpy(args, p, length);
	args[length] = '\0';

	for (int i = length - 1; ; i--) {
		if(args[i] == ' ' || args[i] == '\t')	
			args[i] = '\0';
		else 
			break;
	}

	if(!(p = (char *)memchr(p, delim, strlen(ptr))))
		return NULL;
	else{
		p++;
		return p;
	}
}
