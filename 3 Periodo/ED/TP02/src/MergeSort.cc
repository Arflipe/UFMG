#include "MergeSort.h"

void mergeSort(Register* r, int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(r, left, mid);
		mergeSort(r, (mid + 1), right);
		merge(r, left, mid, right);
	}
}

void merge(Register* r, int left, int mid, int right){
	int leftArraySize = mid - left + 1;
	int rightArraySize = right - mid;
	Register* leftArray = new Register[leftArraySize];
	Register* rightArray = new Register[rightArraySize];
	for(int i = 0; i < leftArraySize; i++){
		leftArray[i] = r[left + i];
		regCopies++;
	}
	for(int i = 0; i < rightArraySize; i++){
		rightArray[i] = r[mid + 1 + i];
		regCopies++;
	}
	int i = 0;
	int j = 0;
	int k = left;
	while((i < leftArraySize) && (j < rightArraySize)){
		if(leftArray[i].getKey() <= rightArray[j].getKey()){
			r[k] = leftArray[i];
			regCopies++;
			i++;
		}
		else{
			r[k] = rightArray[j];
			regCopies++;
			j++;
		}
		keyComps++;
		k++;
	}
	while(i < leftArraySize){
		r[k] = leftArray[i];
		regCopies++;
		i++;
		k++;
	}
	while(j < rightArraySize){
		r[k] = rightArray[j];
		regCopies++;
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
}