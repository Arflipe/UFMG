#ifndef CONVERTER_H
#define CONVERTER_H

#include "Image.h"
#include "msgassert.h"
#include "memlog.h"
#include <fstream>

class Converter{
	private:
	Image* toConvert;
	Image* converted;

	public:
	Converter();
	void GrayScale();
	void ConvertImage(std::ifstream& originalImage, std::ofstream& convertedImage);
	void ReadImage(std::ifstream& originalImage);
	void WriteImage(std::ofstream& convertedImage);
	int CheckRange(int toCheck, int range);
};

#endif