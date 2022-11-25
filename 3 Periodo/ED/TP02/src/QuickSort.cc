#include "QuickSort.h"

void quickSort(Register* r, int size, int type, int extra){
	switch (type){
	case 1:
		recursiveOrder(0, (size - 1), r);
		break;
	case 2:
		medianOrder(0, (size - 1), r, extra); // Mediana de (extra) elementos
		break;
	case 3:
		selectionOrder(0, (size - 1), r, extra); // Faz Selection Sort a partir de vetores com (extra) ou menos elementos;
		break;
	case 4:
		iterative(0, (size - 1), r);
		break;
	case 5:
		smartStack(0, (size - 1), r);
		break;
	}
}

void partition(int left, int right, int* i, int* j, Register* r){
	Register pivot;
	*i = left;
	*j = right;
	LEMEMLOG((long int) &r[(*i + *j) / 2],sizeof(Register), 1);
	pivot = r[(*i + *j) / 2];
	regCopies++;
	do{

		while(r[*i].getKey() < pivot.getKey()){
			LEMEMLOG((long int) &r[*i],sizeof(Register), 1);
			LEMEMLOG((long int) &pivot,sizeof(Register), 1);
			(*i)++;
			keyComps++;
		}
		keyComps++; //Quando condição for falsa
		LEMEMLOG((long int) &r[*i],sizeof(Register), 1);
		LEMEMLOG((long int) &pivot,sizeof(Register), 1);
		while(r[*j].getKey() > pivot.getKey()){
			LEMEMLOG((long int) &r[*j],sizeof(Register), 0);
			LEMEMLOG((long int) &pivot,sizeof(Register), 1);
			(*j)--;
			keyComps++;
		}
		keyComps++; //Quando condição for falsa
		LEMEMLOG((long int) &r[*j],sizeof(Register), 1);
		LEMEMLOG((long int) &pivot,sizeof(Register), 1);
		if(*i <= *j){
			swap(r, *i, *j);
			(*i)++;
			(*j)--;
		}
	} while(*i <= *j);
}
