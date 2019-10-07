[kill()-kill.c]
$ gcc -o loop loop.c
$ loop &
[1] 11844
$ ps
   PID TTY         TIME CMD
 11511 syscon      0:00 bash
 11844 syscon      0:01 loop
 11848 syscon      0:00 ps
$ gcc kill.c
$ a.out 11844
$ ps
   PID TTY         TIME CMD
 11511 syscon      0:00 bash
 11846 syscon      0:00 ps
[1]+  중단됨(Killed)       loop

[11.5 alarm-kill]
$ gcc tlimit.c
$ a.out 3 sleep 10 
[parent] Parent waits for alarm signal.
[alarm] alarm is on
[parent] send child process 29334 the SIGKILL.
[parent:29332] child process 29334 killed.

