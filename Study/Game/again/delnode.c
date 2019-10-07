#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define MAX 20 
#define MIN 0

void delNode(Node* pNode){
	free(pNode->left);
	pNode->left = NULL;
	free(pNode->right);
	pNode->right = NULL;
	free(pNode->jump);
	pNode->jump = NULL;
}
