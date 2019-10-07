/* shv2 -- handle one option */
main(int argc, char *argv[])
{
	int pid;
	pid = fork();

	/* code for parent process */
	if (pid > 0 ) {
	  wait((int *)0);  /* wait for completion of child process */
	  exit(0);
	}

	/* code for child process */
	if (pid == 0) {
	  execl(argv[1], argv[1], argv[2], (char *)0);	/* doesn't return here */
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
