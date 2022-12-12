#ifndef AVLNODE_H
#define AVLNODE_H

#include "Entry.h"

class AVLNode{
	private:
	int height;
	Entry* entry;
	AVLNode* parent;
	AVLNode* left;
	AVLNode* right;

	public:
	AVLNode(Entry* newEntry);

	friend class AVLDict;
};

#endif