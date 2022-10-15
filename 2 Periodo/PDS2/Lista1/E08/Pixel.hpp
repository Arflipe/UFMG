#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Pixel{
	public:
	Pixel();
	Pixel(int red, int green, int blue);
	void set_rgb(int red, int green, int blue);
	vector<int> get_rgb();
	void print();
	
	private:
	int _red, _green, _blue;
};


#endif