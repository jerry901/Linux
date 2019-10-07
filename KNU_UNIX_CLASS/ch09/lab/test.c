#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int exFg(int *pid, int *status) //foreground jobs를 실헹할 함수 test  이후에는 char *jobs[]를 추가해줄것
{
	printf("test 함수.\n");

	for(int i = 1; i < 4; i++){

		if ((*pid = fork()) == -1) {
			printf("fork failed\n");
			return -1;
		}
		else if (*pid != 0) {
			printf("ppid : %d\n", *pid);
			*pid = wait(status);	
		}
		else
		{
			printf("pid : %d\n", *pid);
			printf("%d 번째 ls\n", i);
			execl("/bin/ls","ls", "-al", 0); //execl 매개 변수로서 jobs[] 배열들을 받는다.
			exit(0);
		}

	}

	printf("DONE!!\n");
	return 0;
}
