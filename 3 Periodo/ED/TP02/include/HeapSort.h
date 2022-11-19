#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Register.h"
#include "Swap.h"

void heapSort(Register* r, int size);
void heapify(Register* r, int size);
void redo(Register* r, int left, int right);

#endif