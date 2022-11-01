#include <iostream>
#include <string>

using namespace std;

void Particao(int Esq, int Dir, int *i, int *j, string *A){
	string x, w;
	*i = Esq; *j = Dir;
	x = A[(*i + *j)/2]; 
	do{
		while (x > A[*i]) (*i)++;
		while (x < A[*j]) (*j)--;
	if (*i <= *j){
		w = A[*i]; A[*i] = A[*j]; A[*j] = w;
		(*i)++; (*j)--;
	}
	} while (*i <= *j);
}

void Ordena(int Esq, int Dir, string *A){
	int i, j;
	Particao(Esq, Dir, &i, &j, A);
	if (Esq < j) Ordena(Esq, j, A);
	if (i < Dir) Ordena(i, Dir, A);
}

void QuickSort(string *A, int n){
	Ordena(0, n-1, A);
}

int main(){
	string name;
	string friends[50];
	int friendsSize = 0;
	string notFriends[50];
	int notFriendsSize = 0;
	string isFriend;
	string amigoHabay;
	cin >> name;
	while(name != "FIM"){
		cin >> isFriend;
		bool added = false;
		for(int i = 0; i < friendsSize; i++){
			if(name == friends[i]){
				added = true;
			}
		}
		for(int i = 0; i < notFriendsSize; i++){
			if(name == notFriends[i]){
				added = true;
			}
		}
		if(added){}
		else if(isFriend == "YES"){
			if(!friendsSize){
				amigoHabay = name;
			}
			else if (amigoHabay.length() < name.length()){
				amigoHabay = name;
			}
			friends[friendsSize] = name;
			friendsSize++;
		}
		else if(isFriend == "NO"){
			notFriends[notFriendsSize] = name;
			notFriendsSize++;
		}
		cin >> name;
	}
	QuickSort(friends, friendsSize);
	QuickSort(notFriends, notFriendsSize);
	for(int i = 0; i < friendsSize; i++){
		std::cout << friends[i] << endl;
	}
	for(int i = 0; i < notFriendsSize; i++){
		std::cout << notFriends[i] << endl;
	}
	cout << endl << "Amigo do Habay:" << endl << amigoHabay << endl;
	return 0;
}