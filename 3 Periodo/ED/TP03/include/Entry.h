#ifndef ENTRY_H
#define ENTRY_H

#include "MeaningList.h"

class Entry{
	private:
	string word;
	char type;
	MeaningList* meanings;

	public:
	Entry(string word, char type);
	~Entry();
	void includeMeaning(string value);
	void printEntry();
	bool hasMeanings();
	string getWord();
	char getType();
};

#endif