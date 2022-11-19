#include "SelectionSort.h"

void selectionSort(Register* r, int left, int right){
	int min;
	for(int i = left; i < right; i++){
		min = i;
		for(int j = i + 1; j <= right; j++){
			if(r[j].getKey() < r[min].getKey()){
				min = j;
			}
			keyComps++;
		}
		swap(r, i, min);
	}
}