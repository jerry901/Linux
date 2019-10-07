/* runls3 -- run ls in a subprocess */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

main()
{
	int pid;
	printf("(a.out)process id: %d, parent pid(bash): %d\n", getpid(), getppid());
	pid = fork();

	/* code for parent process */
	if (pid > 0 ) {
	  wait((int *)0);  /* wait for completion of child process */
	  printf("\n(a.out)process id: %d, parent pid(bash): %d, child terminated\n", getpid(), getppid());
	  exit(0);
	}

	/* code for child process */
	if (pid == 0) {
	  printf("(a.out's child)process id: %d, parent pid(a.out): %d\n", getpid(), getppid());
	  execl("/bin/ps","ps","-a",(char *)0);	/* doesn't return here */
	  fatal("execl failed");
	}

	/* error occurs */
	fatal("fork failed");
}
fatal(char *s)
{
	perror(s);
	exit(1);
}
