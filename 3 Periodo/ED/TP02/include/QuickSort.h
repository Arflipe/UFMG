#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Register.h"
#include "SelectionSort.h"
#include "Stack.h"

void quickSort(Register* r, int size, int type, int extra, int* comps, int* regCopies);
void partition(int left, int right, int* i, int* j, Register* r, int* comps, int* regCopies);

// Recursive QuickSort

void recursiveOrder(int left, int right, Register* r, int* comps, int* regCopies);

// Median QuickSort

void medianPartition(int left, int right, int* i, int* j, Register* r, int n, int* comps, int* regCopies);
void medianOrder(int left, int right, Register* r, int medianOf, int* comps, int* regCopies);

// Selection QuickSort

void selectionOrder(int left, int right, Register* r, int maxSize, int* comps, int* regCopies);

// Iterative QuickSort

void iterative(int left, int right, Register* r, int* comps, int* regCopies);

// Smart Stack QuickSort

void smartStack(int left, int right, Register* r, int* comps, int* regCopies);


#endif