#include "QuickSort.h"

void medianPartition(int left, int right, int* i, int* j, Register* r, int medianOf){
	Register pivot;
	if(medianOf > (right - left + 1)){
		medianOf = right - left + 1;
	}
	Register* auxArray = new Register[medianOf];
	for(int k = 0; k < medianOf; k++){
		auxArray[k] = r[left + (k * (right - left + 1) / medianOf)];
		regCopies++;
	}
	selectionSort(auxArray, 0, (medianOf - 1));
	*i = left;
	*j = right;
	pivot = auxArray[medianOf / 2];
	regCopies++;
	do{
		while(r[*i].getKey() < pivot.getKey()){
			(*i)++;
			keyComps++;
		}
		keyComps++; //Quando condição for falsa
		while(r[*j].getKey() > pivot.getKey()){
			(*j)--;
			keyComps++;
		}
		keyComps++; //Quando condição for falsa
		if(*i <= *j){
			swap(r, *i, *j);
			(*i)++;
			(*j)--;
		}
	} while(*i <= *j);
	delete[] auxArray;
}

void medianOrder(int left, int right, Register* r, int medianOf){
	int i, j;
	medianPartition(left, right, &i, &j, r, medianOf);
	if(left < j){
		medianOrder(left, j, r, medianOf);
	}
	if(right > i){
		medianOrder(i, right, r, medianOf);
	}
}