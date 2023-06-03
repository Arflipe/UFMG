#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "vertex.hpp"

using namespace std;

class Graph{
	private:
	list<pair<list<pair<int,int>>::iterator, int>> bfsArr;
	int jobPos;
	int maxFlow;
	vector<Vertex> adjList;

	public:
    Graph(int numVertices, int jobPos);
	void addAdj(int vertex, int adjVertex);
	int greedy();
	int exact();
	int FordFulk();
	bool DFS(int vertex);
	void changeFlow(int vertex, int adjacent, int flow);
};

#endif // GRAPH_HPP