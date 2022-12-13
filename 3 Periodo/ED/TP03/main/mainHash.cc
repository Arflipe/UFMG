#include "HashDict.h"
#include <fstream>

int main(){
	ifstream input;
	input.open("input.txt");
	string line;
	HashDict* d = new HashDict();
	while(getline(input, line)){
		if(line.back() == '\r'){
			line.pop_back();
		}
		char type;
		string word;
		string meaning;
		type = line[0];
		int start = line.find("[");
		start++;
		int end = line.find("]");
		word = line.substr(start, end - start);
		start = end + 2;
		if(start < ((int) line.length())){
			meaning = line.substr(start);
		}
		d->insert(word, meaning, type);
	}
	d->print();
	int maxCollisions = d->remove();
	// cout << maxCollisions << endl;
	d->print();
}