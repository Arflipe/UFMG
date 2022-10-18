#include "Server.h"

Server::Server(){}

void Server::manage(ifstream& input){
	int ID;
	while(!input.eof()){
		string command;
		input >> command;
		input >> ID;
		erroAssert((ID >= 0) && (ID <= 1000000), "ID inválido");
		if(command == "CADASTRA"){
			addUser(ID);
		}
		else if(command == "REMOVE"){
			removeUser(ID);
		}
		else if(command == "ENTREGA"){
			sendMailTo(input, ID);
		}
		else if(command == "CONSULTA"){
			readMailFrom(ID);
		}
	}
}

void Server::addUser(int ID){
	if(list.userExists(ID)){
		cout << "ERRO: CONTA " << ID << " JA EXISTENTE" << endl;
	}
	else{
		User* newUser = new User(ID);
		list.addUser(newUser);
		cout << "OK: CONTA " << ID << " CADASTRADA" << endl;
	}
}

void Server::removeUser(int ID){
	if(list.userExists(ID)){
		list.removeUser(ID);
		cout << "OK: CONTA " << ID << " REMOVIDA" << endl;
	}
	else{
		cout << "ERRO: CONTA " << ID << " NAO EXISTE" << endl;

	}
}

void Server::sendMailTo(ifstream& input, int ID){
	int priority;
	input >> priority;
	erroAssert((priority >= 0) && (priority <= 9), "Prioridade inválida");
	string content, aux;
	input >> content;
	input >> aux;
	while(aux != "FIM"){
		content += " ";
		content += aux;
		input >> aux;
	}
	if(list.userExists(ID)){
		Message* newMessage = new Message(priority, content);
		list.getUser(ID)->receiveMessage(newMessage);
		cout << "OK: MENSAGEM PARA " << ID << " ENTREGUE" << endl;
	}
	else{
		cout << "ERRO: CONTA " << ID << " NAO EXISTE" << endl;
	}
}

void Server::readMailFrom(int ID){
	if(list.userExists(ID)){
		if(list.getUser(ID)->inboxIsEmpty()){
			cout << "CONSULTA " << ID << ": CAIXA DE ENTRADA VAZIA" << endl;
		}
		else{
			cout << "CONSULTA " << ID << ": " << list.getUser(ID)->readMail() << " " << endl;
		}
	}
	else{
		cout << "ERRO: CONTA " << ID << " NAO EXISTE" << endl;
	}
}