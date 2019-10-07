<pid.c>
$ gcc pid.c
$ a.out
나의 프로세스 번호 : 14437
내 부모 프로세스 번호 : 13680
$ ps
  PID TTY          TIME CMD
13680 pts/12   00:00:00 bash
14599 pts/12   00:00:00 ps

$ gcc uid.c
$ a.out
나의 실제 사용자 ID : 1001(shcho)
나의 유효 사용자 ID : 1001(shcho)
나의 실제 그룹 ID : 100(prof)
나의 유효 그룹 ID : 100(prof)
$ cat /etc/passwd | grep shcho
shcho:x:1011:1011:,,,:/home/shcho:/bin/bash
$ ls -l /etc/passwd
-rw-r--r--   1 root     sys        12143  9월 10일  14:50 /etc/passwd
$ ls -asl /bin/passwd
  54 -r-sr-sr-x   1 root     sys        27284 2012년  6월 13일 /bin/passwd

