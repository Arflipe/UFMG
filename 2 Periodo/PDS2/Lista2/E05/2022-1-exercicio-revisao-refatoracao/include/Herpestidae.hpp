#ifndef HERPESTIDAE_H
#define HERPESTIDAE_H

#define FAMILIA_HERPESTIDAE "Herpestidae"
#define PESO_PORCAO_HERPESTIDAE 1
#define COMIDA_HERPESTIDAE "Ração"

#include "Animal.hpp"



class Herpestidae : public Animal {
	public:
	Herpestidae(string _nome, int _idade);
};

#endif