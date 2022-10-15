#include "Image.h"

Image::Image(int height, int width){
	this->height = height;
	this->width = width;
	matrix = new Pixel *[height];
	for(int row = 0; row < height; row++){
		matrix[row] = new Pixel[width];
	}
}

Image::~Image(){
	for(int row = 0; row < height; row++){
		delete matrix[row];
	}
	delete matrix;
}

int Image::GetHeight(){
	return height;
}

int Image::GetWidth(){
	return width;
}

Pixel Image::GetPixel(int row, int col){
	return matrix[row][col];
}

const Pixel* Image::GetPixelAddress(int row, int col){
	return &matrix[row][col];
}

void Image::SetPixel(int row, int col, int red, int green, int blue){
	matrix[row][col].SetRGB(red, green, blue);
}

void Image::SetPixel(int row, int col, int gray){
	matrix[row][col].SetRGB(gray);
}