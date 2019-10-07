<fork>
$ gcc fork1.c
$ a.out
[15425] 프로세스 시작
[15425] 프로세스 : 리턴값  15426
[15426] 프로세스 : 리턴값  0
$ ps
...

$ gcc fork2.c
$ a.out
[Parent] : Hello, world pid=15439
[Child] : Hello, world pid=15440

$ gcc fork3.c
$ a.out
[Child 1] : Hello, world ! pid=15466
[Child 2] : Hello, world ! pid=15467

$ gcc fork3_noexit.c
$ a.out
[Child 1] : Hello, world ! pid=27594, my parent=27593
[Child 2] : Hello, world ! pid=27595, my parent=27593
[Child 2] : Hello, world ! pid=27596, my parent=27594
$ a.out
[Child 1] : Hello, world ! pid=27639, my parent=27638
[Child 2] : Hello, world ! pid=27640, my parent=1
[Child 2] : Hello, world ! pid=27641, my parent=27639

<wait- forkwait>
$ gcc forkwait.c
$ a.out
[15547] 부모 프로세스 시작
[15548] 자식 프로세스 시작
[15547] 자식 프로세스 15548 종료
        종료 코드 1

$ gcc waitpid.c
$ a.out
[15565] 부모 프로세스 시작
[15566] 자식 프로세스 #1 시작
[15567] 자식 프로세스 #2 시작
[15566] 자식 프로세스 #1 종료
[15565] 자식 프로세스 #1 15566 종료
        종료 코드 1
[15567] 자식 프로세스 #2 종료
