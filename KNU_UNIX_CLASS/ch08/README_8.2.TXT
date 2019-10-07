<args.c>
$ gcc args.c
$ a.out -a -l a.txt
argv[0]: a.out
argv[1]: -a
argv[2]: -l
argv[3]: a.txt

<environ.c>
$ gcc environ.c
$ a.out
XDG_SESSION_ID=74
TERM=xterm
SHELL=/bin/bash
SSH_CLIENT=14.52.156.109 56479 22
SSH_TTY=/dev/pts/12
USER=shcho
...
MAIL=/var/mail/shcho
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:.
...

<printenv.c>
$ a.out printenv.c
$ a.out
HOME = /home/shcho
SHELL = /bin/bash
PATH = /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:.

