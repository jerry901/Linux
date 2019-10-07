#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define MAX 200000
#define LEFT 0
#define RIGHT 1
#define JUMP 2

int conyNext(int prv, int n);
int brownNext(int prv1, int where);

void dfs(int prvCony, int prvBrown, int prvSec);

int minSec = -1;
int maxSec = 0;;
int maxCony = 0;

int main()
{
	int sec = 0;
	int cony = 0;
	int brown =0;

	int cony_Next = 0;
	int brown_Next = 0;


	printf(" -----Put Cony'sand Borwn's fist locations----- \n");
	printf("Input : ");
	scanf("%d %d", &cony, &brown);

	sec++;

	if((cony_Next = conyNext(cony, sec)) == -1) {
		printf("MIN SEC : %d\n", minSec);
		return 0;

	} 

	for(maxCony = cony; maxCony < MAX; maxSec++){
		maxCony = maxSec + maxCony;
	}
	maxCony = maxCony - maxSec;
	maxSec--;

	for(int where = LEFT; where <= JUMP; where++){

		if(brown*2 < cony_Next){
			where = JUMP;
		}
		else if((brown_Next = brownNext(brown, where)) == -1){
			continue;
		}
		else if(brown_Next >100000 && brown_Next + (maxSec-sec) < maxCony)
			continue;
		else if(brown_Next - (maxSec-sec) > maxCony)
			continue;
		else if((cony_Next == brown_Next) && ((minSec == -1)||(minSec > sec))){
			minSec = sec;
			continue;
		}
		else{
			printf("CONY : %d, BROWN : %d\n", cony_Next, brown_Next);
			printf("%d\n", minSec);
			dfs(cony_Next, brown_Next, sec);
		}
	}

	printf("MIN SEC : %d\n", minSec);

	return 0;
}
