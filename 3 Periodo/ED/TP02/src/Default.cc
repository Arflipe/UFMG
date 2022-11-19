#include "Default.h"

string defaultOutputName(int type, int extra, int seed){
	string outputName;
	switch (type){
	case 1:
		outputName = "R_QuickSort_";
		break;
	case 2:
		outputName = "M" + to_string(extra) + "_QuickSort_";
		break;
	case 3:
		outputName = "S" + to_string(extra) + "_QuickSort_";
		break;
	case 4:
		outputName = "I_QuickSort_";
		break;
	case 5:
		outputName = "S_S_QuickSort_";
		break;
	case 6:
		outputName = "MergeSort_";
		break;
	case 7:
		outputName = "HeapSort_";
		break;
	}
	outputName += to_string(seed) + ".txt";
	return outputName;
}