#ifndef USER_H
#define USER_H

#include "Inbox.h"

class User{
	private:
	int ID;
	Inbox* uInbox;
	User* nextUser;

	public:
	User(int ID);
	~User();
	int getID();
	void setNextUser(User* next);
	User* getNextUser();
	void receiveMessage(Message* message);
	bool inboxIsEmpty();
	string readMail();
};

#endif