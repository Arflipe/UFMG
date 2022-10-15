#include "ReservaAnimal.hpp"

// Destrutor de reservaanimal
ReservaAnimal::~ReservaAnimal(){
	for(Cuidador* c : cuidadores){
		delete c;
	}
}

// Adiciona cuidador
void ReservaAnimal::addCuidador(Cuidador* &cuidador){
	cuidadores.push_back(cuidador);
}

// Adiciona animal e coloca um cuidador encarregado do animal
void ReservaAnimal::addAnimal(string nomeCuidador, Animal* &animal){
	animais[animal->getNome()] = animal;
	for(Cuidador* c : cuidadores){
		if(c->getNome() == nomeCuidador){
			c->addAnimal(animal);
		}
	}
}

// Alimenta animais passados
void ReservaAnimal::alimentar(string nomeAnimal, double numPorcoes, string descricao){
	Animal* a = getAnimal(nomeAnimal);
	if(kgComidaGasto.count(a->getComida()) == 0){
		kgComidaGasto[a->getComida()] = 0;
	}
	kgComidaGasto[a->getComida()] += a->comer(numPorcoes, descricao);
}

// Lista animais passados
void ReservaAnimal::listarAnimais(vector<string> nomeAnimais){
	for(string nomeAnimal : nomeAnimais){
		Animal* a = getAnimal(nomeAnimal);
		a->print();
	}
}

// Imprime o relatório de alimentação dos animais passados
void ReservaAnimal::relatorioAlimentacao(vector<string> nomeAnimais){
	cout << " " << endl << " " << endl << "--------------------------------";
	cout << endl << endl << "Relatorio das alimentações "<< endl << endl;
	for(string nomeAnimal : nomeAnimais){
		Cuidador* c = getCuidador(nomeAnimal);
		cout << "Animal: " << nomeAnimal << endl;
		cout << " Cuidador: " << c->getNome() << endl;
		cout << " Descricao: ";
		c->descreverRefeicao(nomeAnimal);
	}
}

// Imprime o relatório do Kg consumido dos tipos de comida passados
void ReservaAnimal::relatorioKgComida(vector<string> tipoComidas){
	cout << " " << endl << " " << endl << "--------------------------------";
	cout << endl << endl << "Relatorio de kg de comida gastos " << endl;
	for(string tipoComida : tipoComidas){
		map<string, int>::iterator it;
		it = kgComidaGasto.find(tipoComida);
		cout << endl << "Tipo de comida: " << it->first;
		cout << endl << "Kg consumidos: " << it->second << endl;
	}
}

// Retorna o animal por nome
Animal* ReservaAnimal::getAnimal(string nomeAnimal){
	map<string, Animal*>::iterator it;
	it = animais.find(nomeAnimal);
	return it->second;
}

// Retorna o cuidador pelo nome de um animal
Cuidador* ReservaAnimal::getCuidador(string nomeAnimal){
	for(Cuidador* c : cuidadores){
		if(c->encarregadoAnimal(nomeAnimal)){
			return c;
		}
	}
	return nullptr;
}