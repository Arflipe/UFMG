#include "graph.hpp"

// Construtor do grafo
// @param numVertices Quantidade de vértices no grafo
// @param jobPos Onde começam os empregos no vector
Graph::Graph(int numVertices, int jobPos){
	this->jobPos = jobPos;
	this->maxFlow = 0;

	// Adicionando vértices
	for(int i = 0; i < numVertices; i++){
		Vertex v;
		adjList.push_back(v);
	}

	// Existe uma aresta do Source para cada pessoa e uma de cada emprego para o Sink
	int i = 0;
	for(; i < jobPos; i++){
		addAdj(numVertices - 2, i); // Aresta do Source
	}
	for(; i < numVertices - 2; i++){
		addAdj(i, numVertices - 1); // Aresta para o Sink
	}
}

// Adiciona as arestas ao grafo
// @param vertex Vértice do qual a aresta sai
// @param adjVertex Vértice para qual a aresta aponta
void Graph::addAdj(int vertex, int adjVertex){
	Edge* e1 = new Edge(adjVertex, 1);
	Edge* e2 = new Edge(vertex, 0);

	// Aresta de ida aponta para a de retorno e vice-versa
	e1->returnEdge = e2;
	e2->returnEdge = e1;

	// Adicionando arestas ao vértice
	adjList[vertex].adjacent.push_back(e1);
	adjList[adjVertex].adjacent.push_back(e2);

	// Contador de arestas
	adjList[vertex].edges++;
	adjList[adjVertex].edges++;
}

// Algoritmo Guloso:
// 1 Passo: Pegar a pessoa com a menor quantidade de vagas disponíveis (arestas)
// 2 Passo: Pegar o emprego disponível com a menor quantidade de candidatos (arestas)
// 3 Passo: Emparelhar os dois
// @return Retorna quantidade máxima de pares
int Graph::greedy(){

	// Marcando todos os vértices exceto o Source e o Sink como não visitados
	for(int i = 0; i < (int) (adjList.size() - 2); i++){
		adjList[i].visited = false;
	}

	// Sink e Source marcados como visitados
	adjList[adjList.size() - 2].visited = true;
	adjList[adjList.size() - 1].visited = true;

	int pairs = 0; // Contagem de pares formados
	for(int i = 0; i < jobPos; i++){

		// Encontrar a pessoa com menor quantidade de arestas, exceto as que possuem só a aresta (Person, Source)
		int leastNC = -1;
		int j = 0;
		for(; j < jobPos; j++){ // Marca a primeira pessoa não visitada como a que possui menor número de arestas
			if(!adjList[j].visited && adjList[j].edges > 1){
				leastNC = j;
				break;
			}
		}
		for(; j < jobPos; j++){ // Itera nas não visitadas para achar a que realmente possui menor número de arestas
			if(!adjList[j].visited && adjList[j].edges < adjList[leastNC].edges && adjList[j].edges > 1){
				leastNC = j;
			}
		}
		if(leastNC != -1){ // Se existe pessoa com uma aresta (Person, Job)

			// Encontrar o emprego com menor quantidade de arestas
			list<Edge*>::iterator it = adjList[leastNC].adjacent.begin();
			it++; // Primeira aresta de cada pessoa é sempre a aresta (Person, Source)
			int leastNCJ = -1;
			for(; it != adjList[leastNC].adjacent.end(); ++it){ // Marca o primeiro emprego não visitado como o que possui menor número de arestas
				if(!adjList[(*it)->adjacent].visited){
					leastNCJ = (*it)->adjacent;
					break;
				}
			}
			for(; it != adjList[leastNC].adjacent.end(); ++it){ // Itera nos não visitados para achar o que realmente possui menor número de arestas
				if(!adjList[(*it)->adjacent].visited && adjList[(*it)->adjacent].edges < adjList[leastNCJ].edges){
					leastNCJ = (*it)->adjacent;
				}
			}
			if(leastNCJ != -1){ // Se existe emprego disponível
				// Marcar a pessoa e o emprego como visitados
				adjList[leastNC].visited = true;
				adjList[leastNCJ].visited = true;
				pairs++; // Emparelhamento feito
				it = adjList[leastNCJ].adjacent.begin();
				it++; // Primeira aresta de cada emprego é sempre a aresta (Job, Sink)
				for(; it != adjList[leastNCJ].adjacent.end(); ++it){ // Para cada pessoa elegível à vaga, diminui a quantidade de vagas disponíveis
					adjList[(*it)->adjacent].edges--;
				}
			}
		}
		else{
			return pairs; // Não existe mais empregos disponíveis
		}
	}
	return pairs;
}

// Algoritmo de Ford-Fulkerson para encontrar o flow máximo de um grafo
// @return Retorna quantidade máxima de pares
int Graph::FordFulk(){
	do{
		for(int i = 0; i < (int) adjList.size(); i++){ // Marcar todos os vértices como não visitados
			adjList[i].visited = false;
		}
	} while(DFS(adjList.size() - 2)); // Enquanto achar caminho aumentante
	return maxFlow;
}

// Busca em profundidade
// @param vertex Vértice de início da busca
// @return Retorna True caso tenha encontrado caminho aumentante, False caso contrário
bool Graph::DFS(int vertex){
	if(vertex == (int)(adjList.size() - 1)){ // Se vertex é o Sink, caminho aumentante encontrado
		maxFlow++;
		return true;
	}
	adjList[vertex].visited = true; // Marcar vértice como visitado
	list<Edge*>::iterator it = adjList[vertex].adjacent.begin();
	for(; it != adjList[vertex].adjacent.end(); ++it){ // Itera nos vértices adjacentes ao vertex
		if((*it)->flow > 0 && !adjList[(*it)->adjacent].visited){ // Se tem flow sobrando em (vertex, adj) e adj ainda não foi visitado
			if(DFS((*it)->adjacent)){ // Se encontrar caminho aumentante a partir do vizinho
				// Muda o flow das arestas de ida e de retorno
				(*it)->flow = 0;
				(*it)->returnEdge->flow = 1;
				return true; // Caminho aumentante encontrado
			}
		}
	}
	return false; // Não encontrou caminho aumentante
}