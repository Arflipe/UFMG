#include <iostream>
#include "Coordenada.hpp"
#include <vector>

using namespace std;

int main(){
	int row, col;
	cin >> row;
	col = row;
	vector<Coordenada> adjacentes;
	int co[2];
	cin >> co[0] >> co[1];
	Coordenada coord = Coordenada(co[0], co[1]);
	coord.getCoordenadasAdjacentes(adjacentes, row, col);
	for(Coordenada a : adjacentes){
		cout << a.getRow() << "," << a.getCol() << endl;
	}
}