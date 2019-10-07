[create a file for storing a student record]
$ gcc -o dbcreate dbcreate.c
$ dbcreate stdb1
...
...
^D
record = 32
$ ls -l stdb1
...... 288 stdb1
$ cat stdb1
...

[create a file via I/O redirection]
$ gcc -o dbcreate_rev1 dbcreate_rev1.c
$ dbcreate_rev1 < stdb.ini
$ ls
... stdb.out
$ cat stdb.out
...

- dbcreateSeq: stores a record as it arrives.

