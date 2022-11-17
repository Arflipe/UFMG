#include <iostream>
#include <string>

using namespace std;


class Person{
	private:
	string name;
	int killCount;
	bool dead;

	public:
	Person(string name, int killCount, bool dead){
		this->name = name;
		this->killCount = killCount;
		this->dead = dead;
	}
	void incKC(){
		killCount++;
	}
	void died(){
		dead = true;
	}
	string getName(){
		return name;
	}
	int getKC(){
		return killCount;
	}
	bool isDead(){
		return dead;
	}
	bool isMurderer(){
		return killCount;
	}
};

class Node{
	private:
	Person* p;
	Node* left;
	Node* right;

	public:
	Node(){
		this->left = nullptr;
		this->right = nullptr;
	}
	friend class BSTree;
};

class BSTree{
	private:
	Node* node;
	void recursiveInsert(Node* &node, Person* p){
		if(node == nullptr){
			node = new Node();
			node->p = p;
		}
		else{
			if(node->p->getName() == p->getName()){
				if(p->getKC()){
					node->p->incKC();
				}
				else{
					node->p->died();
				}
			}
			else if(node->p->getName() < p->getName()){
				recursiveInsert(node->right, p);
			}
			else{
				recursiveInsert(node->left, p);
			}
		}
	};

	public:
	BSTree(){
		this->node = nullptr;
	};
	Node* getNode(){
		return node;
	};
	void insert(Person* p){
		recursiveInsert(node, p);
	};
	void print(Node* node){
		if(node != nullptr){
			print(node->left);
			if(!node->p->isDead() && node->p->isMurderer()){
				cout << node->p->getName() << " " << node->p->getKC() << "\n";
			}
			print(node->right);
		}
	};
};

int main(){
	string name;
	bool killed;
	BSTree* people = new BSTree();
	Person* p;
	Node* root = people->getNode();
	while(cin >> name){
		p = new Person(name, 1, false);
		people->insert(p);
		cin >> name;
		p = new Person(name, 0, true);
		people->insert(p);
	}
	cout << "HALL OF MURDERERS\n";
	people->print(people->getNode());
}