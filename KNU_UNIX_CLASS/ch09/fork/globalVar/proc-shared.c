#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int value = 10;

int main()
{
	pid_t pid;

	pid = fork();

	if (pid == 0) { /* child process */
	   value += 10;
	   printf("CHILD: value = %d\n", value);  /* LINE A */
	} else if (pid > 0) { /* parent process */
	   wait(NULL); 
	   printf("PARENT: value = %d\n", value);  /* LINE B */
	   exit(0);
	}
}
