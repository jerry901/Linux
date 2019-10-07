[directory entry: list1.c]
$ gcc list1.c
$ a.out
myshell
list_size_name.c
.
you.txt
you_new.txt
...
$ a.out .
<list of current directory>
$ a.out ..
<list of parent directory>

[# of blocks/file size/entry name: list_size_name.c]
$ gcc list_size_name.c
$ a.out .
blocks size entry
    8  4096 myshell
    8   878 list_size_name.c
    8  4096 .
    0     0 you.txt
    0     0 you_new.txt
...
    8   703 list1.c
   24  8916 cptime

[ls -l: list2.c]
$ gcc list2.c
$ a.out .
    2 drwxr-xr-x   2 shcho other      1024 May  2 00:00 .
    2 drwxr-xr-x  13 shcho other       512 Jun 12 23:09 ..
   18 -rwxr-xr-x   2 shcho other      8664 Dec 17 21:41 ftype
   ...

[list3.c]
$ gcc list3.c
$ a.out
 1024 .
  512 ..
 7128 ftype
  ...
