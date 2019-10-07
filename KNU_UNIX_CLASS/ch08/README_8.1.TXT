
<sequential group of processes>
$ date; hostname; uname
2017년 9월 24일 일요일 오후 09시 58분 23초
nolia.kangnam.ac.kr
SunOS

$ date; hostname; uname > a.txt
2017년 9월 24일 일요일 오후 10시 01분 12초
nolia.kangnam.ac.kr
$ cat a.txt
SunOS

$ (date; hostname; uname) > b.txt
$ cat b.txt
2017년 9월 24일 일요일 오후 10시 02분 12초
nolia.kangnam.ac.kr
SunOS

