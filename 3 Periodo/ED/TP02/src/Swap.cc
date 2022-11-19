#include "Swap.h"

void swap(Register* r, int i, int j){
	Register aux;
	aux = r[i];
	regCopies++;
	r[i] = r[j];
	regCopies++;
	r[j] = aux;
	regCopies++;
}