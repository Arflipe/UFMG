#include "MergeSort.h"

void mergeSort(Register* r, int left, int right, int* comps, int* regCopies){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(r, left, mid, comps, regCopies);
		mergeSort(r, (mid + 1), right, comps, regCopies);
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
	}
	for(int i = 0; i < rightArraySize; i++){
		rightArray[i] = r[mid + 1 + i];	
	}
	int i = 0;
	int j = 0;
	int k = 0;
	while((i < leftArraySize) && (j < rightArraySize)){
		if(leftArray[i].getKey() <= rightArray[j].getKey()){
			r[left + k] = leftArray[i];
			i++;
		}
		else{
			r[left + k] = rightArray[j];
			j++;
		}
		k++;
	}
	while(i < leftArraySize){
		r[left + k] = leftArray[i];
		i++;
		k++;
	}
	while(j < rightArraySize){
		r[left + k] = rightArray[j];
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
}