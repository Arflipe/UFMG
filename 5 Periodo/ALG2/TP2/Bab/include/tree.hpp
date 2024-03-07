#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <vector>

class Tree {
	private:
	Node* root;

	public:
	Tree(int root);
	Node* FindNode(Node* current, int city);
	void AddChild(int parent, int child);
	vector<int> PreOrder();
	vector<int> OddDegreeNodes();
};


#endif