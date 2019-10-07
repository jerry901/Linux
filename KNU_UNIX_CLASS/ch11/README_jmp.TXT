[11.7 setjmp-longjmp]
$ gcc jump1.c
$ a.out
the first call of setjmp() returns 0 and proceeds.
Error, then longjmp runs and jumps to setjmp().
setjmp() returned due to error

[11.8 signal-setjmp-longjmp]
$ gcc jump2.c
$ a.out
setjmp(): the first call:it proceeds
in infinite loop
in infinite loop
in infinite loop
^C entered Ctl+C, calls intHandler() which then calls longjmp(). It runs.
Due to longjmp() it returned to main(), then exit.

