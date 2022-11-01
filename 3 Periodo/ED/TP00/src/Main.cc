#include <fstream>
#include <string>
#include <string.h>
#include <getopt.h>

#include "Converter.h"

static bool endWith(std::string& name, std::string extension){
	return name.size() >= extension.size() && 0 == name.compare(name.size()-extension.size(), extension.size(), extension);
}

int main(int argc, char* argv[]) {
	std::ifstream originalImage;
	std::ofstream convertedImage;
	std::ofstream log;
	std::string originalName, convertedName,regName;
	bool memReg;
	int opt;
	while((opt = getopt(argc, argv, "i:o:p:l")) != -1){
		switch(opt)
		{
		case 'i':
			originalName = optarg;
			if(!endWith(originalName, ".ppm")){
				originalName += ".ppm";
			}
			break;
		case 'o':
			convertedName = optarg;
			if(!endWith(convertedName, ".pgm")){
				convertedName += ".pgm";
			}
			break;
		case 'p':
			regName = optarg;
			if(!endWith(regName, ".out")){
				regName += ".out";
			}
			break;
		case 'l':
			memReg = true;
			break;
		default:
			break;
		}
	}
	char* regNameChar = new char[regName.size() + 1];
	strcpy(regNameChar, regName.c_str());
	iniciaMemLog(regNameChar);
	if(memReg){
		ativaMemLog();
	}
	else{
		desativaMemLog();
	}
	originalImage.open(originalName); // Imagem ppm a ser lida
	erroAssert(originalImage.is_open(), "Imagem a ser lida não encontrada");
	convertedImage.open(convertedName); // Imagem pgm a ser criada
	Converter c;
	c.ConvertImage(originalImage, convertedImage);


	originalImage.close();
	convertedImage.close();
	return 0;
}