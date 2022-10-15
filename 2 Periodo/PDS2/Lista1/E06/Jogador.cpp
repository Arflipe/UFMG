#include "Jogador.hpp"

Jogador::Jogador(string nome, string posicao, int salario){
	_nome = nome;
	_posicao = posicao;
	_salario = salario;
}

void Jogador::imprimir_dados(){
	cout << _nome << "	" << _posicao << "	" << _salario << endl;
}
