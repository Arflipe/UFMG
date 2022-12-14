#include "HashNode.h"

HashNode::HashNode(Entry* entry){
	this->entry = entry;
	nextNode = nullptr;
}

HashNode::~HashNode(){
	delete entry;
}