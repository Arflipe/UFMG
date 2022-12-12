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
			refreshHeight(node);
			balance(parent->parent);
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

void AVLDict::remove(){
	recursiveRemove(root);
}

void AVLDict::recursiveRemove(AVLNode* &node){
	if(node != nullptr){
		recursiveRemove(node->left);
		recursiveRemove(node->right);
		if(node->left == nullptr){
			AVLNode* aux = node;
			node = node->right;
			delete aux;
		}
		else if(node->right == nullptr){
			AVLNode* aux = node;
			node = node->left;
			delete aux;
		}
		else{
			
		}
	}
}

void AVLDict::balance(AVLNode* node){
	int balanceFactor = getBalanceFactor(node);
	if(balanceFactor < -1){
		if(getBalanceFactor(node->left) > 0){
			leftRotation(node->left);
			grandparentLeft(node->left);
			rightRotation(node);
			grandparentLeft(node);
		}
		else{
			rightRotation(node);
			grandparentLeft(node);
			node->height = getHeight(node->left) + 1;
			refreshHeight(node);
		}
	}
	else if(balanceFactor > 1){
		if(getBalanceFactor(node->right) < 0){
			rightRotation(node->right);
			grandparentRight(node->right);
			leftRotation(node);
			grandparentRight(node);
		}
		else{
			leftRotation(node);
			grandparentRight(node);
			node->height = getHeight(node->left) + 1;
			refreshHeight(node);
		}
	}
	if(node != nullptr){
		balance(node->parent);
	}
}

void AVLDict::refreshHeight(AVLNode* node){
	if(node->parent != nullptr){
		int leftHeight = getHeight(node->parent->left);
		int rightHeight = getHeight(node->parent->right);
		node->parent->height = max(leftHeight, rightHeight) + 1;
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

void AVLDict::grandparentLeft(AVLNode* node){
	if(node->parent->parent == nullptr){
		root = node->parent;
	}
	else{
		node->parent->parent->left = node->parent;
	}
	node->height = getHeight(node->left) + 1;
	refreshHeight(node);
}

void AVLDict::grandparentRight(AVLNode* node){
	if(node->parent->parent == nullptr){
		root = node->parent;
	}
	else{
		node->parent->parent->right = node->parent;
	}
	node->height = getHeight(node->right) + 1;
	refreshHeight(node);
}