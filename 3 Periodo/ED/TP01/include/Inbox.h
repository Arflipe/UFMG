#ifndef INBOX_H
#define INBOX_H

// #include "LinkedList.h"
#include "Message.h"

class Inbox /* : public LinkedList */{
	private:
	Message* firstMessage;
	Message* lastMessage;
	int size;


	public:
	Inbox();
	~Inbox();
	void addMessage(Message* newMessage);
	string readFirstMail();
	int getSize();
};

#endif