[execvp]
int execvp(const char *file, char *const argv[]);
 - file: pointer to a file to be executed
 - The value in argv[0] should point to a filename
that is  associated  with the process
being started by one of the exec functions.

=========================
[execvp with arguments]
-bash-3.2$ gcc 23_20.c
-bash-3.2$ a.out ps -a
Running ps with execvp
   PID TTY         TIME CMD
 16425 pts/15      0:00 ps
  8805 pts/45      0:00 passwd
 16397 pts/13      0:00 vi
-bash-3.2$ a.out ls -a -l
Running ls with execvp
총 146
drwxr-xr-x   2 shcho    prof         512 11월  2일  14:00 .
drwxr-xr-x   6 shcho    prof         512  4월 10일  00:48 ..
-rwxr-xr-x   1 shcho    prof        6560 2015년  9월 16일 23_20
-rw-r--r--   1 shcho    prof         660  4월 10일  00:57 23_20.c

