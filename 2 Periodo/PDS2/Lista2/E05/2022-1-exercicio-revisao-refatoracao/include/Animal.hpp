#ifndef ANIMAL_H
#define ANIMAL_H

#include "Alimentacao.hpp"

class Animal{
	protected:
	string nome;
	int idade;
	string especie;
	string familia;
	Alimentacao alimentacao;

	public:
	~Animal();
	Animal(string _nome, int _idade, string _familia, int _porcao, string _comida);

	double comer(double numPorcoes, string _descricao);
	void print();
	
	void setEspecie(string _especie);
	
	string getNome();
	string getComida();
	string getDescAlimentacao();
};

#endif