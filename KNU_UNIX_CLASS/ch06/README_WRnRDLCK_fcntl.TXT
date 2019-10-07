<collision between WRLCK & RDLCKI --> SETLKW>

0)<prepare>
[shcho@localhost ch06]$ gcc -o dbcreate dbcreate.c
[shcho@localhost ch06]$ dbcreate test.db
 학번 이름 점수
1401002 Kim  80
1401003 Lee  70
1401006 Park 90
[shcho@localhost ch06]$ ls -l test.db
-rw-r----- 1 shcho prof 192 11월  6 00:42 test.db

1)<wrlock>
[shcho@localhost ch06]$ gcc -o wrlock wrlock.c 
[shcho@localhost ch06]$ wrlock test.db

수정할 학생의 학번 입력:1401003   
이름:Lee         학번:1401003     점수:70
새로운 점수: // stop here without entering a score.

2)<rdlock>
[shcho@localhost ch06]$ gcc -o rdlock rdlock.c 
[shcho@localhost ch06]$ rdlock test.db

검색할 학생의 학번 입력:1401002   // go forward 
이름:Kim         학번:1401002     점수:80

검색할 학생의 학번 입력:1401003	// stop here due to WRLOCK

3)<wrlock>
// enter a score: still in WRLOCK.
이름:Lee         학번:1401003    점수:70
새로운 점수: 75

4)<rdlock>
// because the other unlocked WRLCK, this gets RDLCK, then read a record. 
이름:Lee         학번:1401003    점수:75
// you can see the correct result.

