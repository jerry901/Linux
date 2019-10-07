#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** #define DEBUG */

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("USAGE : %s \"String\"\n", argv[0]);
		return 0;
	}

	char *p = argv[1];

	char *alphas[50] = {0};
	int nums[50];

	int wordLen = 0;
	int numLen = 0;

	int n;
	for(n = 0 ; 'A'<= *p && *p <= 'Z'; n++, p++){
		alphas[n] = (char *)malloc(2*sizeof(char));
		strncpy(alphas[n], p, 1);
		wordLen++;
		if('a' <= *(p+1) && *(p+1) <= 'z'){
			strncat(alphas[n], ++p, 1);
			wordLen++;
			continue;
		}
	}
	alphas[n] = (char *)0;

	int j;
	for(j = 0 ; 1 <= *p-'0' && *p-'0' <= 9; p++, j++){
		if(2 <= *p-'0' && *p-'0' <= 9){
			nums[j] = *p-'0';
			numLen++;
		}
		else if(*p-'0' == 1){
			if(*(p+1)-'0' == 0){
				nums[j] = 10;
				numLen+=2;
				p++;
				continue;
			}
			else{
				nums[j] = 1;
				numLen++;
			}
		}
	}
	nums[j] = 0;

	if(wordLen != numLen || n != j){
		printf("error\n");
		return 0;
	}

	printf("Chemistry equation :");
	for(int i = 0; i < n; i++){

		printf("%s", alphas[i]);

		if(nums[i]!=1)
			printf("%d", nums[i]);
	}
	printf("\n");

#ifdef DEBUG
	printf("NUMS : ");
	for(int i = 0; nums[i] != 0; i++){
		printf("%d, ", nums[i]);
	}
	printf("\n");

	printf("LENGTH : %d\n", numLen + wordLen);
	printf("ARG LENGTH : %ld\n", strlen(argv[1]));
#endif

	for(int i  = 0; alphas[i]; i++){
#ifdef DEBUG
		printf("%s\n", alphas[i]);
#endif

		free(alphas[i]);
		alphas[i] = (char *)0;
	}

	return 0;
}
