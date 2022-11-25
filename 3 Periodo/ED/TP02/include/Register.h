#ifndef REGISTER_H
#define REGISTER_H

#include "memlog.h"

inline int keyComps = 0;
inline int regCopies = 0;

class Register{
	private:
	int key;
	char matrix[15][200];
	float array[10];

	public:
	Register();
	int getKey();
	void setKey(int key);
};

#endif