#include "QuickSort.h"

void selectionOrder(int left, int right, Register* r, int maxSize){
	int i, j;
	partition(left, right, &i, &j, r);
	if((j - left + 1) > maxSize){
		selectionOrder(left, j, r, maxSize);
	}
	else{
		selectionSort(r, left, j);
	}
	if((right - i + 1) > maxSize){
		selectionOrder(i, right, r, maxSize);
	}
	else{
		selectionSort(r, i, right);
	}
}