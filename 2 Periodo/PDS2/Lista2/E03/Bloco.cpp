#include "Bloco.hpp"

Bloco::Bloco() : revelado(false){}

Bloco::Bloco(Coordenada _coord) : coord(_coord), revelado(false), valor(0){}

Bloco::~Bloco(){}

bool Bloco::revelar(vector<vector<Bloco*>>& tabuleiro){
	revelado = true;
	vector<Coordenada> adjacentes;
	coord.getCoordenadasAdjacentes(adjacentes, tabuleiro.size(), tabuleiro[0].size());
	for(uint i = 0; i < adjacentes.size(); i++){
		int row = adjacentes[i].getRow();
		int col = adjacentes[i].getCol();
		Bloco* bloco = tabuleiro[row][col];
		if(!bloco->ehRevelado()){
			bloco->revelar(tabuleiro);
		}
	}
	return true;
}

string Bloco::getSimbolo(){
	if(!revelado){
		return "#";
	}
	else if(valor == -1){
		return "*";
	}
	return to_string(valor);
}

bool Bloco::ehRevelado(){
	return revelado;
}

int Bloco::getValor(){
	return valor;
}