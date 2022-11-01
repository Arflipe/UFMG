#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

class Image{
	private:
	int height, width;
	Pixel** matrix;

	public:
	Image(int height, int width);
	~Image();
	int GetHeight();
	int GetWidth();
	Pixel GetPixel(int row, int col);
	const Pixel* GetPixelAddress(int row, int col);
	void SetPixel(int row, int col, int red, int green, int blue);
	void SetPixel(int row, int col, int gray);
};

#endif