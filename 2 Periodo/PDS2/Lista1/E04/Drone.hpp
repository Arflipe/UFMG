#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include "Ponto2D.hpp"

using namespace std;

struct Drone
{
	int _id;
	Ponto2D _ponto;
	double _raio;
	double _energia = 100;
	string _mensagens[5];
	int _mensagens_salvas;
	
	Drone(int, Ponto2D, double);
	void mover(double v, double th, double t);
	double calcular_distancia(Drone* drone);
	void broadcast_mensagem(Drone** drones, int n);
	void salvar_mensagem(string mensagem);
	void imprimir_mensagens_recebidas();
	void imprimir_status();
};

#endif