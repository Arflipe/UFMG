#include "Sort.h"

double* Sort(int size, int type, int seed, int extra, ofstream& outputFile){
	double compsArray[5];
	double regCopiesArray[5];
	double timeArray[5];
	for(int i = 0; i < 5; i++){
		int comps = 0;
		int regCopies = 0;
		double time;
		Register* r = new Register[size];
		randArray(r, size, seed);
		time = Timer(); // Tempo de início
		quickSort(r, size, type, extra, &comps, &regCopies);
		time = Timer() - time; // Tempo final = tempo de fim - tempo de início
		seed++; // Não executar 5 vezes com a mesma seed
		compsArray[i] = comps;
		regCopiesArray[i] = regCopies;
		timeArray[i] = time;
		delete[] r;
	}
	double* meanValue = new double[3];
	meanValue[0] = getMean(compsArray, 5);
	meanValue[1] = getMean(regCopiesArray, 5);
	meanValue[2] = getMean(timeArray, 5);
	return meanValue;
}