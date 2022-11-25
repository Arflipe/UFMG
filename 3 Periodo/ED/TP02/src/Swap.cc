#include "Swap.h"

void swap(Register* r, int i, int j){
	Register aux;
	LEMEMLOG((long int) &r[i],sizeof(Register), 0);
	aux = r[i];
	regCopies++;
	ESCREVEMEMLOG((long int) &(r[i]),sizeof(Register), 0);
	LEMEMLOG((long int) &r[j],sizeof(Register), 0);
	r[i] = r[j];
	regCopies++;
	ESCREVEMEMLOG((long int) &r[j],sizeof(Register), 0);
	r[j] = aux;
	regCopies++;
}