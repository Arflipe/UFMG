#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"

class UserList{
	private:
	User* firstUser;
	User* lastUser;
	int size;

	public:
	UserList();
	~UserList();
	void addUser(User* user);
	void removeUser(int ID);
	bool userExists(int ID);
	User* getUser(int ID);

};

#endif