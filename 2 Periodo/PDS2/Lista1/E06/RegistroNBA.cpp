#include "RegistroNBA.hpp"

void RegistroNBA::adicionar_time(string nome){

	this->_registro.insert(pair<string, Time>(nome, Time(nome)));
}

void RegistroNBA::adicionar_jogador(string nome_time, string nome_jogador, string posicao, int salario){
	map<string, Time>::iterator it;
	it = _registro.find(nome_time);
	if(it == _registro.end()){
		adicionar_time(nome_time);
	}
	this->_registro[nome_time].adicionar_jogador(nome_jogador, posicao, salario);
}

void RegistroNBA::imprimir_lista_jogadores_time(string nome_time){
	cout << nome_time << endl;
	this->_registro[nome_time].imprimir_lista_jogadores();
}

void RegistroNBA::imprimir_folha_consolidada_time(string nome_time){
	this->_registro[nome_time].imprimir_folha_salarial_consolidada();
}

void RegistroNBA::imprimir_folha_salarial_geral(){
	for(auto &it : this->_registro){
		it.second.imprimir_folha_salarial_consolidada();
	}
}