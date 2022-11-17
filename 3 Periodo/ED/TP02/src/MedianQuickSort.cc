#include "QuickSort.h"

void medianPartition(int left, int right, int* i, int* j, Register* r, int medianOf, int* comps, int* regCopies){
	Register pivot;
	if(medianOf > (right - left + 1)){
		medianOf = right - left + 1;
	}
	Register* auxArray = new Register[medianOf];
	for(int k = 0; k < medianOf; k++){
		auxArray[k] = r[left + (k * (right - left + 1) / medianOf)];
		(*regCopies)++;
	}
	selectionSort(auxArray, 0, (medianOf - 1), comps, regCopies);
	*i = left;
	*j = right;
	pivot = auxArray[medianOf / 2];
	(*regCopies)++;
	do{
		while(r[*i].getKey() < pivot.getKey()){
			(*i)++;
			(*comps)++;
		}
		(*comps)++; //Quando condição for falsa
		while(r[*j].getKey() > pivot.getKey()){
			(*j)--;
			(*comps)++;
		}
		(*comps)++; //Quando condição for falsa
		if(*i <= *j){
			swap(r, *i, *j);
			(*regCopies) += 3; // 3 Cópias no swap
			(*i)++;
			(*j)--;
		}
		(*comps) += 2; //If de cima e while de baixo
	} while(*i <= *j);
	delete[] auxArray;
}

void medianOrder(int left, int right, Register* r, int medianOf, int* comps, int* regCopies){
	int i, j;
	medianPartition(left, right, &i, &j, r, medianOf, comps, regCopies);
	if(left < j){
		medianOrder(left, j, r, medianOf, comps, regCopies);
	}
	(*comps)++;
	if(right > i){
		medianOrder(i, right, r, medianOf, comps, regCopies);
	}
	(*comps)++;
}