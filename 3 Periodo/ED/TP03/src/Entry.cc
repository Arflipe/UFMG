#include "Entry.h"

Entry::Entry(string word, char type){
	this->word = word;
	this->type = type;
	meanings = new MeaningList();
}

void Entry::includeMeaning(string value){
	meanings->addMeaning(value);
}

void Entry::printEntry(){
	cout << word << " (" << type << ")" << endl;
	meanings->printMeanings();
}

bool Entry::hasNoMeanings(){
	return meanings->isEmpty();
}