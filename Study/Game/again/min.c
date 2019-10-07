#include <stdio.h>

int min(int left, int right, int jump){

	if(left <= right){
		if(left <= jump)
			return left;
		else
			return jump;
	}
	else if(left >= right){
		if(right<=jump)
			return right;
		else
			return jump;
	}

}
