#include "healthBall.hpp"

HealthBall::HealthBall(double _intervalo) : intervalo(_intervalo){}

bool HealthBall::recuperarPokemon(){
	time_t atual = time(NULL);
	double diferenca = difftime(atual, ultimoUso);
	if((!tempokemon) || (diferenca < intervalo)){
		return false;
	}
	else{
		pokemon->maxSaude();
		ultimoUso = atual;
		return true;
	}
}