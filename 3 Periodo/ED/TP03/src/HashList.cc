#include "HashList.h"

HashList::HashList(){
	size = 0;
	firstNode = nullptr;
	lastNode = nullptr;
}

void HashList::insertEntry(Entry* newEntry){
	HashNode* aux = new HashNode(newEntry);
	if(!size){
		firstNode = aux;
		lastNode = aux;
	}
	else if(firstNode->entry->getWord() > newEntry->getWord()){
		aux->nextNode = firstNode;
		firstNode = aux;
	}
	else{
		recursiveInsert(firstNode, aux);
	}
	size++;
}

void HashList::recursiveInsert(HashNode* &node, HashNode* newNode){
	if(node->nextNode != nullptr){
		if(node->nextNode->entry->getWord() > newNode->entry->getWord()){
			newNode->nextNode = node->nextNode;
			node->nextNode = newNode;
		}
		else{
			recursiveInsert(node->nextNode, newNode);
		}
	}
	else{
		node->nextNode = newNode;
	}
}

bool HashList::searchEntry(string word, string newMeaning, char type){
	if(firstNode == nullptr){
		return false;
	}
	if(firstNode->entry->getWord() == word){
		if(firstNode->entry->getType() == type){
			if(!newMeaning.empty()){
				firstNode->entry->includeMeaning(newMeaning);
			}
			return true;
		}
		Entry* newEntry = new Entry(word, type);
		if(!newMeaning.empty()){
			newEntry->includeMeaning(newMeaning);
		}
		HashNode* newNode = new HashNode(newEntry);
		if(firstNode->entry->getType() > type){
			newNode->nextNode = firstNode;
			firstNode = newNode;
		}
		else{
			newNode->nextNode = firstNode->nextNode;
			firstNode->nextNode = newNode;
		}
		size++;
		return true;
	}
	if(firstNode->nextNode != nullptr){
		return recursiveSearch(firstNode, word, newMeaning, type);
	}
	return false;
}

bool HashList::recursiveSearch(HashNode* node, string word, string newMeaning, char type){
	if(node->nextNode->entry->getWord() == word){
		if(node->nextNode->entry->getType() == type){
			if(!newMeaning.empty()){
				node->nextNode->entry->includeMeaning(newMeaning);
			}
			return true;
		}
		Entry* newEntry = new Entry(word, type);
		if(!newMeaning.empty()){
			newEntry->includeMeaning(newMeaning);
		}
		HashNode* newNode = new HashNode(newEntry);
		if(node->nextNode->entry->getType() > type){
			newNode->nextNode = node->nextNode;
			node->nextNode = newNode;
		}
		else{
			newNode->nextNode = node->nextNode->nextNode;
			node->nextNode->nextNode = newNode;
		}
		size++;
		return true;
	}
	else if(node->nextNode->nextNode != nullptr){
		return recursiveSearch(node->nextNode, word, newMeaning, type);
	}
	return false;
}

void HashList::removeEntries(){
	if(firstNode == nullptr){
		return;
	}
	while(firstNode->entry->hasMeanings()){
		HashNode* aux = firstNode;
		firstNode = firstNode->nextNode;
		delete aux;
		if(firstNode == nullptr){
			return;
		}
	}
	recursiveRemove(firstNode);
}

void HashList::recursiveRemove(HashNode* &node){
	if(node == nullptr){
		return;
	}
	while(node->entry->hasMeanings()){
		HashNode* aux = node;
		node = node->nextNode;
		delete aux;
		if(node == nullptr){
			return;
		}
	}
	recursiveRemove(node->nextNode);
}

void HashList::printEntries(){
	HashNode* aux = firstNode;
	while(aux != nullptr){
		aux->entry->printEntry();
		aux = aux->nextNode;
	}
}

int HashList::getSize(){
	return size;
}