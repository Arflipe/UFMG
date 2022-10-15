#ifndef BLOCO_H
#define BLOCO_H

#include "Coordenada.hpp"
#include <vector>
#include <string>

using namespace std;

class Bloco{
	protected:
	Coordenada coord;
	bool revelado;
	int valor;
	
	public:
	Bloco();
	Bloco(Coordenada _coord);
	virtual ~Bloco();
	virtual bool revelar(vector<vector<Bloco*>>& tabuleiro);
	string getSimbolo();
	bool ehRevelado();
	int getValor();
};

#endif