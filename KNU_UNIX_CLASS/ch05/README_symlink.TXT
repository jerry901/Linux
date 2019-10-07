[soft link: ccc --> /usr/local/bin/gcc]

$ gcc slink.c
$ a.out /usr/local/bin/gcc ccc
$ ln -s /usr/local/bin/gcc ddd 
$ ls -l ccc ddd
lrwxrwxrwx   1 shcho    14f           18 11?? 5?? 18:16 ccc -> /usr/local/bin/gcc
$ ccc -o rlink rlink.c
$ ls
...	rlink  ... 
...
$ ls -l rlink
-rwxr-xr-x   1 shcho    14f         6600 11?? 5?? 18:16 rlink

[read symbolic link]
$ rlink ccc
/usr/local/bin/gcc$

[size of symbolic link]
$ gcc 22_18.c
$ a.out a.out 22_18
6808 bytes : 5 bytes

