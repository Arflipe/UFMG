#include "pokebola.hpp"

int Pokebola::count = 0;

Pokebola::Pokebola(){
	id = count;
	count++;
	pokemon = new PokemonCapturado;
	tempokemon = false;
}

Pokebola::~Pokebola(){
	delete pokemon;
}

int Pokebola::getId(){
	return id;
}

void Pokebola::guardarPokemon(){
	if(tempokemon){
		pokemon->setDormindo(true);
	}
}

Pokemon* Pokebola::liberarPokemon(){
	if(!tempokemon){
		return nullptr;
	}
	else{
		pokemon->setDormindo(false);
		return pokemon;
	}
}

bool Pokebola::capturar(Pokemon& _pokemon){
	double capturar = ((double) rand() / (RAND_MAX));
	if(capturar > 0.5){
		*pokemon = _pokemon;
		tempokemon = true;
		return true;
	}
	else{
		return false;
	}
}

bool Pokebola::pokemonCapturado(){
	return tempokemon;
}

void Pokebola::chamarInfo(){
	pokemon->info();
}