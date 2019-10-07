#include <stdio.h>
#include <string.h>

int main()
{
	static const char delim[] = "&";

	char str[256] = "sleep 5 & echo Hello & sleep 5; echo Hello";

	char *args[50];

	char *save;
	char *pBuf;
	int i = 0;

	for(pBuf = strtok_r(str, delim, &save); 
			pBuf; 
			pBuf = strtok_r(NULL, delim, &save)){

		printf("%d\n", i);
		args[i++] = pBuf;	

	}


	/** OUT PUT START*/

	i = 0;

	while(args[i]){
		printf("args[%d] : %s\n", i , args[i]);
		i++;
	}

	/**OUT PUT END  */

	return 0;
}
