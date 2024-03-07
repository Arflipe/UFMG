#include <iostream>
#include <fstream>
#include <queue>

#include "graph.hpp"

using namespace std;

string RemoveSpaces(string str, bool skipToFirstSpace = false) {
	if(skipToFirstSpace) {
		int firstSpace = str.find(" ");
		str = str.substr(firstSpace + 1);
	}
	while(str[0] == ' ') {
		str = str.substr(1);
	}
	return str;
}

Graph* getData(string fileName){
	ifstream file;
	file.open(fileName);

	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		exit(1);
	}


	string line;
	// find substring s in line
	getline(file, line);
	while(line.find("DIMENSION") == string::npos) {
		getline(file, line);
	}
	line = line.substr(line.find(":") + 2);
	int numCities = stoi(line);

	Graph* g = new Graph(numCities);

	getline(file, line);

	while(line.find("1") == string::npos) {
		getline(file, line);
	}
	for(int i = 0; i < numCities; i++) {
		line = RemoveSpaces(line);
		int index = stoi(line.substr(0, line.find(" ")));

		line = RemoveSpaces(line, true);
		double x = stod(line.substr(0, line.find(" ")));

		line = RemoveSpaces(line, true);
		double y = stod(line);

		g->AddCity(index - 1, x, y);

		getline(file, line);
	}
	return g;
}

int main(int argc, char *argv[]) {
	Graph* g = getData(argv[1]);

	double solution = g->GetSolution();
	cout << solution << endl;
	return 0;
}
