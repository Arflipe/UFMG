#include "UserList.h"

UserList::UserList(){
	this->firstUser = nullptr;
	this->lastUser = nullptr;
	this->size = 0;
}

UserList::~UserList(){
	if(size){
		User* aux1 = firstUser;
		User* aux2 = aux1->getNextUser();
		while(aux1 != lastUser && aux2 != lastUser){
			delete aux1;
			aux1 = aux2;
			aux2 = aux1->getNextUser();
		}
		delete aux1;
		delete aux2;
	}
}

void UserList::addUser(User* newUser){
	if(size){
		lastUser->setNextUser(newUser);
		lastUser = newUser;
		size++;
	}
	else{
		firstUser = newUser;
		lastUser = newUser;
		size++;
	}
}

void UserList::removeUser(int ID){
	User* aux;
	if(firstUser->getID() != ID){
		aux = firstUser;
		bool notRemoved = true;
		while(notRemoved){
			if(aux->getNextUser()->getID() != ID){
				aux = aux->getNextUser();
			}
			else{
				User* toRemove = aux->getNextUser();
				if(toRemove == lastUser){
					lastUser = aux;
					aux->setNextUser(nullptr);
				}
				else{
					aux->setNextUser(toRemove->getNextUser());
				}
				delete toRemove;
				size--;
				notRemoved = false;
			}
		}
	}
	else{
		if(firstUser == lastUser){
			lastUser = nullptr;
		}
		aux = firstUser->getNextUser();
		delete firstUser;
		size--;
		firstUser = aux;
	}
}

bool UserList::userExists(int ID){
	User* aux = firstUser;
	while(aux != nullptr){
		if(aux->getID() == ID){
			return true;
		}
		else{
			aux = aux->getNextUser();
		}
	}
	return false;
}

User* UserList::getUser(int ID){
	User* aux = firstUser;
	while(aux->getID() != ID){
		aux = aux->getNextUser();
	}
	return aux;
}

