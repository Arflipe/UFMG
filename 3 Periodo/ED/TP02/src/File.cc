#include "File.h"

void fHeader(int type, int extra, ofstream& outputFile){
	string sortType;
	switch (type){
	case 1:
		sortType = "Recursive QuickSort";
		break;
	case 2:
		sortType = "Median QuickSort\nk = " + to_string(extra);
		break;
	case 3:
		sortType = "Selection QuickSort\nm = " + to_string(extra);
		break;
	case 4:
		sortType = "Iterative QuickSort";
		break;
	case 5:
		sortType = "Smart Stack QuickSort";
		break;
	case 6:
		sortType = "MergeSort";
		break;
	case 7:
		sortType = "HeapSort";
		break;
	}
	outputFile << sortType << endl << endl;
	outputFile.width(10);
	outputFile << "Array Size";
	outputFile.width(20);
	outputFile << "Mean Comparisons";
	outputFile.width(24);
	outputFile << "Mean Register Copies";
	outputFile.width(23);
	outputFile << "Mean Execution Time";
	outputFile << endl;
}

void fBody(int size, int meanComps, int meanRegCopies, double meanTime, ofstream& outputFile){
	outputFile.width(10);
	outputFile << size;
	outputFile.width(20);
	outputFile << meanComps;
	outputFile.width(24);
	outputFile << meanRegCopies;
	outputFile.width(23);
	outputFile << meanTime;
	outputFile << endl;
}