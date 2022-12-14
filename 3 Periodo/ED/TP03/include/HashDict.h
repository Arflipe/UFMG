#ifndef HASHDICT_H
#define HASHDICT_H

#include "HashList.h"
#include <cmath>

static const int numLetters = 3; // Se igual a 1, hash terá 26^1 tabelas, de A a Z, se igual a 2, hash terá 26^2 tabelas, de AA a ZZ.

class HashDict{
	private:
	int M = (pow(26, numLetters) + 26);
	HashList* table;

	public:
	HashDict();
	~HashDict();
	void insert(string word, string newMeaning, char type);
	void remove();
	void print();
	int hash(string word);
};

#endif