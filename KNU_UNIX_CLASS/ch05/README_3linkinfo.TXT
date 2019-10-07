[print stat & lstat info about ordinary file, hard link and symbolic link]

$ ln unix.txt unix.ln
$ ln -s unix.txt unix.sym
$ ls -l unix.*
...
... unix.ln
... unix.sym
... unix.txt
...
$ gcc 3linkinfo.c
$ a.out unix.txt unix.ln unix.sym
1. stat: unix.txt ---
unix.txt: Link count = 2
unix.txt: i-node = 633179
2. stat: unix.ln ---
unix.ln: Link count = 2
unix.ln: i-node = 633179
3. stat: unix.sym ---
unix.sym: Link count = 1
unix.sym: i-node = 633192

