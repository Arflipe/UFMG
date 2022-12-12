#ifndef HASHNODE_H
#define HASHNODE_H

#include "Entry.h"

class HashNode{
	private:
	Entry* entry;
	HashNode* nextNode;

	public:
	HashNode(Entry* entry);

	friend class HashList;
};

#endif