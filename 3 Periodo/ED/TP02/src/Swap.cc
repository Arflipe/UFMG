#include "Swap.h"

void swap(Register* r, int i, int j){
	Register aux;
	aux = r[i];
	r[i] = r[j];
	r[j] = aux;
}