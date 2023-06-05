#include "vertex.hpp"

Vertex::Vertex(){
	this->edges = 0;
	this->visited = false;
}

Vertex::~Vertex(){
	list<Edge*>::iterator it = adjacent.begin();
	for(; it != adjacent.end(); ++it){
		delete (*it);
	}
}