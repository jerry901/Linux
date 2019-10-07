#include <stdio.h>

long long findOne(long long N, double root){

	long long i = (long long)root;

	while(N%i != 0)
		i--;

	return i;
}
