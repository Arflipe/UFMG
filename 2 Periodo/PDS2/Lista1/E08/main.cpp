#include "avaliacao_basica_imagem.hpp"
#include "Imagem.hpp"

int main() {
	Imagem _imagem;
	char comando;
	while(cin >> comando){
		int height, width;
		string pixel;
		int lim;
		switch (comando){
		case 'i':
			cin >> width >> height;
			_imagem.initialize_image(width, height);
			break;
		case 'p':
			for(int row = 0; row < height; row++){
				for(int col = 0; col < width; col++){
					cin >> pixel;
					_imagem.fill(row, col, pixel);
				}
			}
			break;
		case 's':
			_imagem.show();
			break;
		case 'g':
			_imagem.to_grayscale();
			break;
		case 't':
			cin >> lim;
			_imagem.grayscale_thresholding(lim);
			break;
		case 'b':
			avaliacao_basica();
			break;
		default:
			break;
		}
	}
	return 0;
}

