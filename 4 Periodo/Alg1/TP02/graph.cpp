#include "graph.hpp"

Graph::Graph(int numVertices, int jobPos){
	this->jobPos = jobPos;
	this->maxFlow = 0;
	for(int i = 0; i < numVertices; i++){
		Vertex v;
		adjList.push_back(v);
	}
	int i = 0;
	for(; i < jobPos; i++){
		addAdj(numVertices - 2, i);
	}
	for(; i < numVertices - 2; i++){
		addAdj(i, numVertices - 1);
	}
}

void Graph::addAdj(int vertex, int adjVertex){
	adjList[vertex].addNewAdjacent(adjVertex, 1);
	adjList[adjVertex].addNewAdjacent(vertex, 0);
}

int Graph::greedy(){
	for(int i = 0; i < (int) (adjList.size() - 2); i++){
		adjList[i].visited = false;
	}
	adjList[adjList.size() - 2].visited = true;
	adjList[adjList.size() - 1].visited = true;
	int pairs = 0;
	for(int i = 0; i < jobPos; i++){
		int leastNC = -1;
		int j = 0;
		for(; j < jobPos; j++){
			if(!adjList[j].visited && adjList[j].edges > 1){
				leastNC = j;
				break;
			}
		}
		for(; j < jobPos; j++){
			if(!adjList[j].visited && adjList[j].edges < adjList[leastNC].edges && adjList[j].edges > 1){
				leastNC = j;
			}
		}
		if(leastNC != -1){
			list<pair<int,int>>::iterator it = adjList[leastNC].adjacent.begin();
			it++;
			int leastNCJ = -1;
			for(; it != adjList[leastNC].adjacent.end(); ++it){
				if(!adjList[(*it).first].visited){
					leastNCJ = (*it).first;
					break;
				}
			}
			for(; it != adjList[leastNC].adjacent.end(); ++it){
				if(!adjList[(*it).first].visited && adjList[(*it).first].edges < adjList[leastNCJ].edges){
					leastNCJ = (*it).first;
				}
			}
			if(leastNCJ != -1){
				adjList[leastNC].visited = true;
				adjList[leastNCJ].visited = true;
				pairs++;
				it = adjList[leastNCJ].adjacent.begin();
				it++;
				for(; it != adjList[leastNCJ].adjacent.end(); ++it){
					adjList[(*it).first].edges--;
				}
			}
		}
		else{
			return pairs;
		}
	}
	return pairs;
}

int Graph::FordFulk(){
	do{
		for(int i = 0; i < (int) adjList.size(); i++){
			adjList[i].visited = false;
		}
	} while(DFS(adjList.size() - 2));
	return maxFlow;
}

bool Graph::DFS(int vertex){
	if(adjList[vertex].visited){
		return false;
	}
	adjList[vertex].visited = true;
	list<pair<int,int>>::iterator it = adjList[vertex].adjacent.begin();
	for(; it != adjList[vertex].adjacent.end(); ++it){
		if((*it).second == 1){
			if((*it).first == (int)(adjList.size() - 1)){
				(*it).second = 0;
				maxFlow++;
				return true;
			}
			if(DFS((*it).first)){
				(*it).second = 0;
				if(vertex != (int)(adjList.size() - 2)){
					changeFlow(vertex, (*it).first, -1);
				}
				return true;
			}
		}
	}
	it = adjList[vertex].adjacent.begin();
	for(; it != adjList[vertex].adjacent.end(); ++it){
		if((*it).second == -1){
			if(DFS((*it).first)){
				(*it).second = 0;
				changeFlow(vertex, (*it).first, 1);
				return true;
			}
		}
	}
	return false;
}

void Graph::changeFlow(int vertex, int adjacent, int flow){
	list<pair<int,int>>::iterator it = adjList[adjacent].adjacent.begin();
	for(; it != adjList[adjacent].adjacent.end(); ++it){
		if((*it).first == vertex){
			(*it).second = flow;
		}
	}
}