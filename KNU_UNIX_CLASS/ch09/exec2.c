#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* 세 개의 자식 프로세스를 생성하여 각각 다른 명령어를 실행한다. */
int main( ) 
{	
	int ppid, pid1, pid2, pid3, child, status;
	ppid = getpid();
    printf("부모 프로세스 시작\n");
    if ((pid1 = fork( )) == 0) {
		 waitpid(ppid, &status, 0);
	     execl("/bin/echo", "echo", "hello", NULL);
	     fprintf(stderr,"첫 번째 실패");    
         exit(1);
	 }

	 if ((pid2 = fork( )) == 0) {
		 waitpid(pid1, &status, 1);
	     execl("/bin/date", "date", NULL);
	     fprintf(stderr,"두 번째 실패");   
         exit(2);
	 }

	 if ((pid3 = fork( )) == 0) {
		 waitpid(pid1, &status, 1);
		 waitpid(pid2, &status, 2);
	     execl("/bin/ls","ls", "-l", NULL);
	     fprintf(stderr,"세 번째 실패");  
         exit(3);
     }
     printf("부모 프로세스 끝\n");
	 exit(0);
}
