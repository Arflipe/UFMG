#ifndef HASHDICT_H
#define HASHDICT_H

#include "HashList.h"

class HashDict{
	private:
	static const int M = 457001;
	HashList* table;

	public:
	HashDict();
	void insert(string word, string newMeaning, char type);
	int remove();
	void print();
	int hash(string word);
};

#endif