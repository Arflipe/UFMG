#include "vertex.hpp"

Vertex::Vertex(){
	this->visited = false;
}


void Vertex::addNewAdjacent(int distanceTo, int vertexNum){
	adjacent.push_back(make_pair(distanceTo, vertexNum));
}