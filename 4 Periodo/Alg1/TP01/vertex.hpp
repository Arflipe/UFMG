#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <list>

using namespace std;

class Vertex{
	private:
	bool visited;
	list<pair<int,int>> adjacent;

	public:
	Vertex();
	void addNewAdjacent(int distanceTo, int vertexNum);

	friend class Graph;
};

#endif