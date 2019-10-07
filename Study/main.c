#include <stdio.h>

int main()
{
	int a = 0;
	int count = 0;
	
	printf("put num : ");
	scanf("%d", &a);

	for(int i = 1 ;i <= a ; i++){
		if(a%i == 0)
			count++;
	} 

	printf("\nCOUNT : %d\n", count);

	return 0;
}
