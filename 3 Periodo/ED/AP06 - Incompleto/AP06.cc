#include <iostream>

using namespace std;

class Node{
	private:
	char letter;
	Node* left;
	Node* right;

	public:
	Node(char letter){
		this->letter = letter;
		this->left = nullptr;
		this->right = nullptr;
	};

	friend class Tree;
};

class Tree{
	private:
	Node* root;

	public:
	Tree(){
		root = nullptr;
	};
	~Tree(){
	};
	void insert(char preOrder[26], char inOrder[26]){
		char* left;
		char* right;
		int preSize = getSize(preOrder);
		int inSize = getSize(inOrder);
		char root = preOrder[0];
		for(int i = 0; i < inSize; i++){
			if(root == inOrder[i]){
				// left = getSubLeft(preOrder, i);
			}
		}

	};

	private:
	int getSize(char* string){
		int size;
		for(int i = 0; i < 26; i++){
			if(string[i] == '\0'){
				size = i;
				break;
			}
		}
		return size;
	}

	// char* getSubLeft(char* string, int subSize){
	// 	return a;
	// }

};

int getSize(char* string){
		int size;
		for(int i = 0; i < 26; i++){
			if(string[i] == '\0'){
				size = i;
				break;
			}
		}
		return size;
	}

int main(){
	char* preOrder;
	char inOrder[26];
	cin >> preOrder;
	// cin >> inOrder;
	cout << getSize(preOrder) << endl;
	cout << "foi";
	// char lastAdded = preOrder[0];
	// int rootPos;
	// for(int i = 0; i < 26; i++){
	// 	if(root == inOrder[i]){
	// 		rootPos = i;
	// 	}
	// }

	// for(int i = 1; i <= rootPos; i++){
	// 	for(int j = 0; j < rootPos; j++){
	// 		if(preOrder[i] = lastAdded)
	// 	}
	// }
}