#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <list>

using namespace std;

class Vertex{
	private:
	int edges;
	bool visited;
	list<pair<int, int>> adjacent;

	public:
	Vertex();
	void addNewAdjacent(int vertexNum, int flow);
	void changeFlow(int vertexNum, int adjNum, int flow);

	friend class Graph;
};

#endif