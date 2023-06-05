#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "vertex.hpp"

class Graph{
	private:
	int jobPos;
	int maxFlow;
	vector<Vertex> adjList;

	public:
    Graph(int numVertices, int jobPos);
	void addAdj(int vertex, int adjVertex);
	int greedy();
	int FordFulk();
	bool DFS(int vertex);
};

#endif // GRAPH_HPP