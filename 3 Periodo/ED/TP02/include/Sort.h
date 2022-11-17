#ifndef SORT_H
#define SORT_H

#include "RandArray.h"
#include "QuickSort.h"
#include "Timer.h"
#include "Mean.h"

#include <fstream>
using namespace std;
#define SORTING_TYPES 5

double* Sort(int size, int type, int seed, int extra);

#endif