#include <stdio.h>
#include "main.h"

#define PREVIOUS 0
#define CURRENT 1

#define LEFT 0
#define RIGHT 1
#define JUMP 2

int conyNext(int prv, int n);
int brownNext(int prv1, int where);

void dfs(int prvCony, int prvBrown, int sec){

	int cony_Next = 0; 
	int brown_Next = 0;

	if((cony_Next = conyNext(prvCony, sec)) == -1){
		/** printf("lose\n"); */
		return;
	}
	else if(prvBrown < prvCony){
		int brown_Max = prvBrown;
		printf("%d\n", maxCony);

		for(int i = sec; i <= maxSec; i++){
				brown_Max = 2*brown_Max;
		}

		if(brown_Max < maxCony){
			return;
		}
	}

	sec++;

	for(int where = LEFT; where <= JUMP; where++){
		if(prvBrown*2 < cony_Next){
			where = JUMP;
		}
		else if((brown_Next = brownNext(prvBrown, where)) == -1){
			continue;
		}
		else if(brown_Next >100000 && brown_Next + (maxSec-sec) < maxCony)
			continue;
		else if(brown_Next - (maxSec-sec) > maxCony)
			continue;
		else if((cony_Next == brown_Next) && ((minSec == -1)||(minSec > sec))){
			minSec = sec;
			return;
		}
		else{
			printf("CONY : %d, BROWN : %d\n", cony_Next, brown_Next);
			printf("%d\n", minSec);
			dfs(cony_Next, brown_Next, sec);
		}
	}
}
