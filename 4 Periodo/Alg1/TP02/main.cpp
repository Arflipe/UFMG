#include <iostream>
#include <map>
#include <unordered_map>
#include "graph.hpp"
using namespace std;

#define INF 0x3f3f3f3f

int main(int argc, char const *argv[]) {
	int numPeople;
	int numJobs;
	int numQualifications;
	string person;
	string job;

	cin >> numPeople >> numJobs >> numQualifications;

	int numVertices = numPeople + numJobs;

	Graph* g1 = new Graph(numVertices + 2, numPeople); // Criando o grafo
	unordered_map<string, int> m; // Traduzir strings para inteiros

	// Montando o grafo
	numPeople = 0;
	for(int i = 0; i < numQualifications; i++){
		int p;
		int j;
		cin >> person >> job;
		if(!m.count(person)){
			p = numPeople;
			m[person] = p;
			numPeople++;
		}
		if(!m.count(job)){
			j = numVertices - numJobs;
			m[job] = j;
			numJobs--;
		}
		g1->addAdj(m[person], m[job]);
	}

	int guloso = g1->greedy();
	int exato = g1->FordFulk();

	cout  << "Guloso: " << guloso << endl;
	cout << "Exato: " << exato << endl;

	delete g1;
    return 0;
}
