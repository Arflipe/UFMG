#include "FilaAtendimento.hpp"

void FilaAtendimento::adicionar_cliente(string nome, int idade){
	Node* aux = new Node;
	aux->_cliente = new Cliente(idade, nome);
	bool isprioritario = aux->_cliente->eh_prioritario();
	aux->_cliente->_senha = senha;
	senha++;

	if(head == nullptr){
		head = aux;
		tail = aux;
		head->_clienteAnt = nullptr;
		head->_proxCliente = nullptr;
	}
	else if(isprioritario && prioritario != tamanho){
		filaPrioritariaHelper(aux, head, prioritario, tamanho);
	}
	else{
		tail->_proxCliente = aux;
		aux->_clienteAnt = tail;
		tail = aux;
		tail->_proxCliente = nullptr;
	}

	tamanho++;
	if(isprioritario){
		prioritario++;
	}
}

Cliente* FilaAtendimento::chamar_cliente(){
	if(head == nullptr){
		cout << "Fila vazia!" << endl;
		return nullptr;
	}
	Node* aux = head;
	bool isprioritario = head->_cliente->eh_prioritario();
	if(tamanho > 1){
		head = head->_proxCliente;
		head->_clienteAnt = nullptr;
	}
	else{
		head = nullptr;
	}
	tamanho--;
	if(isprioritario){
		prioritario--;
	}
	return aux->_cliente;
}

void FilaAtendimento::estimativa_tempo_espera(int consultar){
	int espera = 0;
	Node* aux = head;
	while(aux->_cliente->_senha != consultar){
		espera += aux->_cliente->tempo_estimado_atendimento();
		aux = aux->_proxCliente;
	}
	cout << "Tempo estimado para atender " << aux->_cliente->_nome << " eh " << espera << " minutos." << endl;
}

void FilaAtendimento::imprimir_fila(){
	for(int lugar = 1; lugar <= tamanho; lugar++){
		imprimirFilaHelper(lugar)->imprimir_dados();
	}
}

Cliente* FilaAtendimento::imprimirFilaHelper(int lugar){
	Node* aux = head;
	for(int i = 1; i < lugar; i++){
		aux = aux->_proxCliente;
	}
	return aux->_cliente;
}

void FilaAtendimento::filaPrioritariaHelper(Node* prio, Node* atual, int prioRemaining, int remaining){
	if(!prioRemaining){
		prio->_proxCliente = atual;
		if(atual->_clienteAnt == nullptr){
			head = prio;
			atual->_clienteAnt = prio;
		}
		else{
			prio->_clienteAnt = atual->_clienteAnt;
			prio->_clienteAnt->_proxCliente = prio;
			atual->_clienteAnt = prio;
		}
	}
	else{
		filaPrioritariaHelper(prio, atual->_proxCliente, (prioRemaining - 1), (remaining - 1));
	}
}