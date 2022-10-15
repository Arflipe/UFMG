#include "Imagem.hpp"


void Imagem::initialize_image(int width, int height){
	_width = width;
	_height = height;
	for(int i = 0; i < (width * height); i++){
		_imagem.push_back(Pixel());
	}
}

void Imagem::fill(int row, int col, string pixel){
	int red, green, blue;
	string aux;
	aux = pixel.substr(0, 3);
	red = stoi(aux);
	aux = pixel.substr(3, 3);
	green = stoi(aux);
	aux = pixel.substr(6, 3);
	blue = stoi(aux);
	_imagem[(_width * row) + col].set_rgb(red, green, blue);
}

void Imagem::to_grayscale(){
	vector<int> pixel;
	int gray;
	for(int i = 0; i < (_width * _height); i++){
		pixel = _imagem[i].get_rgb();
		gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
		_imagem[i].set_rgb(gray, gray, gray);
	}
}

void Imagem::grayscale_thresholding(int lim){
	vector<int> pixel;
	for(int i = 0; i < (_width * _height); i++){
		pixel = _imagem[i].get_rgb();
		if(pixel[0] > lim){
			_imagem[i].set_rgb(255, 255, 255);
		}
		else{
			_imagem[i].set_rgb(0, 0, 0);
		}
	}
}

void Imagem::show(){
	for(int row = 0; row < _height; row++){
		for(int col = 0; col < _width; col++){
			_imagem[(_width * row) + col].print();
			if(col != (_width - 1)){
				cout << " ";
			}
		}
		cout << endl;
	}
}