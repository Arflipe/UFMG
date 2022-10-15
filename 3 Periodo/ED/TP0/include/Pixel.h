#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>


class Pixel{
	private:
	int red, green, blue;

	public:
	Pixel();
	int GetR();
	int GetG();
	int GetB();
	void SetRGB(int red, int green, int blue);;
	void SetRGB(int gray);
};

#endif