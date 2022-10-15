#include "Converter.h"

Converter::Converter(){}

void Converter::GrayScale(){
	int height = converted->GetHeight();
	int width = converted->GetWidth();
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			Pixel toGrayScale = toConvert->GetPixel(row, col);
			LEMEMLOG((long int) (toConvert->GetPixelAddress(row, col)), sizeof(Pixel), 0);
			int red = toGrayScale.GetR();
			int green = toGrayScale.GetG();
			int blue = toGrayScale.GetB();
			int grayScaled = (49.0 / 255.0 * ((red * 0.3) + (green * 0.59) + (blue * 0.11)));
			converted->SetPixel(row, col, CheckRange(grayScaled, 49));
			ESCREVEMEMLOG((long int) (converted->GetPixelAddress(row, col)), sizeof(Pixel), 1);
		}
	}
}
void Converter::ConvertImage(std::ifstream& originalImage, std::ofstream& convertedImage){
	defineFaseMemLog(0);
	ReadImage(originalImage);
	defineFaseMemLog(1);
	GrayScale();
	WriteImage(convertedImage);
}

void Converter::ReadImage(std::ifstream& originalImage){
	originalImage.ignore(100, '\n');
	int width, height;
	originalImage >> width;
	originalImage >> height;
	originalImage.ignore(100, '\n');
	originalImage.ignore(100, '\n');
	toConvert = new Image(height, width);
	converted = new Image(height, width);
	int toCheck, red, green, blue;
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			originalImage >> toCheck;
			red = CheckRange(toCheck, 255);
			originalImage >> toCheck;
			green = CheckRange(toCheck, 255);
			originalImage >> toCheck;
			blue = CheckRange(toCheck, 255);
			toConvert->SetPixel(row, col, red, green, blue);
			ESCREVEMEMLOG((long int) (toConvert->GetPixelAddress(row, col)), sizeof(Pixel), 0);
		}
	}
}

void Converter::WriteImage(std::ofstream& convertedImage){
	convertedImage << "P2" << std::endl;
	int width = converted->GetWidth();
	int height = converted->GetHeight();
	convertedImage << width << " " << height << std::endl;
	convertedImage << 49 << std::endl;
	int colourValue;
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			colourValue = converted->GetPixel(row, col).GetR();
			LEMEMLOG((long int) (converted->GetPixelAddress(row, col)), sizeof(Pixel), 1);
			convertedImage << colourValue;
			if(col != (width - 1)){
				convertedImage << " ";
			}
		}
		convertedImage << std::endl;
	}
}

int Converter::CheckRange(int toCheck, int range){
	erroAssert(toCheck >= 0, "Menor do que o valor mínimo permitido.");
	erroAssert(toCheck <= range, "Maior do que o valor máximo permitido.");
	return toCheck;
}