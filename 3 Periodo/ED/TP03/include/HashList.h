#ifndef HASHLIST_H
#define HASHLIST_H

#include "HashNode.h"

class HashList{
	private:
	int size;
	HashNode* firstNode;
	HashNode* lastNode;

	public:
	HashList();
	~HashList();
	void insertEntry(Entry* newEntry);
	void recursiveInsert(HashNode* &node, HashNode* newNode);
	bool searchEntry(string word, string newMeaning, char type);
	bool recursiveSearch(HashNode* node, string word, string newMeaning, char type);
	void removeEntries();
	void recursiveRemove(HashNode* &node);
	void printEntries();
	int getSize();
};

#endif