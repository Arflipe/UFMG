#ifndef SORT_H
#define SORT_H

#include "RandArray.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "Timer.h"
#include "Mean.h"

#define SORTING_TYPES 7

double* Sort(int size, int type, int seed, int extra);

#endif