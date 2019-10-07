#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node* newNode(int cony, int brown){
		
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->cony = cony; 
	temp->brown = brown;
	temp->left = temp->right = temp->jump = NULL;

	return temp;
}
