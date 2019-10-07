#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

main()
{
  int pid;

  pid = fork();
  printf("%d \n", pid);
}

