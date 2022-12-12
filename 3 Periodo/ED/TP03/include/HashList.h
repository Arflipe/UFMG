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
	void insertEntry(Entry* newEntry);
	void recursiveInsert(HashNode* &node, HashNode* newNode);
	bool searchEntry(string word, string newMeaning, char type);
	bool recursiveSearch(HashNode* node, string word, string newMeaning, char type);
	void removeEntries();
	void recursiveRemove(HashNode* &node);
	void printEntries();
	// bool notEmpty();
	int getSize();
};

#endif