#include "Sort.h"

double* Sort(int size, int type, int seed, int extra){
	double keyCompsArray[5];
	double regCopiesArray[5];
	double timeArray[5];
	for(int i = 0; i < 5; i++){
		keyComps = 0;
		regCopies = 0;
		double time;
		Register* r = new Register[size];
		randArray(r, size, seed);
		time = Timer(); // Tempo de início
		if(type <= 5){
			quickSort(r, size, type, extra);
		}
		else if(type == 6){
			mergeSort(r, 0, (size - 1));
		}
		else{
			heapSort(r, size);
		}
		time = Timer() - time; // Tempo final = tempo de fim - tempo de início
		seed++; // Não executar 5 vezes com a mesma seed
		keyCompsArray[i] = keyComps;
		regCopiesArray[i] = regCopies;
		timeArray[i] = time;
		delete[] r;
	}
	double* meanValue = new double[3];
	meanValue[0] = getMean(keyCompsArray, 5);
	meanValue[1] = getMean(regCopiesArray, 5);
	meanValue[2] = getMean(timeArray, 5);
	return meanValue;
}