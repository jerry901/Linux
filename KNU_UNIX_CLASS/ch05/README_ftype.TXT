
<5.1 file type: ftype.c>
[shcho@localhost ch05]$ gcc ftype.c
[shcho@localhost ch05]$ a.out ./a.out
./a.out: 일반 파일
[shcho@localhost ch05]$ a.out ..
..: 디렉토리
[shcho@localhost ch05]$ a.out ~shcho
/home/shcho: 디렉토리
-bash-3.2$ a.out /bin
/bin: 심볼릭 링크
-bash-3.2$ ls -l / | grep /bin
lrwxrwxrwx   1 root     root           9 2016년  2월  3일 /bin -> ./usr/bin
-bash-3.2$ a.out /usr/bin
/usr/bin: 디렉토리

<5.2 file permission: fchmod.c>
[shcho@localhost ch05]$ touch you.txt 
[shcho@localhost ch05]$ ls -l you.txt
-rw-rw-r-- 1 shcho prof 0 10월 30 21:40 you.txt
[shcho@localhost ch05]$ gcc fchmod.c
[shcho@localhost ch05]$ a.out 611 you.txt
[shcho@localhost ch05]$ ls -l you.txt
-rw---x--x 1 shcho prof 0 10월 30 21:40 you.txt

<5.3 change of file access/mod time: cptime.c>
[shcho@localhost ch05]$ touch you_new.txt 
[shcho@localhost ch05]$ ls -l *txt
-rw---x--x 1 shcho prof 0 10월 30 21:40 you.txt
-rw-r--r-- 1 shcho prof 0 11월 23 10:48 you_new.txt
[shcho@localhost ch05]$ gcc cptime.c
[shcho@localhost ch05]$ a.out you.txt you_new.txt
        st_atime: 1477831220
        st_mtime: 1477831220
[shcho@localhost ch05]$ ls -l *txt
-rw-rw-r-- 1 shcho prof 0 10월 30 21:40 you.txt
-rw-rw-r-- 1 shcho prof 0 10월 30 21:40 you_new.txt


