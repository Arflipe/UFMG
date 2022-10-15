#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>

using namespace std;

struct Jogador{
	string _nome;
	string _posicao;
	int _salario;

	Jogador(string nome, string posicao, int salario);
	void imprimir_dados();
};

#endif