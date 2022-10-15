#include "Time.hpp"

Time::Time(string nome){
	_nome = nome;
}

void Time::adicionar_jogador(string nome, string posicao, int salario){
	Jogador* aux = new Jogador(nome, posicao, salario);
	_jogadores.push_back(*aux);
	tamanho++;
}

void Time::imprimir_lista_jogadores(){
	cout << _nome << endl;
	sort(_jogadores.begin(), _jogadores.end(), [](Jogador a, Jogador b){
		return a._salario > b._salario;
	});
	for(int i = 0; i < tamanho; i++){
		_jogadores[i].imprimir_dados();
	}
}

void Time::imprimir_folha_salarial_consolidada(){
	int somasalarios = 0;
	for(int i = 0; i < tamanho; i++){
		somasalarios += _jogadores[i]._salario;
	}
	cout << _nome << "	" << somasalarios << endl;
}

