#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack{
	private:
	Node* top;
	int size;

	public:
	Stack();
	bool isEmpty();
	void push(Node newNode);
	void pop(Node* top);
};

#endif