#ifndef REGISTER_H
#define REGISTER_H

class Register{
	private:
	int key;
	char matrix[15][200];
	float array[10];

	public:
	Register();
	Register(int key);
	int getKey();
	void setKey(int key);
};

#endif