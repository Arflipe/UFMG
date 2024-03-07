#include "node.hpp"

Node::Node(int city) {
	this->city = city;
}

int Node::GetCity() {
	return this->city;
}

void Node::AddChild(int child) {
	Node newChild(child);
	this->children.push_back(newChild);
}