[11.3 signal()]
$ gcc sigint1.c
$ a.out
^Cinterrupt signal processed
signal no: 2

$ gcc sigint1_DFL.c
$ a.out
^C
$

$ gcc sigint1_Ctl+Z.c
$ a.out
^ZSIGSTP signal processed
signal no: 24
$ a.out
^C
$
 
[11.4 sigaction()]
$ gcc sigint2.c
$ a.out
press Ctrl-C
press Ctrl-C
press Ctrl-C
^C signal no 2
It will end if you press Ctrl-C again
press Ctrl-C
press Ctrl-C
press Ctrl-C
^C

$ gcc sigint2_Ctl+Z.c
$ a.out
press Ctrl-Z
press Ctrl-Z
press Ctrl-Z
^Zsignal no 24
It will stop if you press Ctrl-Z again
press Ctrl-Z
press Ctrl-Z
press Ctrl-Z
^Z
[1]+  Stopped                 a.out
$ ps
.....		a.out
.....
$ kill %1
$ ps
.....
$

