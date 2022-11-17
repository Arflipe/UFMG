#include <string.h>
#include <getopt.h>
#include "memlog.h"
#include "msgassert.h"

#include "File.h"
#include "Mean.h"
#include "RandKeys.h"
#include "QuickSort.h"
#include "Timer.h"

static bool endWith(std::string& name, std::string extension){
	return name.size() >= extension.size() && 0 == name.compare(name.size()-extension.size(), extension.size(), extension);
}

int main(int argc, char* argv[]) {
	ifstream inputFile;
	ofstream outputFile;
	string inputName = "input.txt";
	string outputName;
	int seed = 1;
	int type = 1;
	int k = 3;
	int m = 10;
	int extra = 0; // Para passar o k do Median ou o m do Selection para a função quickSort()
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

	if(outputName.empty()){
		outputName = "QuickSort_" + to_string(type) + "_" + to_string(seed) + ".txt";
	}

	// Se for o Selection QuickSort ou o Median QuickSort, atualizar a variável extra para passar como parâmetro posteriormente
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

	char logName[] = "log.out";
	iniciaMemLog(logName);
	ativaMemLog();

	inputFile.open(inputName); // Arquivo de texto a ser lido
	erroAssert(inputFile.is_open(), "Arquivo a ser lido não encontrado");
	outputFile.open(outputName); // Arquivo de texto a ser criado

	fHeader(type, extra, outputFile);

	int size;
	while(inputFile >> size){
		double compsArray[5];
		double regCopiesArray[5];
		double timeArray[5];
		for(int i = 0; i < 5; i++){
			int comps = 0;
			int regCopies = 0;
			double time;
			Register* r = new Register[size];
			randKeys(r, size, seed);
			time = Timer(); // Tempo de início
			quickSort(r, size, type, extra, &comps, &regCopies);
			time = Timer() - time; // Tempo final = tempo de fim - tempo de início
			seed++; // Não executar 5 vezes com a mesma seed
			compsArray[i] = comps;
			regCopiesArray[i] = regCopies;
			timeArray[i] = time;
			delete[] r;
		}
		int meanComps = getMean(compsArray, 5);
		int meanRegCopies = getMean(regCopiesArray, 5);
		double meanTime = getMean(timeArray, 5);
		fBody(size, meanComps, meanRegCopies, meanTime, outputFile);
	}

	inputFile.close();
	outputFile.close();

	finalizaMemLog();
	return 0;
}