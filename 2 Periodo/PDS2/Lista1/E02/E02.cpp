#include <iostream>
#include <string>

using namespace std;

int main()
{
	string palavra;
	string hashtag = "Hashtags:";
	string arroba = "Arrobas:";
	int hashtagc = 0;
	int arrobac = 0;
	while(cin >> palavra){
		switch (palavra[0]){
		case '#':
			hashtag += " " + palavra;
			hashtagc++;
			break;
		
		case '@':
			arroba += " " + palavra;
			arrobac++;
			break;
		
		default:
			break;
		}
	}
	if(hashtagc == 0){
		cout << "O tweet não possui hashtags." << endl;
	}
	else{
		cout << hashtag << endl;
	}
	if(arrobac == 0){
		cout << "O tweet não possui arrobas." << endl;
	}
	else if(arrobac > 3){
		cout << "Tweet inválido." << endl;
	}
	else{
		cout << arroba << endl;
	}
}