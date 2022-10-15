#include "Drone.hpp"
#include "Ponto2D.hpp"


Drone::Drone(int id, Ponto2D ponto, double raio){
	_id = id;
	_ponto = ponto;
	_raio = raio;
	_mensagens_salvas = 0;
}

void Drone::mover(double v, double th, double t){
	_ponto._x += cos(th) * v * t;
	_ponto._y += sin(th) * v * t;
	_energia -= v * t;
	if(_energia <= 50)
	{
		cout << "Alerta, energia baixa!" << endl;
	}
}

double Drone::calcular_distancia(Drone* drone){
	return _ponto.calcular_distancia(&drone->_ponto);
}

void Drone::broadcast_mensagem(Drone** drones, int n){
	ostringstream oss;
	oss << fixed << setprecision(2); 
	oss << "Drone: " << _id << ", Posição: [" << _ponto._x << ", " << _ponto._y << "]";
	string mensagem = oss.str();
	for(int i = 0; i < n; i++)
	{
		if((calcular_distancia(drones[i]) <= _raio) && i != _id){
			drones[i]->salvar_mensagem(mensagem);
		}
	}
}

void Drone::salvar_mensagem(string mensagem){
	switch (_mensagens_salvas % 5)
	{
	case 0:
		_mensagens[0] = mensagem;
		_mensagens_salvas++;
		break;
	case 1:
		_mensagens[1] = mensagem;
		_mensagens_salvas++;
		break;
	case 2:
		_mensagens[2] = mensagem;
		_mensagens_salvas++;
		break;
	case 3:
		_mensagens[3] = mensagem;
		_mensagens_salvas++;
		break;
	case 4:
		_mensagens[4] = mensagem;
		_mensagens_salvas++;
		break;
	}
	
}

void Drone::imprimir_mensagens_recebidas(){
	cout << "Mensagens de " << _id << ":" << endl;
	int num_mensagens;
	if(_mensagens_salvas > 5){
		num_mensagens = 5;
	}
	else{
		num_mensagens = _mensagens_salvas;
	}
	for(int i = 0; i < num_mensagens; i++){
		cout << _mensagens[i] << endl;
	}
}

void Drone::imprimir_status(){
	cout << _id << "	" << _ponto._x << "	" << _ponto._y << "	" << _energia << endl;
}

