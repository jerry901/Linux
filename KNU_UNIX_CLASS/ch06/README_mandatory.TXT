
1)mandatory locking
[terminal #1]
$ cat mandatory.txt
hello
$ ls -l mandatory.txt
-rw-r--r-- 1 shcho happySchool 27 11월  6 21:39 mandatory.txt
$ chmod 2644 mandatory.txt
$ ls -l mandatory.txt
-rw-r-lr-- 1 shcho happySchool 27 11월  6 21:39 mandatory.txt
$ gcc -o file_lock file_lock.c
$ file_lock mandatory.txt
<강제 잠금됨>
$

[terminal #2]
-bash-3.2$ ls >> mandatory.txt
-bash: mandatory.txt: 일시적으로 사용가능한 자원이 없음
<강제 잠금되어 거부됨>
...

[terminal #1]
<after interrupting a file_lock, that is, terminating mandatory locking>
$ file_lock mandatory.txt
^C
$

[terminal #2]
<강제 잠금 해제됨>
$ ls >> mandatory.txt
$ cat mandatory.txt
hello
README_2WRLCK_lockf_fcntl.TXT
README_WRnRDLCK_fcntl.TXT
...


2)advisory locking
[terminal #1]
$ cat > advisory.txt
Good morning!
^D
$ cat advisoty.txt
Good morning!
$ gcc -o file_lock file_lock.c
$ file_lock advisoty.txt

[terminal #2]
<Though a process locks advisory.txt, another process can disregard it.>
-bash-3.2$ ls >> advisory.txt
-bash-3.2$ cat advisory.txt
Good morning!
advisory.txt
a.out
ch06.tar
dbcreate
dbcreate.c
file_lock.c
mandatory.txt
...


