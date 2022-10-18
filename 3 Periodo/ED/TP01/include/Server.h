#ifndef SERVER_H
#define SERVER_H

#include "UserList.h"
#include "msgassert.h"
#include <fstream>
#include <iostream>

class Server{
	private:
	UserList list;

	public:
	Server();
	void manage(ifstream& input);
	void addUser(int ID);
	void removeUser(int ID);
	void sendMailTo(ifstream& input, int ID);
	void readMailFrom(int ID);
};

#endif