#include "Register.h"

Register::Register(){}

int Register::getKey(){
	return this->key;
}

void Register::setKey(int key){
	this->key = key;
}