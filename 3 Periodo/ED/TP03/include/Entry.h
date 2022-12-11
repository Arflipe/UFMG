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
	void includeMeaning(string value);
	void printEntry();
	bool hasNoMeanings();
};

#endif