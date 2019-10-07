Binary file
 - block-based input/output
 - sizeof(rec)=28(20+4+4)
 - # of records=3
 - |stdb1|=28x3=84

<fwrite(&rec, sizeof(rec), 1, fp)>
$ gcc stcreate1.c
$ a.out stdb1
학번    이름  점수
1401001 박연아 96
1401003 김태완 85
1401006 김현진 88

<fread(&rec, sizeof(rec), 1, fp)>
$ gcc stprint.c
$ a.out stdb1
-----------------------------------
    학번 이름 점수
-----------------------------------
   1401001 박연아     96
   1401003 김태완     85
   1401006 김현진     88
-----------------------------------

