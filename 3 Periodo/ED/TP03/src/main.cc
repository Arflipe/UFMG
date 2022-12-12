#include "AVLDict.h"
#include <fstream>

int main(){
	ifstream input;
	input.open("input.txt");
	string line;
	AVLDict* d = new AVLDict();
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
		if(!d->searchEntry(word, meaning, type)){
			Entry* e = new Entry(word, type);
			if(!meaning.empty()){
				e->includeMeaning(meaning);
			}
			d->insert(e);
		}
	}
	d->print();
	d->remove();
	d->print();
}