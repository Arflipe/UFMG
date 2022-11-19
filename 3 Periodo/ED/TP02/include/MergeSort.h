#ifndef MERGESORT_H
#define MERGESORT_H

#include "Register.h"

void mergeSort(Register* r, int left, int right, int* comps, int* regCopies);
void merge(Register* r, int left, int mid, int right);

#endif