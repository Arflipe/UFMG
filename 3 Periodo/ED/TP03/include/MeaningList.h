#ifndef MEANINGLIST_H
#define MEANINGLIST_H

#include "Meaning.h"
#include <iostream>
#include <fstream>

inline ifstream inputFile;
inline ofstream outputFile;

class MeaningList{
	private:
	int numMeanings;
	Meaning* firstMeaning;
	Meaning* lastMeaning;

	public:
	MeaningList();
	~MeaningList();
	bool isEmpty();
	void addMeaning(string value);
	void printMeanings();
};

#endif