#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Register.h"
#include "Swap.h"

void heapSort(Register* r, int size, int* comps, int* regCopies);
void heapify(Register* r, int size, int* comps, int* regCopies);
void redo(Register* r, int left, int right, int* comps, int* regCopies);

#endif