
<system()>
(1)use a system call in Unix-system()
$ gcc syscall.c
$ a.out
2017년 4월  9일 일요일 오후 10시 53분 41초
종료코드 0
sh: hello: 없음
종료코드 1
root       console       4월  4일  10:57
shcho      pts/1         4월  4일  11:46 (223.194.115.200)
shcho      pts/13        4월  9일  22:52 (14.52.156.109)
nolia.kangnam.ac.kr
종료코드 44

(2)use a 'mysystem' function in a file-mysystem()
$ gcc mysyscall.c mysystem.c
$ a.out
2017년 4월  9일 일요일 오후 10시 58분 49초
종료코드 0
sh: hello: 없음
종료코드 1
root       console       4월  4일  10:57
shcho      pts/1         4월  4일  11:46 (223.194.115.200)
shcho      pts/15        4월  9일  22:54 (14.52.156.109)
shcho      pts/13        4월  9일  22:52 (14.52.156.109)
nolia.kangnam.ac.kr
종료코드 44

