#ifndef AVLDICT_H
#define AVLDICT_H

#include "AVLNode.h"

class AVLDict{
	private:
	AVLNode* root;

	public:
	AVLDict();
	void insert(Entry* newEntry);
	void recursiveInsert(AVLNode* &node, AVLNode* parent, Entry* newEntry);
	void remove();
	void recursiveRemove(AVLNode* &node);
	void balance(AVLNode* node);
	void refreshHeight(AVLNode* node);
	int getBalanceFactor(AVLNode* node);
	int getHeight(AVLNode* node);
	void rightRotation(AVLNode* node);
	void leftRotation(AVLNode* node);
	void grandparentLeft(AVLNode* node);
	void grandparentRight(AVLNode* node);
};

#endif