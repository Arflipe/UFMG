#include "Register.h"

Register::Register(){}

Register::Register(int key){
	this->key = key;
}

int Register::getKey(){
	return this->key;
}

void Register::setKey(int key){
	this->key = key;
}