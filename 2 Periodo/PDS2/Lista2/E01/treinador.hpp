#ifndef TREINADOR_H
#define TREINADOR_H

#include <iostream>
#include <string>
#include <vector>
#include "evolutionBall.hpp"
#include "healthBall.hpp"

using namespace std;

class Treinador{
	private:
	string nome;
	vector<EvolutionBall*> evolution_balls;
	vector<HealthBall*> health_balls;

	public:
	Treinador(std::string _nome);
	~Treinador();
	HealthBall* selecionarHealthBall(int _id);
	EvolutionBall* selecionarEvolBall(int _id);
	void adicionarPokebola(HealthBall* pokebola);
	void adicionarPokebola(EvolutionBall* pokebola);
	void listarPokemons();
	void listarPokemonsHelper(Pokebola& atual, string tipo, int id);
};



#endif