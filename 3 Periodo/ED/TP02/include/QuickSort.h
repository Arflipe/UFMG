#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Register.h"
#include "SelectionSort.h"
#include "Stack.h"

void quickSort(Register* r, int size, int type, int extra);
void partition(int left, int right, int* i, int* j, Register* r);

// Recursive QuickSort

void recursiveOrder(int left, int right, Register* r);

// Median QuickSort

void medianPartition(int left, int right, int* i, int* j, Register* r, int n);
void medianOrder(int left, int right, Register* r, int medianOf);

// Selection QuickSort

void selectionOrder(int left, int right, Register* r, int maxSize);

// Iterative QuickSort

void iterative(int left, int right, Register* r);

// Smart Stack QuickSort

void smartStack(int left, int right, Register* r);


#endif