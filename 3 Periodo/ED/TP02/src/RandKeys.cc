#include "RandKeys.h"

void randKeys(Register* r, int size, uint seed){
	srand(seed);
	for(int i = 0; i < size; i++){
		r[i].setKey(rand() % (10 * size));
	}
}