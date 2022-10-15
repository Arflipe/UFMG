#include <fstream>
#include <string>
#include <string.h>
#include <getopt.h>

#include "Server.h"
#include "msgassert.h"


static bool endWith(std::string& name, std::string extension){
	return name.size() >= extension.size() && 0 == name.compare(name.size()-extension.size(), extension.size(), extension);
}

int main(int argc, char* argv[]) {
	std::ifstream inputFile;
	std::string inputName,regName;
	int opt;
	while((opt = getopt(argc, argv, "i:p:l")) != -1){
		switch(opt)
		{
		case 'i':
			inputName = optarg;
			if(!endWith(inputName, ".txt")){
				inputName += ".txt";
			}
			break;
		case 'p':
			regName = optarg;
			if(!endWith(regName, ".out")){
				regName += ".out";
			}
			break;
		default:
			break;
		}
	}
	char* regNameChar = new char[regName.size() + 1];
	strcpy(regNameChar, regName.c_str());

	iniciaMemLog(regNameChar);

	inputFile.open(inputName); // Arquivo de texto a ser lido
	erroAssert(inputFile.is_open(), "Arquivo a ser lido não encontrado");

	Server s;
	s.manage(inputFile);

	inputFile.close();

	finalizaMemLog();

	return 0;
}