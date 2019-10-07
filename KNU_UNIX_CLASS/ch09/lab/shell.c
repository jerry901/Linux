#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

#define MAXARG 7

int main()
{
	char buf[256];
	char *args[MAXARG];
	static const char delim[] = " \t\n"; /* 공백, 탭, 개행으로 이루어진 구분자 선언 */
	/** static const char AND[] = "&"; */
	/** static const char SEMI_COLON[] = ";"; */

	int pid, status;

	while(1) {  			
		printf("[shell] ");		
		fgets(buf, sizeof(buf), stdin);

		if((argTok(buf, args, delim)) == -1)
			continue;

		if(!strcmp(args[0], "shell")){
			printf("!ERROR(0) : shell program is already running..\n");
			continue;
		}
		else if (!strcmp(args[0], "quit")) 	/* 프롬프트로 입력받은 단어가‘quit’이면 while 문 벗어남 */
			break;

		exFg(args);

    }

    exit(0);
}

