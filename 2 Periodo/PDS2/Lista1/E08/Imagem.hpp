#ifndef IMAGEM_H
#define IMAGEM_H

#include "Pixel.hpp"
#include <memory>

class Imagem{
	public:
	void initialize_image(int width, int height);
	void fill(int row, int col, string pixel);
	void to_grayscale();
	void grayscale_thresholding(int lim);
	void show();

	private:
	int _width, _height;
	vector<Pixel> _imagem;
};

#endif