#include <stdio.h>
#include <math.h>
#include "main.h"

int main(int argc, char *argv[])
{
	long long areaN = 0;
	double rootOfN = 0;

	long long oneOfthem = 0;

	printf("  ┌────────CONDITIONS FOR the input 'N'────────┐    \n");
	printf("  │ \"0 < N < 10^13\", \"'N' is a natural number\" │\n");
	printf("  └────────────────────────────────────────────┘\n"    );

	areaN = inputArea(MAX);
	rootOfN = sqrt(areaN);
	oneOfthem = findOne(areaN, rootOfN);

	/** printf("root = %f\n", rootOfN); */
	/** printf("areaN = %lli\n", areaN); */
	printf("Minimun |w-h| = %lli\n", (long long)((areaN/oneOfthem)-oneOfthem));

	return 0;
}
