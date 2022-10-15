#ifndef URSIDAE_H
#define URSIDAE_H

#define FAMILIA_URSIDAE "Ursidae"
#define PESO_PORCAO_URSIDAE 5
#define COMIDA_URSIDAE "Peixe"

#include "Animal.hpp"

class Ursidae : public Animal{
	public:
	Ursidae(string _nome, int _idade);
};

#endif