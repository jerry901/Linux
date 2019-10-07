File information by stat

[regular file: a text file- mode value]
$ gcc statinfo.c
$ a.out you.txt
Inode = 294207
Mode = 100664
Nlink = 2
UID = 1001
GID = 100
SIZE = 26
Atime = 1493641435
Mtime = 1478482926
Ctime = 1493641471
Blksize = 8192
Blocks = 2
FStype = ufs

[regular file: an executable file(a.out)- mode value]
$ a.out a.out
Inode = 294187
Mode = 100755
Nlink = 2
UID = 1001
GID = 100
SIZE = 6780
Atime = 1493641863
Mtime = 1493641780
Ctime = 1493641780
Blksize = 8192
Blocks = 14
FStype = ufs


