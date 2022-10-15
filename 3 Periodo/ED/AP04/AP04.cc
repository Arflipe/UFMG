#include <iostream>

using namespace std;

class Node{
	private:
	int initialPosition;
	Node* previousNode;
	Node* nextNode;

	public:
	Node(int initialPosition){
		previousNode = nullptr;
		nextNode = nullptr;
		this->initialPosition = initialPosition;
	}
	void setNextNode(Node* nextNode){
		this->nextNode = nextNode;
	}
	void setPreviousNode(Node* previousNode){
		this->previousNode = previousNode;
	}
	Node* getNextNode(){
		return nextNode;
	}
	Node* getPreviousNode(){
		return previousNode;
	}
	int getInitialPosition(){
		return initialPosition;
	}
};

class DoublyLinkedList{
	private:
	Node* firstNode;
	Node* lastNode;
	int size;

	public:
	DoublyLinkedList(int people){
		size = 0;
		for(int i = 0; i < people; i++){
			addNode();
		}
	}
	~DoublyLinkedList(){
		delete firstNode;
	}
	void addNode(){
		if(size){
			Node* aux = new Node(size + 1);
			lastNode->setNextNode(aux);
			aux->setPreviousNode(lastNode);
			lastNode = aux;
			firstNode->setPreviousNode(lastNode);
			lastNode->setNextNode(firstNode);
			size++;
		}
		else{
			firstNode = new Node(1);
			firstNode->setNextNode(firstNode);
			firstNode->setPreviousNode(firstNode);
			lastNode = firstNode;
			size++;
		}
	}
	void removeNode(Node* node){
		node->getPreviousNode()->setNextNode(node->getNextNode());
		node->getNextNode()->setPreviousNode(node->getPreviousNode());
		if(node == firstNode){
			firstNode = node->getNextNode();
		}
		if(node == lastNode){
			lastNode = node->getPreviousNode();
		}
		delete node;
		size--; //Não afetará o atributo initialPosition de novos nodes, já que nesse caso, todos são criados antes de um ser destruido.
	}
	int getSize(){
		return size;
	}
	Node* getFirstNode(){
		return firstNode;
	}
};

Node* kill(int n, Node* currentNode, DoublyLinkedList* list){
	Node* aux;
	if(n > 1){
		aux = kill(n - 1, currentNode->getNextNode(), list);
	}
	else{
		aux = currentNode->getNextNode();
		list->removeNode(currentNode);
	}
	return aux;
}

int josephus(int people, int step){
	DoublyLinkedList* list = new DoublyLinkedList(people);
	Node* currentNode = list->getFirstNode();
	while(list->getSize() > 1){
		currentNode = kill(step, currentNode, list);
	}
	int aux = list->getFirstNode()->getInitialPosition();
	delete list;
	return aux;
}

int main(){
	int testCases, people, step;
	cin >> testCases;
	for(int i = 1; i <= testCases; i++){
		cin >> people >> step;
		cout << "Case " << i << ": " << josephus(people, step) << endl;
	}
}