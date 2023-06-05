#ifndef EDGE_HPP
#define EDGE_HPP

#include <list>

using namespace std;

class Edge{
	private:
	int adjacent;
	int flow;
	Edge* returnEdge;

	public:
	Edge(int adjacent, int flow);

	friend class Vertex;
	friend class Graph;
};

#endif