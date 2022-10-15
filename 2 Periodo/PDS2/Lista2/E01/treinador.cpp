#include "treinador.hpp"

Treinador::Treinador(string _nome) : nome(_nome){}

Treinador::~Treinador(){
	for(auto& it : evolution_balls){
		delete it;
	}
	evolution_balls.clear();
	
	for(auto& it : health_balls){
		delete it;
	}
	health_balls.clear();
}

HealthBall* Treinador::selecionarHealthBall(int _id){
	for(uint i = 0; i <= health_balls.size() ; i++){
		if(health_balls[i]->getId() == _id){
			return health_balls[i];
		}
	}
	return nullptr;
}

EvolutionBall* Treinador::selecionarEvolBall(int _id){
	for(uint i = 0; i <= evolution_balls.size() ; i++){
		if(evolution_balls[i]->getId() == _id){
			return evolution_balls[i];
		}
	}
	return nullptr;

}

void Treinador::adicionarPokebola(HealthBall* pokebola){
	health_balls.push_back(pokebola);
}

void Treinador::adicionarPokebola(EvolutionBall* pokebola){
	evolution_balls.push_back(pokebola);
}

void Treinador::listarPokemons(){
	int pokebolas = evolution_balls.size() + health_balls.size();
	cout << "Treinador: " << nome << endl;
	if(pokebolas == 0){
		cout << "O treinador não possui pokebolas" << endl;
	}
	else{
		for(int i = 0; i < pokebolas; i++){
			Pokebola* atual;
			for(uint j = 0; j < health_balls.size(); j++){
				atual = health_balls[j];
				listarPokemonsHelper(*atual, "HealthBall", i);
			}
			for(uint k = 0; k < evolution_balls.size(); k++){
				atual = evolution_balls[k];
				listarPokemonsHelper(*atual, "EvolutionBall", i);
			}
		}
	}

}

void Treinador::listarPokemonsHelper(Pokebola& atual, string tipo, int id){
	if(atual.getId() == id){
		cout << tipo << " ID: " << id << endl;
		if(atual.pokemonCapturado()){
			atual.chamarInfo();
		}
		else{
			cout << "A pokebola não possui um pokemon" << endl;
		}
	}

}