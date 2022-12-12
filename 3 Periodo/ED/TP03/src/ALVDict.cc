#include "AVLDict.h"

AVLDict::AVLDict(){
	root = nullptr;
}

void AVLDict::insert(Entry* newEntry){
	recursiveInsert(root, nullptr, newEntry);
}

void AVLDict::recursiveInsert(AVLNode* &node, AVLNode* parent, Entry* newEntry){
	if(node == nullptr){
		node = new AVLNode(newEntry);
		if(parent != nullptr){
			node->parent = parent;
			balance(node);
		}
	}
	else{
		if(newEntry->getWord() < node->entry->getWord()){
			recursiveInsert(node->left, node, newEntry);
		}
		else{
			recursiveInsert(node->right, node, newEntry);
		}
	}
}

bool AVLDict::searchEntry(string word, string newMeaning, char type){
	return recursiveSearch(root, word, newMeaning, type);
}

bool AVLDict::recursiveSearch(AVLNode* node, string word, string newMeaning, char type){
	if(node == nullptr){
		return false;
	}
	if(node->entry->getWord() == word){
		if(node->entry->getType() != type){
			Entry* newEntry = new Entry(word, type);
			if(!newMeaning.empty()){
				newEntry->includeMeaning(newMeaning);
			}
			if(node->entry->getType() > type){
				recursiveInsert(node->left, node, newEntry);
			}
			else{
				recursiveInsert(node->right, node, newEntry);
			}

		}
		else{
			if(!newMeaning.empty()){
				node->entry->includeMeaning(newMeaning);
			}
		}
		return true;
	}
	if(node->entry->getWord() > word){
		return recursiveSearch(node->left, word, newMeaning, type);
	}
	else{
		return recursiveSearch(node->right, word, newMeaning, type);
	}
}

void AVLDict::remove(){
	recursiveRemove(root);
	rebalance(root);
}

void AVLDict::recursiveRemove(AVLNode* &node){
	if(node != nullptr){
		recursiveRemove(node->left);
		recursiveRemove(node->right);
		if(node->entry->hasMeanings()){
			if(node->left == nullptr){
				AVLNode* aux = node;
				node = node->right;
				if(node != nullptr){
					node->parent = aux->parent;
				}
				delete aux;
			}
			else if(node->right == nullptr){
				AVLNode* aux = node;
				node = node->left;
				if(node != nullptr){
					node->parent = aux->parent;
				}
				delete aux;
			}
			else{
				predecessor(node, node->left);
			}
		}
	}
}

void AVLDict::rebalance(AVLNode* node){
	if(node->left == nullptr && node->right == nullptr){
		balance(node);
	}
	if(node->left != nullptr){
		rebalance(node->left);
	}
	if(node->right != nullptr){
		rebalance(node->right);
	}
}

void AVLDict::print(){
	recursivePrint(root);
}

void AVLDict::recursivePrint(AVLNode* &node){
	if(node != nullptr){
		recursivePrint(node->left);
		node->entry->printEntry();
		recursivePrint(node->right);
	}
}

void AVLDict::predecessor(AVLNode* node, AVLNode* &r){
	if(r->right != nullptr){
		predecessor(node, r->right);
		return;
	}
	AVLNode* parent = r->parent;
	node->entry = r->entry;
	node = r;
	r = r->left;
	if(r != nullptr){
		r->parent = parent;
	}
	delete node;
}

void AVLDict::balance(AVLNode* node){
	if(node != nullptr){
		AVLNode* parent = node->parent;
		refreshHeight(node);
		int balanceFactor = getBalanceFactor(node);
		if(balanceFactor < -1){
			if(getBalanceFactor(node->left) > 0){
				leftRotation(node->left);
				grandparentRotate(node->left);
				rightRotation(node);
				grandparentRotate(node);
			}
			else{
				rightRotation(node);
				grandparentRotate(node);
			}
		}
		else if(balanceFactor > 1){
			if(getBalanceFactor(node->right) < 0){
				rightRotation(node->right);
				grandparentRotate(node->right);
				leftRotation(node);
				grandparentRotate(node);
			}
			else{
				leftRotation(node);
				grandparentRotate(node);
			}
		}
		balance(parent);
	}
}

void AVLDict::refreshHeight(AVLNode* node){
	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	node->height = max(leftHeight, rightHeight) + 1;
	if(node->parent != nullptr){
		refreshHeight(node->parent);
	}
}

int AVLDict::getBalanceFactor(AVLNode* node){
	if(node == nullptr){
		return 0;
	}
	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	return rightHeight - leftHeight;
}

int AVLDict::getHeight(AVLNode* node){
	if(node == nullptr){
		return 0;
	}
	return node->height;
}

void AVLDict::rightRotation(AVLNode* node){
	AVLNode* aux = node->left;
	node->left = node->left->right;
	if(node->left != nullptr){
		node->left->parent = node;
	}
	aux->right = node;
	aux->parent = node->parent;
	node->parent = aux;
}

void AVLDict::leftRotation(AVLNode* node){
	AVLNode* aux = node->right;
	node->right = aux->left;
	if(node->right != nullptr){
		node->right->parent = node;
	}
	aux->left = node;
	aux->parent = node->parent;
	node->parent = aux;
}

void AVLDict::grandparentRotate(AVLNode* node){
	if(node->parent->parent == nullptr){
		root = node->parent;
	}
	else{
		if(node->parent->parent->left == node){
			node->parent->parent->left = node->parent;
		}
		else{
			node->parent->parent->right = node->parent;
		}
	}
	refreshHeight(node);
}

