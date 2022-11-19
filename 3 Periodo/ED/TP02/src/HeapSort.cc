#include "HeapSort.h"

void heapSort(Register* r, int size, int* comps, int* regCopies){
	int left = 0;
	int right = (size - 1);
	heapify(r, size, comps, regCopies);
	while(right > 0){
		swap(r, left, right);
		right--;
		redo(r, left, right, comps, regCopies);
	}
}

void heapify(Register* r, int size, int* comps, int* regCopies){
	int left = size / 2;
	while(left > 0){
		left--;
		redo(r, left, (size - 1), comps, regCopies);
	}
}

void redo(Register* r, int left, int right, int* comps, int* regCopies){
	int i = left;
	int j = 2 * i;
	Register aux = r[i];
	while(j <= right){
		if(j < right){
			if(r[j].getKey() < r[j + 1].getKey()){
				j++;
			}
		}
		if(aux.getKey() < r[j].getKey()){
			r[i] = r[j];
			i = j;
			j = i * 2;
		}
		else{
			break;
		}
	}
	r[i] = aux;
}
