#include "graph.hpp"

using namespace std;

// Adiciona os vértices no vector
// @param numVertices Número de vértices no grafo
Graph::Graph(int numVertices) {
	for(int i = 0; i < numVertices; i++){
		Vertex v;
		adjList.push_back(v);
	}
	distanceArr = new int[adjList.size()];
}

// Libera a memória alocada para o vetor de distâncias
Graph::~Graph(){
	delete[] distanceArr;
}

// Adiciona arestas no grafo
// @param vertex Vértice inicial
// @param distanceTo Distancia entre os vértices
// @param adjVertex Vértice final
void Graph::addAdj(int vertex, int distanceTo, int adjVertex){
	adjList[vertex - 1].addNewAdjacent(distanceTo, (adjVertex - 1));
}

// Retorna a distância do menor caminho entre o primeiro e último vértice por meio de um caminho par de arestas
int Graph::findSmallestEvenRoute(){ // Dijkstra adaptado
	distanceArr[0] = 0;
	for(uint i = 1; i < adjList.size(); i++){
		distanceArr[i] = 1;
	}
	pq.push(make_pair(0, 0));
	for(uint i = 0; i < adjList.size(); i++){ // Necessita de no máximo N iterações para achar os menores caminhos para todos os vértices
		int currentVertex;
		if(!pq.empty()){ // Por algum motivo, se é feito um pop() em um priority_queue que já está vazio, ele enche. Dessa maneira, é necessário checar antes se ele está vazio, ou então entra em loop infinito
			do{
				currentVertex = pq.top().second;
				pq.pop();
			} while(adjList[currentVertex].visited && !pq.empty()); // Olhar somente os que não foram visitados
		}
		searchCombinations(currentVertex, distanceArr[currentVertex]);
		if(adjList[adjList.size() - 1].visited){
			return (distanceArr[adjList.size() - 1] * -1); // Se marcar o último vértice como visitado no meio da execução, não precisa terminar
		}
	}
	return (distanceArr[adjList.size() - 1] * -1);
}

// Marca o vértice como visitado e varre todos os vizinhos dele para chamar chama o método updateDistances para cada um 
// @param vertex Vértice a ser marcado como visitado e de onde serão analisados os vizinhos
// @param initDistance Distância do menor caminho entre o vértice 0 e o vértice passado como parâmetro
void Graph::searchCombinations(int vertex, int initDistance){
	for(list<pair<int,int>>::iterator it = adjList[vertex].adjacent.begin(); it != adjList[vertex].adjacent.end(); it++){
		updateDistances((*it).second, ((*it).first + initDistance));
	}
	adjList[vertex].visited = true;
}

// Depois de sair de um vértice já visitado (v) e escolher um caminho para um vizinho (a1), verifica se a distância para alcançar cada vizinho (a2) passando por a1 é menor que a já conhecida para a2 e, se for, atualiza o vetor distância 
// @param vertex Vértice adjacente a v
// @param initDistance Distância do menor caminho entre o vértice 0 e o vizinho de v
void Graph::updateDistances(int vertex, int initDistance){
	for(list<pair<int,int>>::iterator it = adjList[vertex].adjacent.begin(); it != adjList[vertex].adjacent.end(); it++){
		int v = (*it).second;
		if(!adjList[v].visited){
			int dis = (*it).first + initDistance; // Soma as distâncias para simular uma só aresta, criada pela combinação das arestas v-a1 e a1-a2, formando uma v-a1-a2
			if((distanceArr[v] == 1) || (distanceArr[v] < dis)){ // Atualiza o vetor distância e manda o vértice para o heap
				distanceArr[v] = dis;
				pq.push(make_pair(dis, v));
			}
		}
	}
}