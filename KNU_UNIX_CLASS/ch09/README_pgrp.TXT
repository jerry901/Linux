<process group>
<pgrp1.c>
$ gcc pgrp1.c
$ a.out
PARENT: PID = 15556 GID = 15556
CHILD: PID = 15557 GID = 15556

<pgrp2.c>
$ gcc pgrp2.c
$ a.out
PARENT: PID = 22067  GID = 22067
CHILD: PID = 22068  GID = 22068

