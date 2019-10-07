[11.6 kill(... SIGSTOP), kill(.. SIGCONT)]
$ gcc control.c
$ a.out
child[1] runs: 1
child[2] runs: 1
child[2] runs: 2
child[2] runs: 3
child[1] runs: 2
child[2] runs: 4
child[1] runs: 3
child[2] runs: 5
child[1] runs: 4
child[1] runs: 5
child[2] runs: 6
child[1] runs: 6
child[2] runs: 7
child[1] runs: 7

<STOP/CONT handler>
-bash-3.2$ gcc control_rev1.c
-bash-3.2$ a.out
child[2] runs: 1
child[1] runs: 1
child[2] runs: 2
child[2] runs: 3
[CONT] child process 18798 continues
child[1] runs: 2
child[2] runs: 4
child[1] runs: 3
child[2] runs: 5
child[1] runs: 4
child[1] runs: 5
[CONT] child process 18799 continues
child[2] runs: 6
child[1] runs: 6
...
child[2] runs: 10
child[1] runs: 10

