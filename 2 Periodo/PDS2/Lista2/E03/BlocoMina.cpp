#include "BlocoMina.hpp"

BlocoMina::~BlocoMina(){}

BlocoMina::BlocoMina(vector<vector<Bloco*>>& tabuleiro, Coordenada _coord){
	coord = _coord;
	valor = -1;
	vector<Coordenada> adjacentes;
	coord.getCoordenadasAdjacentes(adjacentes, tabuleiro.size(), tabuleiro[0].size());
	for(uint i = 0; i < adjacentes.size(); i++){
		int row = adjacentes[i].getRow();
		int col = adjacentes[i].getCol();
		int valor = tabuleiro[row][col]->getValor();
		if(valor == 0){
			delete tabuleiro[row][col];
			Coordenada coord(row, col);
			tabuleiro[row][col] = new BlocoContador(coord);
		}
		else if(valor > 0){
			BlocoContador* bc = dynamic_cast<BlocoContador*>(tabuleiro[row][col]);
			bc->incrementarValor();
		}
	}
}

bool BlocoMina::revelar(vector<vector<Bloco*>>& tabuleiro){
	revelado = true;
	for(uint cR = 0; cR < tabuleiro.size(); cR++){
		for(uint cC = 0; cC < tabuleiro[0].size(); cC++){
			if(!tabuleiro[cR][cC]->ehRevelado()){
				tabuleiro[cR][cC]->revelar(tabuleiro);
			}
		}
	}
	return false;
}