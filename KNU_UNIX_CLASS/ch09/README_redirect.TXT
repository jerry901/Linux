<Duplicate a file descriptor>
(1) dup2()
-bash-3.2$ gcc redirect1.c
-bash-3.2$ a.out
Hello stdout! duplicated file descriptor = -1
Hello stderr !
-bash-3.2$ a.out out.txt
Hello stderr !
-bash-3.2$ cat out.txt
Hello stdout! duplicated file descriptor = 1

(2) dup2()
$ gcc redirect2.c
$ a.out out2.txt wc redirect2.c
[15344] 자식 프로세스 15345 종료
$ cat out2.txt
 24  72 629 redirect2.c

