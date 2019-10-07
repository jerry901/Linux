$ gcc fopen.c
$ a.out fopen.c
파일 fopen.c 열기 성공
fd = 3

$ gcc fsize.c
$ a.out fsize.c
512
108
fsize.c 파일 크기 : 620 바이트

$ gcc fcopy.c
$ a.out fcopy.c fcopy2.c
$ ls -l fco*
-rw-r--r--   1 shcho    prof         583  9월 16일  21:18 fcopy2.c
-rw-r--r--   1 shcho    prof         583 2016년  9월  6일 fcopy.c
$ diff fcopy.c fcopy2.c

$ gcc dup.c
$ a.out
$ cat myfile
Hello! LinuxBye! Linux

