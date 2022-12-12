#include "HashDict.h"

#include <cmath>

HashDict::HashDict(){
	table = new HashList[M];
}

void HashDict::insert(string word, string newMeaning, char type){
	int tableNum = hash(word);
	if(!table[tableNum].searchEntry(word, newMeaning, type)){
		Entry* newEntry = new Entry(word, type);
		if(!newMeaning.empty()){
			newEntry->includeMeaning(newMeaning);
		}
		table[tableNum].insertEntry(newEntry);
	}
}

int HashDict::remove(){
	int maxCollisions = 0;
	for(int i = 0; i <= M; i++){
		maxCollisions = max(maxCollisions, table[i].getSize());
		table[i].removeEntries();
	}
	return maxCollisions;
}

void HashDict::print(){
	for(int i = 0; i <= M; i++){
		table[i].printEntries();
	}
}

int HashDict::hash(string word){
	int hash = 0;
	for(int i = 0; i < min((int) word.length(), 3); i++){
		int letterPos = word[i];
		if(letterPos >= 97){
			letterPos -= 97;
		}
		else{
			letterPos -= 65;
		}
		hash += pow(26, (2 - i)) * letterPos;
	}
	return hash;
}