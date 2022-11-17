#include <string.h>
#include <getopt.h>
#include "memlog.h"
#include "msgassert.h"

#include "Default.h"
#include "File.h"
#include "Mean.h"
#include "RandArray.h"
#include "QuickSort.h"
#include "Timer.h"
#include "Sort.h"

static bool endWith(std::string& name, std::string extension){
	return name.size() >= extension.size() && 0 == name.compare(name.size()-extension.size(), extension.size(), extension);
}

// Se for o Selection QuickSort ou o Median QuickSort, atualizar a variável extra para passar como parâmetro posteriormente
int getExtra(int type, int k, int m){
	int extra;
	switch (type){
	case 2:
		extra = k;
		break;
	case 3:
		extra = m;
		break;
	default:
		break;
	}
	return extra;
}

int main(int argc, char* argv[]) {
	ifstream inputFile;
	ofstream outputFile;
	string inputName = "input.txt";
	string outputName;
	int type = 0;
	int k = 3;
	int m = 10;
	int seed = 1;
	int extra; // Para passar o k do Median ou o m do Selection para a função quickSort()
	int opt;
	while((opt = getopt(argc, argv, "v:k:m:s:i:o:")) != -1){
		switch(opt){
		case 'v':
			type = atoi(optarg);
			break;
		case 'k':
			k = atoi(optarg);
			break;
		case 'm':
			m = atoi(optarg);
			break;
		case 's':
			seed = atoi(optarg);
			break;
		case 'i':
			inputName = optarg;
			if(!endWith(inputName, ".txt")){
				inputName += ".txt";
			}
			break;
		case 'o':
			outputName = optarg;
			if(!endWith(outputName, ".txt")){
				outputName += ".txt";
			}
			break;
		default:
			break;
		}
	}

	inputFile.open(inputName); // Arquivo de texto a ser lido
	erroAssert(inputFile.is_open(), "Arquivo a ser lido não encontrado");

	char logName[] = "log.out";
	iniciaMemLog(logName);
	ativaMemLog();

	int size;
	if((type > 0) && (type <= SORTING_TYPES)){
		extra = getExtra(type, k, m);

		if(outputName.empty()){
			outputName = defaultOutputName(type, extra, seed);
		}
		outputFile.open(outputName); // Arquivo de texto a ser criado
		fHeader(type, extra, outputFile);

		while(inputFile >> size){
			double* meanValue = Sort(size, type, seed, extra);
			fBody(size, meanValue[0], meanValue[1], meanValue[2], outputFile);
		}

		outputFile.close();
	}
	else{
		for(int i = 1; i <= SORTING_TYPES; i++){
			extra = getExtra(i, k, m);

			string currentOutputName = outputName;
			if(currentOutputName.empty()){
				currentOutputName = defaultOutputName(i, extra, seed);
				outputFile.open(currentOutputName); // Arquivo de texto a ser criado
			}
			else if(i == 1){
				outputFile.open(currentOutputName); // Arquivo de texto a ser criado
			}
			else{
				outputFile.open(currentOutputName, ios_base::app); // Arquivo de texto a ser criado
			}
			
			fHeader(i, extra, outputFile);

			while(inputFile >> size){
				double* meanValue = Sort(size, i, seed, extra);
				fBody(size, meanValue[0], meanValue[1], meanValue[2], outputFile);
			}

			outputFile << endl;

			outputFile.close();
			
			inputFile.clear();
			inputFile.seekg(0);
		}
	}

	inputFile.close();

	finalizaMemLog();
	return 0;
}