
<5.1 file type: ftype.c>
$ gcc ftype.c
$ a.out ./a.out
./a.out: 일반 파일
$ a.out ..
..: 디렉토리
$ a.out ~shcho
/home/shcho: 디렉토리
$ a.out /bin
/bin: 심볼릭 링크
$ ls -l /bin
lrwxrwxrwx   1 root     root           9 2016년  2월  3일 /bin -> ./usr/bin
$ a.out /usr/bin
/usr/bin: 디렉토리

<5.2 file permission: fchmod.c>
$ touch you.txt 
$ ls -l you.txt
-rw-rw-r-- 1 shcho prof 0 10월 30 21:40 you.txt
$ gcc fchmod.c
$ a.out 611 you.txt
$ ls -l you.txt
-rw---x--x 1 shcho prof 0 10월 30 21:40 you.txt

<5.3 change of file access/mod time: cptime.c>
$ touch you_new.txt 
$ ls -l *txt
-rw---x--x 1 shcho prof 0 10월 30 21:40 you.txt
-rw-r--r-- 1 shcho prof 0 11월 23 10:48 you_new.txt
$ gcc cptime.c
$ a.out you.txt you_new.txt
        actime: 1477831220
        modtime: 1477831220
$ ls -l *txt
-rw-rw-r-- 1 shcho prof 0 10월 30 21:40 you.txt
-rw-rw-r-- 1 shcho prof 0 10월 30 21:40 you_new.txt


