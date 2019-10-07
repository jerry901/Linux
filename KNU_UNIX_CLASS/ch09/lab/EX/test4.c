#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512 
#define MAX_ARGS 40

#define DEBUG

int main()
{
	static const char DELIM_AND = '&';
	static const char DELIM_SEMI_COLON = ';';

	char str[MAX_SIZE];
	char *ptr = NULL;

	char *argsFg[MAX_ARGS] = {0};
	char *argsBg[MAX_ARGS] = {0};

	int bgIndex = 0;
	int fgIndex = 0;

	printf("PUT YOUR STRGING : ");
	fgets(str, sizeof(str), stdin);

	str[strlen(str)-1] = '\0';
	ptr = str;

	while(ptr){
		for(int i = 0; ptr; i++){

			for(int j = 0; ptr[j] == ' '; j++) //명령의 첫 문자가 공백이라면 공백이 나오지 않을 때 까지 ptr++한다.
				ptr++;

			if(ptr[i] == DELIM_SEMI_COLON){
				argsFg[fgIndex] = (char *)malloc((i*sizeof(char)) + 1);
				strncpy(argsFg[fgIndex], ptr, i);
				fgIndex++;

				if(!(ptr = (char *)memchr(ptr, DELIM_SEMI_COLON, strlen(ptr) - 1)))
					break;

				ptr++;
				break;
			}
			else if(ptr[i] == DELIM_AND){
				argsBg[bgIndex] = (char *)malloc((i*sizeof(char)) + 1);
				strncpy(argsBg[bgIndex++], ptr, i);

				if(!(ptr = (char *)memchr(ptr, DELIM_AND, strlen(ptr) - 1)))
					break;

				ptr++;
				break;
			}
			else if(i == ((int)strlen(ptr) - 1)){ //Index가 끝에 위치한다는 것은 아직 세미콜론이나 &가 없다는 의미
				argsFg[fgIndex] = (char *)malloc((i*sizeof(char)) + 1);
				strncpy(argsFg[fgIndex++], ptr, i);
				ptr = NULL;
				break;
			}
		}
	}

#ifdef DEBUG

	argsFg[fgIndex] = (char *)0;
	argsBg[bgIndex] = (char *)0;


	for(int i = 0; argsFg[i]; i ++){
		printf("argsFg[%d] = %s\n", i, argsFg[i]);

		free(argsFg[i]);
		argsFg[i] = NULL;
	}

	printf("--------------------------------------------\n");

	for(int i = 0; argsBg[i]; i ++){
		printf("argsBg[%d] = %s\n", i, argsBg[i]);

		free(argsBg[i]);
		argsBg[i] = NULL;
	}


	printf("\n");
	printf("argsFg[0] = %s\n", argsFg[0]);
	printf("argsBg[0] = %s\n", argsBg[0]);


	printf("DONE\n");

#endif

	return 0;
}
