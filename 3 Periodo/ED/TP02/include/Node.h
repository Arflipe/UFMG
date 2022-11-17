#ifndef NODE_H
#define NODE_H

class Node{
	private:
	int left;
	int right;
	Node* nextNode;
	
	public:
	Node();
	void setLeft(int left);
	void setRight(int right);
	int getLeft();
	int getRight();

	friend class Stack;
};

#endif