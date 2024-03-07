#ifndef NODE_HPP
#define NODE_HPP

#include <list>

using namespace std;

class Node {
	friend class Tree;

	private:
	int city;
	list<Node> children;
	
	public:
	Node(int city);
	int GetCity();
	void AddChild(int child);
};

#endif