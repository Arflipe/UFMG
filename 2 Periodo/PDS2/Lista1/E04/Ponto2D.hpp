#ifndef PONTO2D_H
#define PONTO2D_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Ponto2D
{
	double _x, _y;

	Ponto2D() = default;
	Ponto2D(double, double);
	double calcular_distancia(Ponto2D* ponto);
	string get_dados();
};

#endif