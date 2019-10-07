#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int status;
    if ((status = mysystem("date")) < 0)
       perror("mysystem() 오류");
    printf("종료코드 %d\n", WEXITSTATUS(status));

    if ((status = mysystem("hello")) < 0)
       perror("mysystem() 오류");
    printf("종료코드 %d\n", WEXITSTATUS(status));

    if ((status = mysystem("who; hostname; exit 44")) < 0)
       perror("mysystem() 오류");
    printf("종료코드 %d\n", WEXITSTATUS(status));
}
