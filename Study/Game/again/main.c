#include <stdio.h>
#include <stdlib.h>
#include "mindepth.h"
#include "newnode.h"
#include "delnode.h"

int makeTree(Node *pRoot, int sec);
int freeTree(Node *pRoot);

int main()
{
	int cony ,brown = 0;

	printf("Put Cony's and Brown's first loacation\n");
	scanf("%d %d", &cony, &brown);

	Node *pRoot = NULL;
	pRoot = newNode(cony, brown);

	mindepth(pRoot, 0);

	return 0;
}
