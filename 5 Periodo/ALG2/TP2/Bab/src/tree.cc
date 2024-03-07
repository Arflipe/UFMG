#include "tree.hpp"

#include <stack>

Tree::Tree(int root) {
	this->root = new Node(root);
}

Node* Tree::FindNode(Node* current, int city) {
	if (current->GetCity() == city) {
		return current;
	}
	for (list<Node>::iterator it = current->children.begin(); it != current->children.end(); ++it) {
		Node* node = this->FindNode(&(*it), city);
		if (node != nullptr) {
			return node;
		}
	}
	return nullptr;
}

void Tree::AddChild(int parent, int child) {
	Node* node = this->FindNode(this->root, parent);
	node->AddChild(child);
}

vector<int> Tree::PreOrder() {
	vector<int> result;
	stack<Node*> stack;
	stack.push(this->root);
	while (!stack.empty()) {
		Node* node = stack.top();
		stack.pop();
		result.push_back(node->GetCity());
		for (list<Node>::reverse_iterator it = node->children.rbegin(); it != node->children.rend(); ++it) {
			stack.push(&(*it));
		}
	}
	return result;
}

vector<int> Tree::OddDegreeNodes() {
	vector<int> result;
	stack<Node*> stack;
	stack.push(this->root);
	while (!stack.empty()) {
		Node* node = stack.top();
		stack.pop();
		if (node == this->root){
			if (node->children.size() % 2 == 1) {
				result.push_back(node->GetCity());
			}
		}
		else{
			if (node->children.size() % 2 == 0) {
				result.push_back(node->GetCity());
			}
		}
		for (list<Node>::reverse_iterator it = node->children.rbegin(); it != node->children.rend(); ++it) {
			stack.push(&(*it));
		}
	}
	return result;
}
