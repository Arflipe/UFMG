#include "MeaningList.h"

MeaningList::MeaningList(){
	numMeanings = 0;
	firstMeaning = nullptr;
	lastMeaning = nullptr;
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
		cout << i << ". " << current->value << endl;
		current = current->nextMeaning;
	}
}