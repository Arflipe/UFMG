#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
	int numVertices, numLinks;
	cin >> numVertices >> numLinks;
	Graph* g = new Graph(numVertices);
	int vertex, distance, adjacent;
	for(int i = 0; i < numLinks; i++){
		cin >> vertex >> adjacent >> distance;
		distance *= -1; // Priority_queue é um heap de máximo
		if(distance % 2 == 0){ // Não adicionar arestas com distâcias ímpares
			g->addAdj(vertex, distance, adjacent);
			g->addAdj(adjacent, distance, vertex);
		}
	}
	cout << g->findSmallestEvenRoute() << endl;
	delete g;
    return 0;
}