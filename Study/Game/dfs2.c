#include <stdio.h>
#include "main.h"

#define PREVIOUS 0
#define CURRENT 1

#define LEFT 0
#define RIGHT 1
#define JUMP 2

int conyNext(int prv, int n);
int brownNext(int prv1, int where);

void dfs(int prvCony, int prvBrown, int prvSec){
	printf("minSec = %d\n", minSec);

	int sec = prvSec;
	int cony_Next = 0; 
	int brown_Next = 0;

	if(prvCony == prvBrown){
		if(minSec == -1 || minSec > sec){
			printf("DONE\n");
			minSec = prvSec;
			return;
		}
	}
	else if((cony_Next = conyNext(prvCony, sec)) == -1){
		printf("Out of range\n");
		return;
	} 

	sec++;

	if(prvCony < prvBrown){
		if((brown_Next = brownNext(prvBrown, LEFT)) != -1){
			printf("Cony : %d, brown :%d\n", cony_Next, brown_Next);
			dfs(cony_Next, brown_Next, sec);
		}
	}
	else if(prvCony > prvBrown && (prvCony-prvBrown) >= prvBrown){
		if((brown_Next = brownNext(prvBrown, JUMP)) != -1){
			printf("Cony : %d, brown :%d\n", cony_Next, brown_Next);
			dfs(cony_Next, brown_Next, sec);
		}
	}
	else if(prvCony > prvBrown && (prvCony-prvBrown) <= prvBrown){
		if((brown_Next = brownNext(prvBrown, RIGHT)) != -1){
			printf("Cony : %d, brown :%d\n", cony_Next, brown_Next);
			dfs(cony_Next, brown_Next, sec);
		}
	}
}
