#include "BlocoContador.hpp"

BlocoContador::~BlocoContador(){}

BlocoContador::BlocoContador(Coordenada _coord){
	coord = _coord;
	valor = 1;
}

bool BlocoContador::revelar(vector<vector<Bloco*>>& tabuleiro){
	revelado = true;
	return true;
}

void BlocoContador::incrementarValor(){
	valor += 1;
}