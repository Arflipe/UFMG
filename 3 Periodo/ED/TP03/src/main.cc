#include "AVLDict.h"
#include <fstream>

int main(){
	ifstream input;
	input.open("input.txt");
	string line;
	AVLDict* d = new AVLDict();
	while(getline(input, line)){
		line.pop_back();
		char type;
		string word;
		string meaning;
		type = line[0];
		int start = line.find("[");
		start++;
		int end = line.find("]");
		word = line.substr(start, end - start);
		start = end + 2;
		Entry* e = new Entry(word, type);
		if(start < ((int) line.length() - 1)){
			meaning = line.substr(start);
			e->includeMeaning(meaning);
		}
		e->printEntry();
		d->insert(e);
	}
}