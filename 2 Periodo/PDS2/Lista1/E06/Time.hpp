#ifndef TIME_H
#define TIME_H

#include "Jogador.hpp"
#include <vector>
#include <algorithm>



struct Time{
	string _nome;
	vector<Jogador> _jogadores;
	int tamanho = 0;

	Time() = default;
	Time(string nome);
	void adicionar_jogador(string nome, string posicao, int salario);
	void imprimir_lista_jogadores();
	void imprimir_folha_salarial_consolidada();
};

#endif
