#ifndef MERGESORT_H
#define MERGESORT_H

#include "Register.h"

void mergeSort(Register* r, int left, int right);
void merge(Register* r, int left, int mid, int right);

#endif