<mini shell>
-bash-3.2$ gcc 23_23.c
-bash-3.2$ a.out
myshell$ ls
23_20              23_23_str.c        d.txt              README_execvp.TXT
23_20.c            all.tar            e.txt              README.TXT
23_23              a.out              f.txt              test.txt
23_23.c            c.txt              g.txt
myshell$ pwd
/home/shcho/class/os/fork/myshell
myshell$ cp c.txt h.txt
myshell$ cat c.txt
Hello~
This is a lab class.
myshell$ cat h.txt
Hello~
This is a lab class.
myshell$ quit
-bash-3.2$

[limits]
myshell$ date > a.txt
date: 잘못된 변환
myshell$ date | wc
date: 잘못된 변환
myshell$ cat c.txt
Hello~
This is a lab class.
myshell$ wc < c.txt
wc: <을(를) 열 수 없습니다
       2       6      28 c.txt
       2       6      28 total

