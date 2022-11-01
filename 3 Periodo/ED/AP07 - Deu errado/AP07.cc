#include <iostream>
#include <string>

using namespace std;

void trade(char *vector[], int bigger, int smaller){
	string aux;
	char* aux;
	aux = vector[bigger];
	vector[bigger] = vector[smaller];
	vector[smaller] = aux;
}

void bubble(char *vector[], int numAmount){
	int i, j;
	for(i = 0; i < (numAmount - 1); i++){
		for(j = 1; j < (numAmount - i); j++){
			if(strcmp(vector[j], vector[j - 1]) < 0){
				trade(vector, (j - 1), j);
			}
		}
	}
}

int main(){
	int numAmount;
	while(cin >> numAmount){
		string* vector [numAmount];
		string aux;
		cin >> aux;
		int vectorSize = aux.size();
		for(int i = 0; i < numAmount; i++){
			string* aux2 = new string[vectorSize + 1];
			for(int j = 0; j < vectorSize; j++){
				aux2[j] = aux[j];
			}
			vector[i] = aux2;
			if(i != (numAmount - 1)){
				cin >> aux;
			}
		}
		bubble(vector, numAmount);
		for(int i = 0; i < numAmount; i++){
			cout << vector[i] << endl;
		}
		int counter = 0;
		for(int i = 0; i < (numAmount - 1); i++){
			bool equal = true;
			for(int j = 0; j < vectorSize; j++){
				if(vector[i][j] == vector[i + 1][j] && equal){
					counter++;
				}
				else{
					equal = false;
				}
			}
		}
		cout << counter << endl;
		for(int i = 0; i < numAmount; i++){
			delete[] vector[i];
		}
		cout << "vector: " << sizeof(vector) << endl;
	}
	return 0;
}