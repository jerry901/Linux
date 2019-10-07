#include <stdio.h>
#include <stdlib.h>
#include "maxabs.h"

#define MAX_NUM 5000
#define MAX_ROW 101
#define DEBUG

int main()
{
	int r1, c1, r2, c2 = 0;
	int *pArr[MAX_ROW] = {0};
	int squareSize = 0;
	int endOfArr = 0;

	printf("Put r1, c1, r2, c2 : \n");

	do{
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		while(getchar() != '\n');
	}while(r1 > MAX_NUM || r1 < -MAX_NUM || c1 > MAX_NUM || c1 < -MAX_NUM || 
			r2 > MAX_NUM || r2 <-MAX_NUM || c2 > MAX_NUM || c2 < -MAX_NUM || 
			r2-r1 < 0 || r2-r1 > 50 || c2-c1 < 0 || c2-c1 > 4);

	squareSize = 2*maxabs(maxabs(r1, r2), maxabs(c1, c2)) + 1;
	endOfArr = squareSize*squareSize;


	for(int i = 0; i < squareSize; i++){
		pArr[i] = (int*)malloc(squareSize*sizeof(int));
		for (int j = 0; j < squareSize; j++) {
			pArr[i][j] = 0;	
		}
	}

	int W = squareSize/2;
	int H = squareSize/2;
	int delta = 1;
	int where = 1;
	int num = 1;

	while(W < squareSize && H < squareSize){
		for (int x = 0; x < delta; x++) {
			pArr[W][H] = num++; 

			if((H = H + where) > squareSize)
				break;

		}

		for (int y = 0; y < delta; y++) {
			pArr[W][H] = num++; 

			if((W = W - where) > squareSize)
				break;
		}
		where = (-1)*where;
		delta++;
	}

/************* 여기부터 출력 부분 *******************/
#ifdef DEBUG

	printf("------------DEBUG------------\n");
	printf("       ");


	for(int i = 0; i < squareSize; i++){
			if(endOfArr > 999)
				printf("%4d  ", c1 + i);
			else if(endOfArr > 99)
				printf("%3d ", c1 + i);
			else if(endOfArr > 9)
				printf("%2d ", c1 + i);
			else
				printf("1%d", c1 + i);
	}

	printf("\n      ");

	for(int i = 0; i < squareSize; i++){
			if(endOfArr > 999)
				printf("-----");
			else if(endOfArr > 99)
				printf("----");
			else if(endOfArr > 9)
				printf("---");
			else
				printf("--");
	}
	printf("\n");

	for(int i = 0; i < squareSize; i++){
			printf("%5d|", r1 + i);
		for (int j = 0; j < squareSize; j++) {
			if(endOfArr > 999)
				printf("%5d", pArr[i][j]);
			else if(endOfArr > 99)
				printf("%4d",  pArr[i][j]);
			else if(endOfArr > 9)
				printf("%3d", pArr[i][j]);
			else
				printf("%2d", pArr[i][j]);
		}
		printf("\n");
	}

	printf("-----------------------------\n");
#endif

	int rowStart = r1 + squareSize/2;
	int rowLength = r2 - r1;
	int colStart = c1 + squareSize/2;
	int colLength = c2 - c1;


	printf("       ");

	for(int i = 0; i <= colLength; i++){
			if(endOfArr > 999)
				printf("%4d  ", c1 + i);
			else if(endOfArr > 99)
				printf("%3d ", c1 + i);
			else if(endOfArr > 9)
				printf("%2d ", c1 + i);
			else
				printf("1%d", c1 + i);
	}

	printf("\n      ");

	for(int i = 0; i <= colLength; i++){
			if(endOfArr > 999)
				printf("-----");
			else if(endOfArr > 99)
				printf("----");
			else if(endOfArr > 9)
				printf("---");
			else
				printf("--");
	}
	printf("\n");

	for(int i = rowStart; i <= rowLength; i++){
			printf("%5d|", r1 + i);
		for (int j = colStart; j <= colLength; j++) {
			if(endOfArr > 999)
				printf("%5d", pArr[i][j]);
			else if(endOfArr > 99)
				printf("%4d",  pArr[i][j]);
			else if(endOfArr > 9)
				printf("%3d", pArr[i][j]);
			else
				printf("%2d", pArr[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < squareSize; i++) {
		free(pArr[i]);
		pArr[i] = NULL;
	}

	return 0;
}
