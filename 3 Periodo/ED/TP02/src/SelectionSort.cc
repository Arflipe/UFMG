#include "SelectionSort.h"

void selectionSort(Register* r, int left, int right, int* comps, int* regCopies){
	int min;
	for(int i = left; i < right - 1; i++){
		min = i;
		for(int j = i + 1; j < right; j++){
			if(r[j].getKey() < r[min].getKey()){
				min = j;
			}
			(*comps)++;
		}
		swap(r, i, min);
		(*regCopies) += 3;
	}
}