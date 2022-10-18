#include "Message.h"

Message::Message(int priority, string content){
	this->priority = priority;
	this->content = content;
	this->nextMessage = nullptr;
}

int Message::getPriority(){
	return priority;
}

string Message::getContent(){
	return content;
}

Message* Message::getNextMessage(){
	return nextMessage;
}

void Message::setNextMessage(Message* next){
	this->nextMessage = next;
}
