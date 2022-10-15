#include "Cliente.hpp"
#include "FilaAtendimento.hpp"

Cliente::Cliente(int idade, string nome){
	_idade = idade;
	_nome = nome;
}

bool Cliente::eh_prioritario(){
	if(_idade >= 60){
		return true;
	}
	else{
		return false;
	}
}

int Cliente::tempo_estimado_atendimento(){
	bool isprioritario = eh_prioritario();
	if(isprioritario){
		return 12;
	}
	else{
		return 8;
	}

};

void Cliente::imprimir_dados(){
	cout << _senha << "	" << _nome << "	" << _idade << endl;
};	