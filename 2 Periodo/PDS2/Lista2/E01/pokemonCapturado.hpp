#ifndef POKEMONCAPTURADO_H
#define POKEMONCAPTURADO_H

#include "pokemon.hpp"

class PokemonCapturado : public Pokemon{
	private:
	bool evoluido;
	bool dormindo;

	public:
	PokemonCapturado();
	PokemonCapturado(Pokemon& _pok);
	void evoluir(double taxaPoder);
	void setDormindo(bool _dormindo);

};

#endif