#include "evolutionBall.hpp"

EvolutionBall::EvolutionBall(double _taxaPoder): taxaPoder(_taxaPoder), habilidadeUsada(false){}

bool EvolutionBall::evoluirPokemon(){
	if((!tempokemon) || (habilidadeUsada)){
		return false;
	}
	else{	
		pokemon->evoluir(taxaPoder);
		habilidadeUsada = true;
		return true;
	}
}