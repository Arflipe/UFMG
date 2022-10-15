#include "pokemon.hpp"

Pokemon::Pokemon(){}

Pokemon::Pokemon(string _nome, string _tipo, string _pEvol, double _fA, double _fD, double _saude){
	nome = _nome;
	tipo = _tipo;
	forcaAtaque = _fA;
	forcaDefesa = _fD;
	proxEvolucao = _pEvol;
	saude = _saude;
}

string Pokemon::getNome(){
	return nome;
}

void Pokemon::maxSaude(){
	saude = 100;
}

void Pokemon::info(){
	cout << "Pokemon: " << nome << ", " << tipo << ", " << forcaAtaque << ", " << forcaDefesa << ", " << saude << endl;
}