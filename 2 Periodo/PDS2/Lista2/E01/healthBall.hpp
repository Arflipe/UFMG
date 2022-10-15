#ifndef HEALTHBALL_H
#define HEALTHBALL_H

#include <ctime>
#include "pokebola.hpp"

class HealthBall : public Pokebola{
	private:
	time_t ultimoUso;
	double intervalo;

	public:
	HealthBall(double _intervalo);
	bool recuperarPokemon();
};

#endif