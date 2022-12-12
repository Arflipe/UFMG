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
	if(!hasNoMeanings()){
		meanings->printMeanings();
	}
}

bool Entry::hasNoMeanings(){
	return meanings->isEmpty();
}

string Entry::getWord(){
	return word;
}

char Entry::getType(){
	return type;
}