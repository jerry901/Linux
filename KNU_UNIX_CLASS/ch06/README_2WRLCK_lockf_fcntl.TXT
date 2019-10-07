<collision between two WRLCKs via lockf>
 - open two terminals

1)<wrlockf#1>
[shcho@localhost ch06]$ gcc -o wrlockf wrlockf.c 
[shcho@localhost ch06]$ wrlockf test.db

수정할 학생의 학번 입력:1401003
이름:Lee         학번:1401003    점수:75
새로운 점수:

2)<wrlockf#2>
[shcho@localhost ch06]$ wrlockf test.db

수정할 학생의 학번 입력:1401003

3)<wrlockf#1>
새로운 점수: 77

수정할 학생의 학번 입력:1401006
이름:Park        학번:1401006     점수:68
새로운 점수: 70

4)<wrlockf#2>
이름:Lee         학번:1401003    점수:77
새로운 점수: 79

수정할 학생의 학번 입력:1401002
이름:Kim         학번:1401002     점수:80
새로운 점수: 82

수정할 학생의 학번 입력:q

5)<wrlockf#1>
검색할 학생의 학번 입력:quit

 - repeat the lab above with fcntl(wrlock.c)
[shcho@localhost ch06]$ gcc -o wrlock wrlock.c 

