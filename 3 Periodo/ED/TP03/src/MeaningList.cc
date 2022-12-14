#include "MeaningList.h"

MeaningList::MeaningList(){
	numMeanings = 0;
	firstMeaning = nullptr;
	lastMeaning = nullptr;
}

MeaningList::~MeaningList(){
	if(firstMeaning != nullptr){
		Meaning* aux = firstMeaning->nextMeaning;
		while(aux != nullptr){
			firstMeaning->nextMeaning = aux->nextMeaning;
			delete aux;
			aux = firstMeaning->nextMeaning;
		}
		delete firstMeaning;
	}
}

bool MeaningList::isEmpty(){
	return !numMeanings;
}

void MeaningList::addMeaning(string value){
	Meaning* aux = new Meaning(value);
	if(isEmpty()){
		firstMeaning = aux;
		lastMeaning = aux;
	}
	else{
		lastMeaning->nextMeaning = aux;
		lastMeaning = lastMeaning->nextMeaning;
	}
	numMeanings++;
}

void MeaningList::printMeanings(){
	Meaning* current = firstMeaning;
	for(int i = 1; i <= numMeanings; i++){
		outputFile << i << ". " << current->value << endl;
		current = current->nextMeaning;
	}
}