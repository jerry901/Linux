#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int exBg(char *args[]) //foreground jobs를 실헹할 함수 test  이후에는 char *jobs[]를 추가해줄것
{
	int pid, status;
	int isWaiter = 0;

	if ((pid = fork()) == -1) {
		printf("fork failed\n");
		return -1;
	}

	/** if(pid != 0){ */
	/**     printf("[1] %d\n", pid); */
	/**     [> pid = wait(&status); <] */
	/** } */
	/** else if(pid == 0) */
	/** { */
	/**     [> printf("pid : %d\n", *pid); <] */
	/**     execvp(args[0], args); */
	/**     printf("execvp(): FAILED!!\n"); */
	/** } */


	if(pid == 0){ //첫번 째 자식 프로세스는 fork를 시행하고 wait 한다.
		isWaiter = 1;
		pid = fork();

		if(isWaiter == 1 && pid != 0){
			pid = wait(&status);
			printf("[1] Done\n");
			exit(0);
		}
	}

	if(pid == 0) // 두번 째 자식 프로세스가 실행될 부분
	{
		/** printf("pid : %d\n", *pid); */
		/** printf("Waitr = %d\n", isWaiter); */
		printf("[1] %d\n", getpid());
		execvp(args[0], args);
		printf("execvp(): FAILED!!\n");
	}
}
