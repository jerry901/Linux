#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int exFg(char *args[]) //foreground jobs를 실헹할 함수 test  이후에는 char *jobs[]를 추가해줄것
{
	int pid, status;

	if ((pid = fork()) == -1) {
		printf("fork failed\n");
		return -1;
	}
	else if (pid != 0) {
		/** printf("ppid : %d\n", *pid); */
		pid = wait(&status);	
	}
	else
	{
		/** printf("pid : %d\n", *pid); */

		execvp(args[0], args);
		printf("execvp(): FAILED!!\n");
		exit(0);
	}

	return 0;
}
