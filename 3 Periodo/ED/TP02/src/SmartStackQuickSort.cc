#include "QuickSort.h"

void smartStack(int left, int right, Register* r, int* comps, int* regCopies){
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
			if((j - left) > (right - i)){
				top.setLeft(left);
				top.setRight(j);
				s->push(top);
				(*regCopies)++;
				left = i;
			}
			else{
				top.setLeft(i);
				top.setRight(right);
				s->push(top);
				(*regCopies)++;
				right = j;
			}
			(*comps)++;
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