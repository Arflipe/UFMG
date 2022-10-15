#include <fstream>

#include "Animal.hpp"
#include "Herpestidae.hpp"
#include "Ursidae.hpp"
#include "Cuidador.hpp"
#include "Alimentacao.hpp"
#include "ReservaAnimal.hpp"

// Função para ler uma linha inteira não nula do arquivo
string lerLinha(ifstream& file){
	string linha;
	getline(file, linha);
	if(linha.empty()){
		linha = lerLinha(file);
	}
	return linha;
}


void adicionarCuidadores(ReservaAnimal& reserva, ifstream& file){
	int numCuidadores; // Número de cuidadores a serem adicionados
	file >> numCuidadores;

	for(int i = 0; i < numCuidadores; i++){ // Adicionando cuidadores
		string nomeCuidador = lerLinha(file);
		Cuidador* c = new Cuidador(nomeCuidador);
		reserva.addCuidador(c);
	}
}

void adicionarAnimais(ReservaAnimal& reserva, ifstream& file){
	int numAnimais; // Número de animais a serem adicionados
	file >> numAnimais;

	for(int i = 0; i < numAnimais; i++){ // Adicionar animais
		string nomeAnimal = lerLinha(file);
		
		int idade;
		file >> idade;

		string familia = lerLinha(file);

		Animal* a;
		if(familia == "Ursidae"){
			a = new Ursidae(nomeAnimal, idade);
		}
		else if(familia == "Herpestidae"){
			a = new Herpestidae(nomeAnimal, idade);
		}

		bool temEspecie;
		file >> temEspecie;

		string especie;
		if(temEspecie){
			especie = lerLinha(file);
			a->setEspecie(especie);
		}

		string cuidador = lerLinha(file);

		reserva.addAnimal(cuidador, a);
	}
}

void listAnimais(ReservaAnimal& reserva, ifstream& file){
	int numAnimais; // Número de animais a serem listados
	file >> numAnimais;

	vector<string> nomeAnimais; // Listar animais
	for(int i = 0; i < numAnimais; i++){
		string nomeAnimal = lerLinha(file);
		nomeAnimais.push_back(nomeAnimal);
	}

	reserva.listarAnimais(nomeAnimais);
}

void refeicao(ReservaAnimal& reserva, ifstream& file){
	int numAnimais; // Número de animais a serem alimentados
	file >> numAnimais;

	for(int i = 0; i < numAnimais; i++){ // Alimentar animais
		string nomeAnimal = lerLinha(file);

		int numPorcoes;
		file >> numPorcoes;

		string descricao = lerLinha(file);

		reserva.alimentar(nomeAnimal, numPorcoes, descricao);
	}
}

void relatorioRefeicao(ReservaAnimal& reserva, ifstream& file){
	int numRelatorios; // Número de relatorios a serem exibidos
	file >> numRelatorios;

	vector<string> nomeAnimais;
	for(int i = 0; i < numRelatorios; i++){ // Exibir relatórios
		string nomeAnimal = lerLinha(file);
		nomeAnimais.push_back(nomeAnimal);
	}

	reserva.relatorioAlimentacao(nomeAnimais);
}

void relatorioPeso(ReservaAnimal& reserva, ifstream& file){
	vector<string> tipoComidas;
	tipoComidas.push_back("Ração");
	tipoComidas.push_back("Peixe");

	reserva.relatorioKgComida(tipoComidas);
}

int main()
{
	ifstream file;
	file.open("ReservaPadrão.txt"); // Abrindo o arquivo utilizado para ler os dados

	ReservaAnimal reserva; // Inicializando a ReservaAnimal
	
	bool continuar = true;
	while(continuar){
		char comando;
		file >> comando;

		switch (comando){
		case 'c': { // Adicionar cuidadores à reserva
			adicionarCuidadores(reserva, file);
			break;
		}

		case 'a': { // Adicionar animais à reserva e aos respectivos cuidadores
			adicionarAnimais(reserva, file);
			break;
		}

		case 'l': { //Listar animais passados
			listAnimais(reserva, file);
			break;
		}

		case 'r': { // Alimentar animais passados
			refeicao(reserva, file);
			break;
		}

		case 't': { // Imprimir o relatório de alimentação dos animais passados
			relatorioRefeicao(reserva, file);
			break;
		}

		case 'p': { // Imprimir o relatório de Kgs consumidos dos animais passados
			relatorioPeso(reserva, file);
			break;
		}

		case 'q': { // Encerrar o programa
			continuar = false;
			break;
		}

		default:
			break;
		}
	}
	file.close();
	return 0;
}
