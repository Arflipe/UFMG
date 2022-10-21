#include "Inbox.h"

Inbox::Inbox(){
	this->firstMessage = nullptr;
	this->lastMessage = nullptr;
	this->size = 0;
}

Inbox::~Inbox(){
	if(size){
		Message* aux1 = firstMessage;
		Message* aux2 = aux1->getNextMessage();
		while(aux1 != lastMessage && aux2 != lastMessage){
			delete aux1;
			aux1 = aux2;
			aux2 = aux1->getNextMessage();
		}
		delete aux1;
		delete aux2;
	}
}

int Inbox::getSize(){
	return size;
}

void Inbox::addMessage(Message* newMessage){
	if(size){
		if(firstMessage->getPriority() >= newMessage->getPriority()){
			Message* aux = firstMessage;
			bool notAdded = true;
			while(notAdded){
				if(aux == lastMessage){
					lastMessage->setNextMessage(newMessage);
					lastMessage = newMessage;
					size++;
					notAdded = false;
				}
				else if(!(aux->getNextMessage()->getPriority() >= newMessage->getPriority())){
					newMessage->setNextMessage(aux->getNextMessage());
					aux->setNextMessage(newMessage);
					size++;
					notAdded = false;
				}
				else{
					aux = aux->getNextMessage();
				}
			}
		}
		else{
			newMessage->setNextMessage(firstMessage);
			firstMessage = newMessage;
			size++;
		}
	}
	else{
		firstMessage = newMessage;
		lastMessage = newMessage;
		size++;
	}
}

string Inbox::readFirstMail(){
	Message* aux = firstMessage;
	if(firstMessage == lastMessage){
		lastMessage = nullptr;
	}
	firstMessage = aux->getNextMessage();
	string content = aux->getContent();
	delete aux;
	size--;
	return content;
}
