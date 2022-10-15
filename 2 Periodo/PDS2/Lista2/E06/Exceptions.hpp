#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

using namespace std;

class InvalidSizeException{
	public:
	string name = "InvalidSizeException";
};

class QueueFullException{
	public:
	string name = "QueueFullException";
};

class QueueEmptyException{
	public:
	string name = "QueueEmptyException";
};

class ItemNotFoundException{
	public:
	string name = "ItemNotFoundException";
};

#endif