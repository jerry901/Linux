#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

#define MAX_ARGS 10 
#define MAX_COMMANDS 10
#define MAX_BUF 512

#define CHAR_AND 38				// Integer value for char '&'
#define CHAR_SEMI_COLON 59		// Integer value for char ';' 

int main()
{
	static const char delim[] = " \t\n"; // 공백, 탭, 개행으로 이루어진 구분자 선언
	static const char DELIM_AND = '&';
	static const char DELIM_SEMI_COLON = ';';

	int pidFg, pidBg, status;

	while(1) {  			
		char buf[MAX_BUF] = {0};
		fflush(stdin);

		char *ptr = NULL;
		char *cmdFg[MAX_COMMANDS] = {0};
		char *cmdBg[MAX_COMMANDS] = {0};

		int indexBg = 0;
		int indexFg = 0;
		int length = 0;

		sleep(0);
		printf("[shell] ");		
		fgets(buf, sizeof(buf), stdin);
		ptr = buf;

		for(int curIndex = 0, fromIndex = 0; curIndex < (int)strlen(buf) ; curIndex++){

			for(int i = 0;  ; i++){ //첫부분에 공백이 존재하면 공백을 건너 뜀
				if(ptr[i] == ' ' || ptr[i] == '\t' ){
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
					length = curIndex - fromIndex;
					cmdFg[indexFg] = (char *)malloc((length)*sizeof(char));
					ptr = procSort(cmdFg[indexFg++], ptr, DELIM_SEMI_COLON, length);
					fromIndex = curIndex + 1;
					break;

				case CHAR_AND :
					length = curIndex - fromIndex;
					cmdBg[indexBg] = (char *)malloc((length)*sizeof(char));
					ptr = procSort(cmdBg[indexBg++], ptr, DELIM_AND, length);
					fromIndex = curIndex + 1;
					break;

				default:
					if(curIndex == (int)strlen(buf)-1 && (ptr != &buf[curIndex])){
						length = curIndex - fromIndex;
						cmdFg[indexFg] = (char *)malloc(length*sizeof(char));
						strncpy(cmdFg[indexFg], ptr, length);
						cmdFg[indexFg][length] = '\0';

						for (int i = length - 1; ; i--) {
							if(cmdFg[indexFg][i] == ' ' || cmdFg[indexFg][i] == '\t' )
								cmdFg[indexFg][i] = '\0';
							else
								break;
						}
						indexFg++;
						ptr = NULL;
					}
					break;
			}
		}

		cmdFg[indexFg] = (char *)0; // 인수가 더이상 없음을 의미
		cmdBg[indexBg] = (char *)0;

		/** printf("cmdFg[0] = %s\n",cmdFg[0]); */
		/** printf("cmdBg[0] = %s\n",cmdBg[0]); */

		if(cmdFg[0]){
			if(!strcmp(cmdFg[0], "shell")){
				printf("!ERROR(0) : shell program is already running..\n");
				continue;
			}
			else if(!strcmp(cmdFg[0], "quit")){
				break;
			}
		}

		if(cmdBg[0]){
			if(!strcmp(cmdBg[0], "shell")){
				printf("!ERROR(0) : shell program is already running..\n");
				continue;
			}
			else if(!strcmp(cmdBg[0], "quit")){
				break;
			}
		}

/************ fork 함수가 들어와야 할 곳 ***********/
		if(cmdBg[0]){
			pidBg = fork();
		}

		if(pidBg == 0) { //BackGround
			/** printf("pidBg forked\n"); */
			for (int i = 0; i < indexBg; i++) {
				char *args[MAX_ARGS] = {0};
				argTok(cmdBg[i], args, delim);
				exBg(args);
			}
			exit(0);
		}

		if(cmdFg[0]){
			pidFg = fork();
		}	

		if(pidFg != 0){
			wait(&status);
		}
		else if (pidFg == 0 && pidBg != 0) { //ForeGround
			for (int i = 0; i < indexFg; i++) {
				/** printf("pidFg forked\n"); */
				char *args[MAX_ARGS] = {0};
				argTok(cmdFg[i], args, delim);
				exFg(args);
			}
			exit(0);
		}
/**************************************************/
		for (int i = 0; cmdFg[i]; ++i) {
			/** printf("argsFg[%d] = %s\n", i, cmdFg[i]); */
			cmdFg[i][0] = '\0';
			free(cmdFg[i]);
			cmdFg[i] = NULL;
		}
		for (int i = 0; cmdBg[i]; ++i) {
			/** printf("argsBg[%d] = %s\n", i, cmdBg[i]);  */
			cmdBg[i][0] = '\0';
			free(cmdBg[i]);
			cmdBg[i] = NULL;
		}

			/** printf("cmdFg[0] = %s\n",cmdFg[0]); */
			/** printf("cmdBg[0] = %s\n",cmdBg[0]); */
	}

    exit(0);

}

