/* runls3 -- run ls in a subprocess */
main()
{
	int pid;
	printf("process id of a.out= %d, parent of a.out=%d\n", getpid(), getppid());
	pid = fork();

	/* code for parent process */
	if (pid > 0 ) {
	  printf("(parent)returned pid=%d\n", pid);
	  wait((int *)0);  /* wait for completion of child process */
	  printf("(parent)process id: %d, ls completed\n", getpid());
	  exit(0);
	}

	/* code for child process */
	if (pid == 0) {
	  printf("(child)returned pid: %d, child's pid=%d, parent's pid: %d\n", pid, getpid(), getppid());
	  execl("/bin/ls","ls","-a",(char *)0);	/* doesn't return here */
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
