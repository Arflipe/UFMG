#include "pokemonCapturado.hpp"


PokemonCapturado::PokemonCapturado(){}

PokemonCapturado::PokemonCapturado(Pokemon& _pok) : Pokemon(_pok){
	evoluido = false;
	dormindo = true;
}

void PokemonCapturado::evoluir(double taxaPoder){
	nome = proxEvolucao;
	proxEvolucao.empty();
	taxaPoder += 1;
	forcaAtaque *= taxaPoder;
	forcaDefesa *= taxaPoder;
	evoluido = true;
}

void PokemonCapturado::setDormindo(bool _dormindo){
	dormindo = _dormindo;
}