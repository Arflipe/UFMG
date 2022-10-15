#include "Ponto2D.hpp"

// Ponto2D() = default;

Ponto2D::Ponto2D(double x, double y)
{
	_x = x;
	_y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto)
{
	// cout << sqrt(pow((_x - ponto->_x), 2) + pow((_y - ponto->_y), 2)) << endl;
	return sqrt(pow((_x - ponto->_x), 2) + pow((_y - ponto->_y), 2));
}

string Ponto2D::get_dados()
{
	cout << "[" << _x << ", " << _y << "]" << endl;
	return 0;
}

