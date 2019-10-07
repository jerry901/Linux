#include <stdio.h>

#define MAX 200000

int conyNext(int prv, int n)
{
	int	next = prv + n;

	if(next <= MAX){
		return next;
	}
	else
		return -1;

	return 0;
}
