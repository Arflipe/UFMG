#include "HeapSort.h"

void heapSort(Register* r, int size){
	int left = 0;
	int right = (size - 1);
	heapify(r, size);
	while(right > 0){
		swap(r, left, right);
		right--;
		redo(r, left, right);
	}
}

void heapify(Register* r, int size){
	int left = size / 2;
	while(left > 0){
		left--;
		redo(r, left, (size - 1));
	}
}

void redo(Register* r, int left, int right){
	int i = left;
	int j = 2 * i + 1;
	Register aux = r[i];
	regCopies++;
	while(j <= right){
		if(j < right){
			if(r[j].getKey() < r[j + 1].getKey()){
				j++;
			}
			keyComps++;
		}
		if(aux.getKey() < r[j].getKey()){
			r[i] = r[j];
			regCopies++;
			i = j;
			j = i * 2;
		}
		else{
			break;
		}
		keyComps++;
	}
	r[i] = aux;
	regCopies++;
}
