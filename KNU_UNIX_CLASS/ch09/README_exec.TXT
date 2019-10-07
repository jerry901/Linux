<exec>
$ gcc exec1.c
$ a.out
부모 프로세스 시작
부모 프로세스 끝
hello

$ gcc exec2.c
$ a.out
부모 프로세스 시작
부모 프로세스 끝
2017. 04. 03. (월) 22:53:49 KST
hello
total 176
-rw-rw-r-- 1 shcho shcho   783  4월  3 22:44 '
-rw-rw-r-- 1 shcho shcho   777  4월  3 22:50 README_forkwait.TXT
...

$ gcc exec3.c
$ a.out
[15869] 자식 프로세스 15870 종료
        종료 코드 0
$ a.out ls -a
'                     a.out     forever.c   lab          pgrp2.c
.                     ch09.tar  fork1       mysyscall.c  redirect1.c
..                    exec1.c   fork1.c     mysystem.c   redirect1_nodup2.c
README_system.TXT     execute2  forkwait.c  pgrp1.c
[15893] 자식 프로세스 15894 종료
        종료 코드 0
$ a.out ps
  PID TTY          TIME CMD
13826 pts/13   00:00:00 bash
15901 pts/13   00:00:00 a.out
15902 pts/13   00:00:00 ps
[15901] 자식 프로세스 15902 종료
        종료 코드 0
$ a.out pwd
/home/shcho/class/chang/ch09
[16090] 자식 프로세스 16091 종료
        종료 코드 0
$ a.out cd ..
cd:실행 불가
[16096] 자식 프로세스 16097 종료
        종료 코드 0

