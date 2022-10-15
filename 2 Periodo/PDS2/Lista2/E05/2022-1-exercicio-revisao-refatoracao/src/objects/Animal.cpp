#include "Animal.hpp"

// Destrutor de animal
Animal::~Animal(){}

// Construtor do animal
Animal::Animal(string _nome, int _idade, string _familia, int _porcao, string _comida) : nome(_nome), idade(_idade), familia(_familia){
	alimentacao = Alimentacao(_porcao, _comida);
}

// Alimentar animal
double Animal::comer(double numPorcoes, string descricao){
	alimentacao.setDescricao(descricao);
	return alimentacao.pesoRefeicao(numPorcoes);
}

// Imprime dados do animal
void Animal::print(){
	cout << endl << "[Animal]" << endl;
	cout << "  Nome: " << nome << endl;
	cout << "  Idade: " << idade << endl;
	cout << "  Familia: " << familia << endl;
	if(!especie.empty()){
		cout << "  Especie: " << especie << endl;
	}
}

// Altera a especie do animal
void Animal::setEspecie(string _especie){
	especie = _especie;
}

// Retorna nome do animal
string Animal::getNome(){
	return nome;
}

// Retorna o tipo de comida que o animal come
string Animal::getComida(){
	return alimentacao.getTipo();
}

// Retorna a descrição da alimentação do animal
string Animal::getDescAlimentacao(){
	return alimentacao.getDescricao();
}