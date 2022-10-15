#ifndef PESSOA_H
#define PESSOA_H

#include "ireadable.hpp"

class Pessoa : public IReadable{
	private:
	string nome;
	int idade;
	unsigned long cpf;

	protected:
	virtual void print(ostream& out) override;

	public:
	virtual void GetCampos(vector<string>& out) override;
	virtual void setAtributo(string key, string valor) override;
	virtual string GetAtributo(string key) override;

	bool operator == (Pessoa& rhs);
};

#endif