#ifndef AVLDICT_H
#define AVLDICT_H

#include "AVLNode.h"

class AVLDict{
	private:
	AVLNode* root;

	public:
	AVLDict();
	~AVLDict();
	void insert(string word, string newMeaning, char type);
	void recursiveInsert(AVLNode* &node, AVLNode* parent, Entry* newEntry);
	bool searchEntry(string word, string newMeaning, char type);
	bool recursiveSearch(AVLNode* node, string word, string newMeaning, char type);
	void remove();
	void recursiveRemove(AVLNode* &node);
	void rebalance(AVLNode* node);
	void print();
	void recursivePrint(AVLNode* &node);

	void predecessor(AVLNode* node, AVLNode* &r);
	void balance(AVLNode* node);
	void refreshHeight(AVLNode* node);
	int getBalanceFactor(AVLNode* node);
	int getHeight(AVLNode* node);
	void rightRotation(AVLNode* node);
	void leftRotation(AVLNode* node);
	void grandparentRotate(AVLNode* node);

	void clean();
	void recursiveClean(AVLNode* &node);
};

#endif