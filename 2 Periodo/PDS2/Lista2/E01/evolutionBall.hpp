#ifndef EVOLUTIONBALL_H
#define EVOLUTIONBALL_H

#include "pokebola.hpp"

class EvolutionBall : public Pokebola{
	private:
	double taxaPoder;
	bool habilidadeUsada;

	public:
	EvolutionBall(double _taxaPoder);
	bool evoluirPokemon();
};

#endif