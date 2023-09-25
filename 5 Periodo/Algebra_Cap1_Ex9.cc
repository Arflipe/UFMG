#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}

int main(){
	int a, b;
	int testNum = 10;
	int pairNum;
	int pairsOne;
	cin >> pairNum;
	// for each test case, generate random a and b, and calculate if gcd(a, b) == 1
	for(int i = 0; i < testNum; i++){
		pairsOne = 0;
		for(int j = 0; j < pairNum; j++){
			a = rand() % 1000000 + 1;
			b = rand() % 1000000 + 1;
			if(gcd(a, b) == 1){
				pairsOne++;
			}
		}
		float coprimality = (float)pairsOne / (float)pairNum;
		cout << "Test " << i + 1 << ": " << coprimality << endl;
	}
	return 0;
}