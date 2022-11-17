#include "Mean.h"

double getMean(double* array, int size){
	double mean = 0;
	for(int i = 0; i < size; i++){
		mean += array[i];
	}
	mean /= size;
	return mean;
}
