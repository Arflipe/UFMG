#ifndef IREADABLE_H
#define IREADABLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IReadable{
	protected:
	virtual void print(ostream& out) = 0;

	public:
	virtual void GetCampos(vector<string>& out) = 0;
	virtual void setAtributo(string key, string valor) = 0;
	virtual string GetAtributo(string key) = 0;
	
	friend ostream& operator << (ostream& out, IReadable& readable);
};

#endif