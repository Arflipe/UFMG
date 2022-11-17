#include "QuickSort.h"

void quickSort(Register* r, int size, int type, int extra, int* comps, int* regCopies){
	switch (type){
	case 1:
		recursiveOrder(0, (size - 1), r, comps, regCopies);
		break;
	case 2:
		medianOrder(0, (size - 1), r, extra, comps, regCopies); // Mediana de (extra) elementos
		break;
	case 3:
		selectionOrder(0, (size - 1), r, extra, comps, regCopies); // Faz Selection Sort a partir de vetores com (extra) ou menos elementos;
		break;
	case 4:
		iterative(0, (size - 1), r, comps, regCopies);
		break;
	case 5:
		smartStack(0, (size - 1), r, comps, regCopies);
		break;
	}
}

void partition(int left, int right, int* i, int* j, Register* r, int* comps, int* regCopies){
	Register pivot;
	*i = left;
	*j = right;
	pivot = r[(*i + *j) / 2];
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
}
