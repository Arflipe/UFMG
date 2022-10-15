#include "avaliacao_basica_atendimento.hpp"
#include <iostream>
#include "FilaAtendimento.hpp"
#include "Cliente.hpp"

using namespace std;

void adicionarCliente(FilaAtendimento* fila){
	string nome;
	int idade;
	cin >> nome;
	cin >> idade;
	fila->adicionar_cliente(nome, idade);
}

void chamarCliente(FilaAtendimento* fila){
	fila->chamar_cliente();
}

void tempoEspera(FilaAtendimento* fila){
	int senha;
	cin >> senha;
	fila->estimativa_tempo_espera(senha);
}

void imprimirFila(FilaAtendimento* fila){
	fila->imprimir_fila();
}

int main(){
	FilaAtendimento fila = FilaAtendimento();
	char comando;
	while(cin >> comando){
		switch (comando){
		case 'a':
			adicionarCliente(&fila);
			break;
		case 'c':
			chamarCliente(&fila);
			break;
		case 'e':
			tempoEspera(&fila);
			break;
		case 'p':
			imprimirFila(&fila);
			break;
		case 'b':
			avaliacao_basica();
			break;
		default:
			break;
		}
	}

}