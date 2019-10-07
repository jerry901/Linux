#include <stdio.h>

int maxabs(int inputA, int inputB){

	int A;
	int B;

	if(inputA < 0)
		A = - inputA;
	else
		A = inputA;

	if(inputB < 0)
		B = -inputB;
	else 
		B = inputB;

	return A > B ? A : B;
}
