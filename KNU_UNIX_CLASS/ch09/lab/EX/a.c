#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024 

int argTok(char *fromArg, char *toArg[], const char *delim);

int main()
{
	char str[MAX_SIZE];
	/** char *p = str; */
	char *toStr[MAX_SIZE];
	/** char *p2 = toStr; */
	static const char delim[] = "&";

	printf("PUT YOUR STRGING : ");
	fgets(str, sizeof(str), stdin);


	str[strlen(str)-1] = ';';
	argTok(str, toStr , delim);

	printf("DONE\n");

	return 0;
}
