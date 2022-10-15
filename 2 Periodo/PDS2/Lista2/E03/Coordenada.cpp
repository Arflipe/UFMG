#include "Coordenada.hpp"

Coordenada::Coordenada() : row(0), col(0){}

Coordenada::Coordenada(int _row, int _col) : row(_row), col(_col){}

int Coordenada::getRow(){
	return row;
}

int Coordenada::getCol(){
	return col;
}

void Coordenada::getCoordenadasAdjacentes(vector<Coordenada>& adjacentes, int rowBoundary, int colBoundary){
	for(int cR = (row - 1); cR <= (row + 1); cR++){
		for(int cC = (col - 1); cC <= (col + 1); cC++){
			if(isInBoundary(cR, rowBoundary) && isInBoundary(cC, colBoundary) && isDifferent(cR, cC)){
				adjacentes.push_back(Coordenada(cR, cC));
			}
		}
	}
}

bool Coordenada::isInBoundary(int current, int boundary){
	if(current >= 0 && current < boundary){
		return true;
	}
	return false;
}

bool Coordenada::isDifferent(int cR, int cC){
	if((cR == row) && (cC == col)){
		return false;
	}
	return true;
}