#ifndef MEANINGLIST_H
#define MEANINGLIST_H

#include "Meaning.h"
#include <iostream>

class MeaningList{
	private:
	int numMeanings;
	Meaning* firstMeaning;
	Meaning* lastMeaning;

	public:
	MeaningList();
	bool isEmpty();
	void addMeaning(string value);
	void printMeanings();
};

#endif