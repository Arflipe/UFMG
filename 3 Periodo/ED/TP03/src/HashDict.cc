#include "HashDict.h"

HashDict::HashDict(){
	table = new HashList[M];
}

HashDict::~HashDict(){
	delete[] table;
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

void HashDict::remove(){
	for(int i = 0; i < M; i++){
		table[i].removeEntries();
	}
}

void HashDict::print(){
	for(int i = 0; i < M; i++){
		table[i].printEntries();
	}
}

int HashDict::hash(string word){
	int hash = 26;
	int firstLetter = word[0];
	if(firstLetter <= 90){
		hash = firstLetter - 65;
	}
	else{
		for(int i = 0; i < min((int) word.length(), numLetters); i++){
			int letterPos = word[i];
			if(letterPos >= 97){
				letterPos -= 97;
			}
			else{
				letterPos -= 65;
			}
			hash += pow(26, ((numLetters - 1) - i)) * letterPos;
		}
	}
	return hash;
}