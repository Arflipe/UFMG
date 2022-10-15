#include "User.h"

User::User(int ID){
	this->ID = ID;
	this->nextUser = nullptr;
	this->uInbox = new Inbox();
}

User::~User(){
	delete uInbox;
}

int User::getID(){
	return ID;
}

void User::setNextUser(User* next){
	this->nextUser = next;
}

User* User::getNextUser(){
	return nextUser;
}

void User::receiveMessage(Message* message){
	uInbox->addMessage(message);
}

bool User::inboxIsEmpty(){
	return !(uInbox->getSize());
}

string User::readMail(){
	return uInbox->readFirstMail();
}