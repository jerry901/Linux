<execl: "ls","-a">
-bash-3.2$ gcc runls3.c
-bash-3.2$ a.out
process id of a.out= 16157, parent of a.out=15056
(parent)returned pid=16158
(child)returned pid: 0, child's pid=16158, parent's pid: 16157
.                   execl_args_v2.c     newproc-win32.c     runps.c
..                  fork.c              project             runps.out
a.out               global-var          README.TXT          runpwd.c
clientserver_chap3  myshell             runls3.c
execl_args_v1.c     newproc-posix.c     runls3.out
(parent)process id: 16157, completed

<execl: "ps", "-a">
-bash-3.2$ gcc runps.c
-bash-3.2$ a.out
(a.out)process id: 16262, parent pid(bash): 15056
(a.out's child)process id: 16263, parent pid(a.out): 16262
   PID TTY         TIME CMD
 16262 pts/15      0:00 a.out
 16263 pts/15      0:00 ps
  8805 pts/45      0:00 passwd
 16196 pts/13      0:00 vi

(a.out)process id: 16262, parent pid(bash): 15056, child terminated

<execl: "pwd">
-bash-3.2$ gcc runpwd.c
-bash-3.2$ a.out
process id of a.out= 16325, parent of a.out=15056
(parent)returned pid=16326
(child)returned pid: 0, child's pid=16326, parent's pid: 16325
/home/shcho/class/os/fork
(parent)process id: 16325, completed

