#include "Node.h"

Node::Node(){
	this->nextNode = nullptr;
}

void Node::setLeft(int left){
	this->left = left;
}

void Node::setRight(int right){
	this->right = right;
}

int Node::getLeft(){
	return this->left;
}

int Node::getRight(){
	return this->right;
}