#include <iostream>

int main(){
	int size;
	std::cin >> size;
	int* vector0 = new int[size];
	int* vector1;
	for(int i = 0; i < size; i++){
		std::cin >> vector0[i];
	}
	int vectorToCreate = 1;
	while(size > 1){
		if(vectorToCreate){
			vector1 = new int[size - 1];
			for(int i = 0; i < (size - 1); i++){
				if(!(vector0[i] + vector0[i + 1])){
					vector1[i] = -1;
				}
				else{
					vector1[i] = 1;
				}
			}
			delete vector0;
			vectorToCreate = 0;
		}
		else{
			vector0 = new int[size - 1];
			for(int i = 0; i < (size - 1); i++){
				if(vector1[i] + vector1[i + 1] == 0){
					vector0[i] = -1;
				}
				else{
					vector0[i] = 1;
				}
			}
			delete vector1;
			vectorToCreate = 1;
		}
		size--;
	}
	int resultado;
	if(vectorToCreate){
		resultado = vector0[0];
		delete vector0;
	}
	else{
		resultado = vector1[0];
		delete vector1;
	}
	if(resultado == 1){
		std::cout << "preta" << std::endl;
	}
	else{
		std::cout << "branca" << std::endl;
	}
}