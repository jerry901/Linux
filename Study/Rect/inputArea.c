#include <stdio.h>

long long inputArea(long long maxNum){

	long long area;

	while(1){
		printf("Put the area 'N' : ");
		if(scanf("%lld", &area)==1){
			if (area < 1 || area > maxNum) {
				printf("Out of input range\n");
				printf("Try again..\n");
				continue;
			}
			else
				break;
		}
		else{
			printf("Scanf error!\n");
			printf("Try again..\n");
			while (getchar() != '\n');
			continue;
		}
	}
	return area;
}
