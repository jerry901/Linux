#include <stdio.h>
#include "min.h"
#include "mindepth.h"
#include "newnode.h"
#include "delnode.h"

int mindepth(Node *pNode, int sec){
	if(pNode && pNode->cony == pNode->brown){
		delNode(pNode);
		return 0;
	}

	sec++;

	/** 따라가기 */
	if(pNode->cony > pNode->brown){
		if(pNode->brown + 1 <= 200 && pNode->cony+sec >= pNode->brown + 1){
			pNode->right = newNode(pNode->cony + sec, pNode->brown + 1);
		}

		if((pNode->brown)*2 <= 200 && pNode->cony+sec >= pNode->brown*2){
			pNode->jump = newNode(pNode->cony + sec, (pNode->brown)*2);
		}

		if(pNode->brown - 1 >= 0 && pNode->cony+sec <= pNode->brown-1){
			pNode->left = newNode(pNode->cony + sec, pNode->brown - 1);
		}
	}

	if(pNode->cony < pNode->brown){
		if(pNode->brown - 1 >= 0 && pNode->cony+sec <= pNode->brown - 1){
			pNode->left = newNode(pNode->cony + sec, pNode->brown - 1);
		}

		if(pNode->brown + 1 <= 200 && pNode->cony+sec <= pNode->brown + 1){
			pNode->right = newNode(pNode->cony + sec, pNode->brown + 1);
		}

		if((pNode->brown)*2 <= 200 && pNode->cony+sec <= pNode->brown*2){
			pNode->jump = newNode(pNode->cony + sec, (pNode->brown)*2);
		}
	}

	/** 노드삭제  */
	if(pNode->left){
		if(pNode->left->cony == pNode->left->brown){
			delNode(pNode->left);
			return 1;
		}
	}

	if(pNode->right){
		if(pNode->right->cony == pNode->right->brown){
			delNode(pNode->right);
			return 1;
		}
	}

	if(pNode->jump){
		if(pNode->jump->cony == pNode->jump->brown){
			delNode(pNode->jump);
			return 1;
		}
	}


	if(!(pNode->left) && (pNode->right) && (pNode->jump))
		return mindepth(pNode->right, sec) < mindepth(pNode->jump, sec) ? mindepth(pNode->right, sec) : mindepth(pNode->jump, sec) + 1;

	if((pNode->left) && !(pNode->right) && (pNode->jump))
		return mindepth(pNode->left, sec) < mindepth(pNode->jump, sec) ? mindepth(pNode->left, sec) : mindepth(pNode->jump, sec) + 1;

	if((pNode->left) && (pNode->right) && !(pNode->jump))
		return mindepth(pNode->left, sec) < mindepth(pNode->right, sec) ? mindepth(pNode->left, sec) : mindepth(pNode->right, sec) + 1;

	if(pNode->left)
		return mindepth(pNode->left, sec) + 1;

	if(pNode->right)
		return mindepth(pNode->right, sec) + 1;

	if(pNode->jump)
		return mindepth(pNode->jump, sec) + 1;

	return min(mindepth(pNode->left, sec), mindepth(pNode->right, sec), mindepth(pNode->jump, sec));
}
