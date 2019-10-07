#include <stdio.h>

#define MAX 200000

#define LEFT 0
#define RIGHT 1
#define JUMP 2

int brownNext(int prv1, int where){

	int next;
	switch (where) {
		case LEFT:
			next = prv1-1;
			if(next >= 0){
				return next;
			}
			else
				return -1;
			break;
		case RIGHT:
			next = prv1+1;
			if(next <= 200000){
				return next;
			}
			else
				return -1;
			break;
		case JUMP:
			next = prv1*2;
			if(next <= 200000){
				return next;
			}
			else
				return -1;
			break;
		default:
				return -1;
				break;
	}
}
