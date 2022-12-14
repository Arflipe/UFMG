#include <getopt.h>
#include "msgassert.h"

#include "AVLDict.h"
#include "HashDict.h"
#include "Timer.h"

static bool endWith(string& name, string extension){
	return name.size() >= extension.size() && 0 == name.compare(name.size()-extension.size(), extension.size(), extension);
}

void parseArgs(int argc, char* argv[], string& inputName, string& outputName, char& type){
	int opt;
	while((opt = getopt(argc, argv, "i:o:t:")) != -1){
		switch(opt){
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
		case 't':
			type = tolower(optarg[0]);
			break;
		default:
			break;
		}
	}
}

bool getEntry(string& word, string& meaning, char& type){
	string line;
	if(!getline(inputFile, line)){
		return false;
	}
	if(line.back() == '\r'){
		line.pop_back();
	}
	type = line[0];
	int start = line.find("[");
	start++;
	int end = line.find("]");
	word = line.substr(start, end - start);
	start = end + 2;
	if(start < ((int) line.length())){
		meaning = line.substr(start);
	}
	return true;
}

void aDict(){
	string word;
	string meaning;
	char type;
	AVLDict* d = new AVLDict();
	while(getEntry(word, meaning, type)){
		d->insert(word, meaning, type);
		meaning.clear();
	}
	d->print();
	d->remove();
	d->print();
	delete d;
}

void hDict(){
	string word;
	string meaning;
	char type;
	HashDict* d = new HashDict();
	while(getEntry(word, meaning, type)){
		if(!word.empty()){
			d->insert(word, meaning, type);
		}
		meaning.clear();
	}
	d->print();
	d->remove();
	d->print();
	delete d;
}

int main(int argc, char* argv[]) {
	string inputName = "input.txt";
	string outputName = "output.txt";
	char type;

	double time;

	parseArgs(argc, argv, inputName, outputName, type);

	inputFile.open(inputName); // Arquivo de texto a ser lido
	erroAssert(inputFile.is_open(), "Arquivo a ser lido não encontrado");

	outputFile.open(outputName);

	time = Timer(); // Tempo de início
	if(type == 'a'){
		aDict();
	}
	else if(type == 'h'){
		hDict();
	}
	time = Timer() - time; // Tempo final = tempo de fim - tempo de início

	cout << time << endl;

	inputFile.close();
	outputFile.close();
	return 0;
}