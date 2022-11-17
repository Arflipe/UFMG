#include "QuickSort.h"

void recursiveOrder(int left, int right, Register* r, int* comps, int* regCopies){
	int i, j;
	partition(left, right, &i, &j, r, comps, regCopies);
	if(left < j){
		recursiveOrder(left, j, r, comps, regCopies);
	}
	(*comps)++;
	if(right > i){
		recursiveOrder(i, right, r, comps, regCopies);
	}
	(*comps)++;
}