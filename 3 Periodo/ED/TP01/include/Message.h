#ifndef MESSAGE_H
#define MESSAGE_H

#include "string"
#include "memlog.h"


using namespace std;

class Message{
	private:
	int priority;
	string content;
	Message* nextMessage;

	public:
	Message(int priority, string content);
	int getPriority();
	string getContent();
	void setNextMessage(Message* next);
	Message* getNextMessage();
};

#endif