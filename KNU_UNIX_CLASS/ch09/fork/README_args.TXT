
-bash-3.2$ gcc execl_args1.c
-bash-3.2$ a.out ls
execl failed: No such file or directory
-bash-3.2$ a.out /bin/ls
a.out               myshell             README.TXT          runps.out
execl_args1.c       newproc-posix.c     README_windows.TXT  runpwd.c
...

-bash-3.2$ gcc execl_args2.c
-bash-3.2$ a.out ls -l
bas failed: No such file or directory
-3.2$ a.out /bin/ls -l
총 50
-rwxr-xr-x   1 shcho    prof        6760  9월 18일  23:54 a.out
-rw-r--r--   1 shcho    prof         451 2002년  4월 30일 execl_args1.c
...
-3.2$ a.out /bin/ls -a
...

