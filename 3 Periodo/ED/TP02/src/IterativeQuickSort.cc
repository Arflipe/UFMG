#include "QuickSort.h"

void iterative(int left, int right, Register* r, int* comps, int* regCopies){
	int i, j;
	Stack* s = new Stack();
	Node top;
	top.setLeft(left);
	top.setRight(right);
	s->push(top);
	(*regCopies)++;

	do{
		if(right > left){
			partition(left, right, &i, &j, r, comps, regCopies);
			top.setRight(j);
			top.setLeft(left);
			s->push(top);
			(*regCopies)++;
			left = i;
		}
		else{
			s->pop(&top);
			(*regCopies)++;
			left = top.getLeft();
			right = top.getRight();
		}
		(*comps)++;
	} while(!s->isEmpty());
	delete s;
}