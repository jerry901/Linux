#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *p[1000000];

	for(int i = 0 ; i <1000000; i++){
		p[i] = (int*)malloc(sizeof(int));
		*p[i] = 5;
	}

	for(int i = 0 ; i <1000000; i++){
		free(p[i]);
	}


	printf("done\n");
	return 0;
}
