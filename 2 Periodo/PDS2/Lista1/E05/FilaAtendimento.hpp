#ifndef FILAATENDIMENTO_H
#define FILAATENDIMENTO_H

#include "Cliente.hpp"

using namespace std;

struct Node{
	Cliente* _cliente;
	Node* _clienteAnt;
	Node* _proxCliente;
};

struct FilaAtendimento{
	int tamanho = 0;
	int prioritario = 0;
	int senha = 1;
	Node* head = nullptr;
	Node* tail = nullptr;

	// Fila();
	void adicionar_cliente(string nome, int idade);
	Cliente* chamar_cliente();
	void estimativa_tempo_espera(int senha);
	void imprimir_fila();

	void filaPrioritariaHelper(Node* prio, Node* atual, int prioRemaining, int remaining);
	void mudarSenhaHelper(Node* atual, int remaining, int operation);
	int estimativaTempoEsperaHelper(int atual);
	Cliente* imprimirFilaHelper(int lugar);
};




#endif