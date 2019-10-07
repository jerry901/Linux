#include <stdio.h>
#include <string.h>   /* strlen 함수가 정의된 헤더 파일 */
#define MAX 20

main()
{
   char str[MAX];
   int i, j, ch;

   printf("Input string ==> ");
   /* 문자열을 입력 받음 */
   scanf("%s", str);

   /* 첫 번째 문자와 마지막 문자를 교환하고, 두 번째 문자와 마지막에서 
      두 번째 문자와 교환, ... 결국 문자열이 거꾸로 변환 */
   for (i=0, j=strlen(str)-1; i<j; i++, j--) {
      ch = str[i];
      str[i] = str[j];
      str[j] = ch;
   }
   printf("reverse : %s\n", str);
}

