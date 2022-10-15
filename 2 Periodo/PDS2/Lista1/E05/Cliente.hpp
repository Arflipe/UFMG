#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

struct Cliente{
	int _idade, _senha;
	string _nome;

	Cliente(int _idade, string nome);
	bool eh_prioritario();
	int tempo_estimado_atendimento();
	void imprimir_dados();
};



#endif