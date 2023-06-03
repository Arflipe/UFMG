#include "vertex.hpp"

Vertex::Vertex(){
	this->edges = 0;
	this->visited = false;
}

void Vertex::addNewAdjacent(int vertexNum, int flow){
	adjacent.push_back(make_pair(vertexNum, flow));
	edges++;
}

void Vertex::changeFlow(int vertexNum, int adjNum, int flow){

}