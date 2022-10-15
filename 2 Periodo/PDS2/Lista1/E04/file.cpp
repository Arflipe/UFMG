#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int y = 1;
	int x = 1;
	int id = 1;
	ostringstream oss;
	oss << "Drone: " << id << ", Posição: [" << x << ", " << y << "]";
	string mensagem = oss.str();
	string mensagem2 = mensagem;
	cout << mensagem << endl;
	cout << mensagem2 << endl;

	// cout << sqrt(pow((5 - 7), 2) + pow((8 - 2), 2)) << endl;
}
