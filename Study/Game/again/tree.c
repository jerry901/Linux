#include <stdio.h>
#include "tree.h"
#include "node.h"
#include "newnode.h"
#include "delnode.h"

int makeTree(Node *pNode, int sec){ //pNode는 main 함수에서 미리 newNode 한 상태로 인수에 넣는다!! pNode->sec 를 인수로 받을 것. 초기 main에서  sec는 입력  
	/** if(pNode == NULL){ */
	/**     printf("ERROR : pNode is NULL!!\n"); */
	/**     return -1; */
	/** } */

	sec++;

	if(pNode->brown - 1 >= 0){
		pNode->left = newNode(pNode->cony + sec, pNode->brown - 1);
		makeTree(pNode->left, sec);
	}

	if(pNode->brown + 1 <= 200){
		pNode->right = newNode(pNode->cony + sec, pNode->brown + 1);
		makeTree(pNode->right, sec);
	}

	if((pNode->brown)*2 <= 200){
		pNode->jump = newNode(pNode->cony + sec, (pNode->brown)*2);
		makeTree(pNode->jump, sec);
	}

	return 0; 
}

int freeTree(Node *pNode){
	if(pNode == NULL)
		return 0;

	if(pNode->left)
		freeTree(pNode->left);

	if(pNode->right)
		freeTree(pNode->right);

	if(pNode->jump)
		freeTree(pNode->jump);

	delNode(pNode->left);
	delNode(pNode->right);
	delNode(pNode->jump);

	return 0;
}
