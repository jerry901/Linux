#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAXARG 7
    
static const char delim[] = "&; \t\n"; /* 공백, 탭, 개행으로 이루어진 구분자 선언 */

void tok_1(char *pBuf, const char *pDel, char **pArg);

int main()
{
    char buf[256];
    char *args[MAXARG];
    int argn;
    int pid, status;

    while(1) {  			/* 무한 반복 */
       printf("[shell] ");		/* 프롬프트 출력 */
       fgets(buf, sizeof(buf), stdin);

       argn = 0;
	   tok_1(buf, delim, args);
       
       if (!strcmp(args[0], "quit")) 	/* 프롬프트로 입력받은 단어가‘quit’이면 while 문 벗어남 */
           break;

       if ((pid=fork()) == -1)      	/* fork 호출에 실패하면 */
          perror("fork failed");
       else if (pid != 0) {         	/* 부모 프로세스는 자식 프로세스가 종료되기를 기다림 */
          pid = wait(&status);
       
       } else {                     	/* 자식 프로세스는 execvp를 이용하여 arg[0] 실행 */
          execvp(args[0], args);
		  printf("execvp(): FAILED!!");
		  exit(0);
       }
    }
    exit(0);
}
