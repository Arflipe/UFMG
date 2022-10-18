#ifndef INBOX_H
#define INBOX_H

// #include "LinkedList.h"
#include "Message.h"

class Inbox{
	private:
	Message* firstMessage;
	Message* lastMessage;
	int size;


	public:
	Inbox();
	~Inbox();
	int getSize();
	void addMessage(Message* newMessage);
	string readFirstMail();
};

#endif