#ifndef MEANING_H
#define MEANING_H

#include <string>

using namespace std;

class Meaning{
	private:
	string value;
	Meaning* nextMeaning;

	public:
	Meaning(string value);

	friend class MeaningList;
};

#endif