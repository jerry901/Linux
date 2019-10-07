#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

#define MAX_ARG 50 
#define MAX_BUF 512

#define CHAR_AND 38				// Integer value for char '&'
#define CHAR_SEMI_COLON 59		// Integer value for char ';' 

int main()
{
	static const char delim[] = " \t\n"; // 공백, 탭, 개행으로 이루어진 구분자 선언
	static const char DELIM_AND = '&';
	static const char DELIM_SEMI_COLON = ';';

	int pid, status;

	while(1) {  			
		char buf[MAX_BUF] = {0};
		fflush(stdin);

		char *ptr = NULL;
		char *argsFg[MAX_ARG];
		char *argsBg[MAX_ARG];

		int indexBg = 0;
		int indexFg = 0;
		int length = 0;

		printf("[shell] ");		
		fgets(buf, sizeof(buf), stdin);
		ptr = buf;

		for(int curIndex = 0, fromIndex = 0; curIndex < (int)strlen(buf) ; curIndex++){
			for(int i = 0;  ; i++){
				if(ptr[i] == ' ' || ptr[curIndex] == '\t' ){
					ptr++;
					fromIndex++;
				}
				else
					break;
			}

			switch (buf[curIndex]) {
				case CHAR_SEMI_COLON :
					/** printf("ptr = %d\n", ptr); */
					/** printf("&buf[cur] = %d\n", &buf[curIndex]); */
					argsFg[indexFg] = (char *)malloc((length)*sizeof(char));
					length = curIndex - fromIndex;
					ptr = procSort(argsFg[indexFg++], ptr, DELIM_SEMI_COLON, length);
					fromIndex = curIndex + 1;
					break;

				case CHAR_AND :
					argsBg[indexBg] = (char *)malloc((length)*sizeof(char));
					length = curIndex - fromIndex;
					ptr = procSort(argsBg[indexBg++], ptr, DELIM_AND, length);
					fromIndex = curIndex + 1;
					break;

				default:
					if(curIndex == (int)strlen(buf)-1 && (ptr != &buf[curIndex])){
						argsFg[indexFg] = (char *)malloc(length*sizeof(char));
						length = curIndex - fromIndex;
						strncpy(argsFg[indexFg], ptr, length);
						argsFg[indexFg++][length] = '\0';
						ptr = NULL;
					}
					break;
			}
		}

		argsFg[indexFg] = (char *)0;
		argsBg[indexBg] = (char *)0;

		printf("argsFg[0] = %s\n",argsFg[0]);
		printf("argsBg[0] = %s\n",argsBg[0]);

		if(argsFg[0]){
			if(!strcmp(argsFg[0], "shell")){
				printf("!ERROR(0) : shell program is already running..\n");
				continue;
			}
			else if(!strcmp(argsFg[0], "quit")){
				break;
			}
		}

		printf("누가이기나 해보자 시발아\n");

		if(argsBg[0]){
			if(!strcmp(argsBg[0], "shell")){
				printf("!ERROR(0) : shell program is already running..\n");
				continue;
			}
			else if(!strcmp(argsBg[0], "quit")){
				break;
			}
		}

		for (int i = 0; argsFg[i]; ++i) {
			printf("argsFg[%d] = %s\n", i, argsFg[i]);
			argsFg[i][0] = '\0';
			free(argsFg[i]);
			argsFg[i] = NULL;
		}
		for (int i = 0; argsBg[i]; ++i) {
			printf("argsBg[%d] = %s\n", i, argsBg[i]);
			argsBg[i][0] = '\0';
			free(argsBg[i]);
			argsBg[i] = NULL;
		}
			printf("argsFg[0] = %s\n",argsFg[0]);
			printf("argsBg[0] = %s\n",argsBg[0]);

	}
    exit(0);
}

