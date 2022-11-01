#include <stdio.h>
#include <string.h>

typedef struct PhoneNumber{
	char num[200];
} PhoneNumber;

void trade(PhoneNumber *vector, int bigger, int smaller){
	PhoneNumber aux;
	aux = vector[bigger];
	vector[bigger] = vector[smaller];
	vector[smaller] = aux;
}

void bubble(PhoneNumber *vector, int amountOfNum){
	int i, j;
	for(i = 0; i < (amountOfNum - 1); i++){
		for(j = 1; j < (amountOfNum - i); j++){
			if(strcmp(vector[j].num, vector[j - 1].num) < 0){
				trade(vector, (j - 1), j);
			}
		}
	}
}

int main(){
	int amountOfNum;
	while(scanf("%d%*c", &amountOfNum) != EOF){
		PhoneNumber vector[amountOfNum];
		for(int i = 0; i < amountOfNum; i++){
			scanf("%[^\n]%*c", &vector[i].num);
		}
		bubble(vector, amountOfNum);
		int vectorSize = strlen(vector[0].num);
		int counter = 0;
		for(int i = 0; i < (amountOfNum - 1); i++){
			for(int j = 0; j < vectorSize; j++){
				if(vector[i].num[j] == vector[i + 1].num[j]){
					counter++;
				}
				else{
					break;
				}
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}