#include <iostream>
#include "distribution.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	int testCases;
	int numAlloyTypes;
	int request;
	cin >> testCases;
	for(int i = 0; i < testCases; i++){
		DistributionCenter* dc = new DistributionCenter();
		cin >> numAlloyTypes >> request;
		dc->addType(1); // Sempre possui de tamanho 1
		for(int j = 0; j < numAlloyTypes; j++){
			int alloyLength;
			cin >> alloyLength;
			if(alloyLength != 1){ // Tamanho 1 já foi adicionado
				dc->addType(alloyLength);
			}
		}
		cout << dc->distribute(request) << endl;
		delete dc;
	}
    return 0;
}
