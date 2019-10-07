#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/* 프로세스 번호를 출력한다. */
int main()
{ 
	int pid;
	char *ptr;

	printf("나의 프로세스 번호 : %d \n", getpid());
	printf("내 부모 프로세스 번호 : %d \n", getppid());

//	chdir("/home/shcho/class/os/fork");
	ptr = getenv("PWD");
	printf("PWD = %s\n", ptr);
}
