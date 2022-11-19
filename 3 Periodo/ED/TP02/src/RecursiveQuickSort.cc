#include "QuickSort.h"

void recursiveOrder(int left, int right, Register* r){
	int i, j;
	partition(left, right, &i, &j, r);
	if(left < j){
		recursiveOrder(left, j, r);
	}
	if(right > i){
		recursiveOrder(i, right, r);
	}
}