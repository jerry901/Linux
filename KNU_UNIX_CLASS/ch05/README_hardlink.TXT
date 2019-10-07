[Hard link]
$ gcc link.c
$ cat > you.txt
Hello~
How are you doing?
Nice to meet you today.
See you again!
$ a.out you.txt new.txt
$ ls -l
-rw-r--r--   2 shcho    14f           65 11?? 5?? 16:33 new.txt
...
-rw-r--r--   2 shcho    14f           65 11?? 5?? 16:33 you.txt
$ cat new.txt
Hello~
How are you doing?
Nice to meet you today.
See you again!

[unlink]
$ gcc unlink.c
$ a.out new.txt
$ ls -l
...(no new.txt)
-rw-r--r--   1 shcho    14f           65 11?? 5?? 16:33 you.txt
$ a.out you.txt
$ ls
...(no you.txt)



