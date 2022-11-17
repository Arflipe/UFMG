#include "QuickSort.h"

void selectionOrder(int left, int right, Register* r, int maxSize, int* comps, int* regCopies){
	int i, j;
	partition(left, right, &i, &j, r, comps, regCopies);
	if((j - left + 1) > maxSize){
		selectionOrder(left, j, r, maxSize, comps, regCopies);
	}
	else{
		selectionSort(r, left, j, comps, regCopies);
	}
	(*comps)++;
	if((right - i + 1) > maxSize){
		selectionOrder(i, right, r, maxSize, comps, regCopies);
	}
	else{
		selectionSort(r, i, right, comps, regCopies);
	}
	(*comps)++;
}