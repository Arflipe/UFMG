#include "Stack.h"

Stack::Stack(){
	this->top = nullptr;
	this->size = 0;
}

bool Stack::isEmpty(){
	return (!size);
}

void Stack::push(Node newNode){
	if(isEmpty()){
		top = new Node();
		*top = newNode;
	}
	else{
		newNode.nextNode = top;
		top = new Node();
		*top = newNode;
	}
	size++;
}

void Stack::pop(Node* newNode){
	Node* aux = top;
	*newNode = *top;
	top = top->nextNode;
	delete aux;
	size--;
}