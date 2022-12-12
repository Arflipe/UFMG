#include "AVLNode.h"

AVLNode::AVLNode(Entry* newEntry){
	this->entry = newEntry;
	this->height = 1;
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}