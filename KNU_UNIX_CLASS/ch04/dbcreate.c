dbcreate2.c                                                                                         0000644 0012010 0000001 00000001417 13444037071 0013522 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student2.h"

/* 학생 정보를 입력받아 데이터베이스 파일에 저장한다. */
int main(int argc, char *argv[])
{
    int fd;
    struct student rec;

    if (argc < 2) {
        fprintf(stderr,  "사용법 : %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1],O_WRONLY |O_CREAT, 0640))==-1) {
        perror(argv[1]);
        exit(2);
    }

    printf("%-9s %-8s %-4s", "학번",  "이름",  "점수"); 
    while (scanf("%d %s %d", &rec.id, rec.name, &rec.score) ==  3) {
        lseek(fd, (rec.id - START_ID) * sizeof(rec), SEEK_SET);
        write(fd, &rec, sizeof(rec) );
    }
    printf("record size= %d\n", sizeof(rec));

    close(fd);
    exit(0);
}
                                                                                                                                                                                                                                                 dbquery.c                                                                                           0000644 0012010 0000001 00000002103 13444037071 0013333 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* 학번을 입력받아 해당 학생의 레코드를 파일에서 읽어 출력한다. */
int main(int argc, char *argv[])
{
    int fd, id;
    char c;
    struct student rec;

   if (argc < 2) {
        fprintf(stderr,  "사용법 : %s file\n", argv[0]);
        exit(1);
   }

   if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("\n검색할 학생의 학번 입력:");
        if (scanf("%d", &id) == 1) {
            lseek(fd, (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) 
                printf("학번:%d\t 이름:%s\t 점수:%d\n", 
                        rec.id, rec.name, rec.score);
            else printf("검색할 레코드 %d 없음, rec.id=%d\n", id, rec.id);
        }
        else printf("입력 오류"); 

        printf("계속하겠습니까?(Y/N)");
        scanf(" %c", &c);
    } while (c == 'Y');
   
    close(fd);
    exit(0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                             dbupdate.c                                                                                          0000644 0012010 0000001 00000002325 13444060423 0013453 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* 학번을 입력받아 해당 학생 레코드를 수정한다. */
int main(int argc, char *argv[])
{
    int fd, id;
    char c;
    struct student rec;

    if (argc < 2) {
        fprintf(stderr,  "사용법 : %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("수정할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1) {
            lseek(fd,  (long) (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) {
                printf("학번:%8d\t 이름:%4s\t 점수:%4d\n", 
                       rec.id, rec.name, rec.score);
	        printf("새로운 점수: ");
	        scanf("%d", &rec.score);
                lseek(fd, (long) -sizeof(rec), SEEK_CUR);
                write(fd, &rec, sizeof(rec));
            }
            else printf("레코드 %d 없음\n", id);
        }
        else printf("입력오류\n");
        printf("계속하겠습니까?(Y/N)");
        scanf(" %c",&c);
    } while (c == 'Y');

    close(fd);
    exit(0);
}

                                                                                                                                                                                                                                                                                                           student.h                                                                                           0000644 0012010 0000001 00000000151 13444037071 0013354 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        #define MAX 24
#define START_ID 1401001
struct student {
   char name[MAX];
   int id;
   int score;
};

                                                                                                                                                                                                                                                                                                                                                                                                                       student2.h                                                                                          0000644 0012010 0000001 00000000151 13444037071 0013436 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        #define MAX 24
#define START_ID 0000001
struct student {
   char name[MAX];
   int id;
   int score;
};

                                                                                                                                                                                                                                                                                                                                                                                                                       stdb1                                                                                               0000640 0012010 0000001 00000000440 13444056715 0012460 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        Tom                      `�                                   Mike                     `�   N                                                                Susan                    `�   X                                                                Derek                    `�   A                                                                                                                                                                                                                                stud.txt                                                                                            0000644 0012010 0000001 00000003206 13444037071 0013241 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        1401001 Paek1 80
1401003 Lee1 75
1401006 Kim1 54
1401009 Park1 68
1401011 Cho1 63
1401014 Kim2 56
1401015 Lee2 73
1401016 Jeong1 87
1401019 Kang1 72
1401020 Yoon1 64
1401021 Paek2 71
1401023 Lee3 54
1401026 Kim3 64
1401029 Park2 68
1401031 Cho2 53
1401034 Kim4 46
1401035 Lee4 73
1401036 Jeong2 57
1401039 Kang2 62
1401040 Yoon2 54
1401041 Paek3 82
1401043 Lee5 78
1401046 Kim5 57
1401049 Park3 63
1401051 Cho3 64
1401053 Kim6 58
1401055 Lee6 77
1401058 Jeong3 84
1401059 Kang3 78
1401060 Yoon3 65
1401062 Paek4 71
1401064 Lee7 59
1401067 Kim7 68
1401069 Park4 64
1401070 Cho4 55
1401074 Kim8 48
1401075 Lee8 73
1401076 Jeong4 59
1401078 Kang4 64
1401080 Yoon4 55
1401082 Cheon1 80
1401084 Song1 75
1401087 Kim9 54
1401089 Moon1 68
1401090 Cho5 63
1401093 Kim10 56
1401094 Lee9 73
1401096 Jeong5 87
1401098 Kang5 72
1401101 Yoon5 64
1401102 Paek5 71
1401103 Lee10 54
1401106 Kim11 64
1401108 Park5 68
1401111 Choi 53
1401113 Pi1 46
1401114 Moon2 73
1401116 Jeong6 57
1401118 Kang6 62
1401120 Yoon6 54
1401121 Paek6 72
1401124 Lee11 77
1401125 Kim12 57
1401128 Park6 63
1401131 Choi2 64
1401133 Pi2 58
1401134 Cheon2 67
1401137 Jeong7 64
1401139 Kan 78
1401140 You 65
1401142 Paek7 51
1401143 Lee12 59
1401146 Kim13 48
1401149 Park7 64
1401150 Choi3 55
1401153 Shin 58
1401154 Do 63
1401156 Jeong8 59
1401157 Kan1 64
1401160 You2 55
1401161 Paek8 62
1401164 Lee13 58
1401165 Kim14 47
1401168 Park8 63
1401171 Cho6 44
1401173 Choi4 38
1401174 You3 57
1401177 Jeong9 64
1401179 Kan2 78
1401180 Yoon7 65
1401182 Paek9 61
1401183 Lee14 59
1401186 Kang7 48
1401189 Park9 54
1401190 Cho7 35
1401193 Kim15 58
1401194 Lee15 63
1401196 Jeong10 49
1401197 Kan3 74
1401200 Yoon8 65

1401080 Yoon4 55
1401082 Cheon1 80
1401084 Song1 75
1401087 Kim9 54
1401089 Moon1 68
1401090 Cho5 63
1401093 Kim10 56
1401094 Lee9 73
1401096 Jeong5 87
1401098 Kang5 72
1401101 Yoon5 64
1401102 Paek5 71
1401103 Lee10 54
1401106 Kim11 64
1401108 Park5 68
1401111 Choi 53
1401113 Pi1 46
1401114 Moon2 73
1401116 Jeong6 57
1401118 Kang6 62
1401120 Yoon6 54
1401121 Paek6 72
140112dup.c                                                                                               0000644 0012010 0000001 00000000442 13444037071 0012454 0                                                                                                    ustar 00pkhu2000                        other                           0000040 0000040                                                                                                                                                                        #include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int  fd, fd2;

    if((fd = creat("myfile", 0600)) == -1)
        perror("myfile");

    write(fd, "Hello! Linux", 12);  
    fd2 = dup(fd);
    write(fd2, "Bye! Linux", 10);  
    exit(0); 
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              