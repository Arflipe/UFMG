#include "pessoa.hpp"

void Pessoa::print(ostream& out){
	out << "(nome = " << nome << ", idade = " << idade << ", CPF = " << cpf << ")";
}

void Pessoa::GetCampos(vector<string>& out){
	out.push_back("nome");
	out.push_back("idade");
	out.push_back("cpf");
}

void Pessoa::setAtributo(string key, string valor){
	if(key == "nome"){
		nome = valor;
	}
	else if(key == "idade"){
		idade = stoi(valor);
	}
	else if(key == "cpf"){
		cpf = stoul(valor);
	}
}

string Pessoa::GetAtributo(string key){
	if(key == "nome"){
		return nome;
	}
	else if(key == "idade"){
		return to_string(idade);
	}
	else if(key == "cpf"){
		return to_string(cpf);
	}
	else{
		return NULL;
	}
}

bool Pessoa::operator==(Pessoa& rhs){
	if(cpf == rhs.cpf){
		return true;
	}
	return false;
}