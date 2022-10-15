#ifndef REGISTRONBA_H
#define REGISTRONBA_H

#include "Time.hpp"
#include <map>

struct RegistroNBA{
	map<string, Time> _registro;

	void adicionar_time(string nome);
	void adicionar_jogador(string nome_time, string nome_jogador, string posicao, int salario);
	void imprimir_lista_jogadores_time(string nome_time);
	void imprimir_folha_consolidada_time(string nome_time);
	void imprimir_folha_salarial_geral();
};

#endif