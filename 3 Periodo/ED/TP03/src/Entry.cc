#include "Entry.h"

Entry::Entry(string word, char type){
	this->word = word;
	this->type = type;
	meanings = new MeaningList();
}

Entry::~Entry(){
	delete meanings;
}

void Entry::includeMeaning(string value){
	meanings->addMeaning(value);
}

void Entry::printEntry(){
	outputFile << word << " (" << type << ")" << endl;
	if(hasMeanings()){
		meanings->printMeanings();
	}
}

bool Entry::hasMeanings(){
	return !meanings->isEmpty();
}

string Entry::getWord(){
	return word;
}

char Entry::getType(){
	return type;
}