#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <list>
#include "edge.hpp"

class Vertex{
	private:
	int edges;
	bool visited;
	list<Edge*> adjacent;

	public:
	Vertex();
	~Vertex();

	friend class Graph;
};

#endif