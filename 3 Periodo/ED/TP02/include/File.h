#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

using namespace std;

void fHeader(int type, int extra, ofstream& convertedImage);
void fBody(int size, int meanComps, int meanRegCopies, double meanTime, ofstream& convertedImage);

#endif