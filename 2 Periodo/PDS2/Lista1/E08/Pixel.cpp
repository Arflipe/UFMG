#include "Pixel.hpp"

Pixel::Pixel() : Pixel(0,0,0) {};

Pixel::Pixel(int red, int green, int blue) : _red(red), _green(green), _blue(blue){}

void Pixel::set_rgb(int red, int green, int blue){
	_red = red;
	_green = green;
	_blue = blue;
}

vector<int> Pixel::get_rgb(){
	vector<int> pixel;
	pixel.push_back(_red);
	pixel.push_back(_green);
	pixel.push_back(_blue);
	return pixel;
}

void Pixel::print(){
	cout << setfill('0') << setw(3);
	cout << _red;
	cout << setfill('0') << setw(3);
	cout << _green;
	cout << setfill('0') << setw(3);
	cout << _blue;
}