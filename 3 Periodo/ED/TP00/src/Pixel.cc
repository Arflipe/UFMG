#include "Pixel.h"

Pixel::Pixel(){}


int Pixel::GetR(){
	return red;
}

int Pixel::GetG(){
	return green;
}

int Pixel::GetB(){
	return blue;
}

void Pixel::SetRGB(int red, int green, int blue){
	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Pixel::SetRGB(int gray){
	red = gray;
	green = gray;
	blue = gray;
}