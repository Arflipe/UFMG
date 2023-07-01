#include "distribution.hpp"

// Construtor
DistributionCenter::DistributionCenter(){
	lAlloys = NULL;
}

// Destrutor
DistributionCenter::~DistributionCenter(){
	delete[] lAlloys;
}

// Adiciona um tipo de liga
// @param length: Comprimento da liga
void DistributionCenter::addType(int length){
	alloyLength.push_back(length);
}

// Calcula a menor quantidade de ligas para atender o pedido
// @param request: Comprimento do pedido
int DistributionCenter::distribute(int request){
	sort(alloyLength.begin(), alloyLength.end()); // Começar pelas ligas maiores diminui o número de trocas na função min()
	lAlloys = new int[request + 1]; // Vetor de soluções
	lAlloys[0] = 0;
	for(int i = 1; i <= request; i++){
		lAlloys[i] = INF;
	}
	for(int i = 0; i <= request; i++){ // Calculando todos de 0 ao pedido
		findLeastAlloys(i);
	}
	return lAlloys[request]; 
}

// Encontra a menor quantidade de ligas para o tamanho dado
// @param request: Comprimento do pedido
void DistributionCenter::findLeastAlloys(int request){
	for(int i = (alloyLength.size() - 1); i >= 0; i--){
		if(request - alloyLength[i] >= 0){ // Não pode entregar mais do que o pedido
			lAlloys[request] = min(lAlloys[request], (lAlloys[request - alloyLength[i]] + 1)); // Pela estratégia bottom-up, já temos a solução para o subproblema
		}
	}
}

