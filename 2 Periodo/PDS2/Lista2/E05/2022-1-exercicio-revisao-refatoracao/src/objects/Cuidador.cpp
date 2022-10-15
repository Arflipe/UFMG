#include "Cuidador.hpp"

// Destrutor de cuidador
Cuidador::~Cuidador(){
	for(Animal* a : animaisCuidados){
		delete a;
	}
}

// Construtor para o cuidador
Cuidador::Cuidador(string _nome) : nome(_nome){};

// Coloca o cuidador a encargo do animal passado
void Cuidador::addAnimal(Animal* &_animal){
	animaisCuidados.push_back(_animal);
}

// Descreve a refeição do animal passado
void Cuidador::descreverRefeicao(string nomeAnimal){
	for(Animal* a : animaisCuidados){
		if(a->getNome() == nomeAnimal){
			cout << nomeAnimal << " " << a->getDescAlimentacao() << endl << endl;
		}
	}
}

// Retorna true se cuidador estiver encarregado do animal passado
bool Cuidador::encarregadoAnimal(string nomeAnimal){
	for(Animal* a : animaisCuidados){
		if(a->getNome() == nomeAnimal){
			return true;
		}
	}
	return false;
}

// Retorna nome do cuidador
string Cuidador::getNome(){
	return nome;
}