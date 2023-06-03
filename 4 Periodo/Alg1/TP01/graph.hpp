#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "vertex.hpp"
#include <iostream>
#include <vector>
#include <queue>

class Graph{
	private:
	vector<Vertex> adjList;
	int* distanceArr;
	priority_queue<pair<int,int>> pq;

	public:
    Graph(int numVertices);
	~Graph();
	void addAdj(int vertex, int distanceTo, int adjVertex);
	int findSmallestEvenRoute();
	void searchCombinations(int vertex, int initDistance);
	void updateDistances(int vertex, int initDistance);
};

#endif // GRAPH_HPP