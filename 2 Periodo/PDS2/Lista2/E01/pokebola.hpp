#ifndef POKEBOLA_H
#define POKEBOLA_H

#include <iostream>
#include <cstdlib>
#include "pokemon.hpp"
#include "pokemonCapturado.hpp"

class Pokebola{
	private:
	static int count;

	protected:
	int id;
	PokemonCapturado* pokemon;
	bool tempokemon;

	public:
	Pokebola();
	~Pokebola();
	int getId();
	void guardarPokemon();
	Pokemon* liberarPokemon();
	bool capturar(Pokemon& _pokemon);
	bool pokemonCapturado();
	void chamarInfo();

};

#endif