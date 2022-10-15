#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

using namespace std;

class Pokemon{
	protected:
	string nome;
	string tipo;
	double forcaAtaque;
	double forcaDefesa;
	string proxEvolucao;
	double saude;

	public:
	Pokemon();
	Pokemon(string _nome, string _tipo, string _pEvol, double _fA, double _fD, double _saude);
	string getNome();
	void maxSaude();
	void info();

};

#endif