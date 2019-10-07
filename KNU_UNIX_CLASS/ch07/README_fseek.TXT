$ gcc stcreate2.c
$ a.out stdb2
학번    이름  점수
1401002 Kim 90
1401004 Lee 80
1401007 Park 70

$ gcc stquery.c
$ a.out stdb2
검색할 학생의 학번 입력: 1401002
학번:  1401002 이름:  Kim 점수:   90
계속하겠습니까?(Y/N)Y
검색할 학생의 학번 입력: 1401003
레코드 1401003 없음
계속하겠습니까?(Y/N)N

$ gcc stupdate.c
$ a.out stdb2
수정할 학생의 학번 입력: 1401002
학번:  1401002 이름:  Kim 점수:   90
새로운 점수 입력: 85
계속하겠습니까?(Y/N)N

$ gcc stquery.c
$ a.out stdb2
검색할 학생의 학번 입력: 1401002
학번:  1401002 이름:  Kim 점수:   85
계속하겠습니까?(Y/N)N
$

