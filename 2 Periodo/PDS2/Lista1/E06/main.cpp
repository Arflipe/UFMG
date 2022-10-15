#include "avaliacao_basica_nba.hpp"
#include "Jogador.hpp"
#include "Time.hpp"
#include "RegistroNBA.hpp"

int main() {
	RegistroNBA times;
	char comando;
	while(cin >> comando){
		string nomeTime;
		string nomeJogador;
		string posicao;
		int salario;
		switch (comando){
		case 't':
			cin >> nomeTime;
			times.adicionar_time(nomeTime);
			break;
		case 'j':
			cin >> nomeTime >> nomeJogador >> posicao >> salario;
			times.adicionar_jogador(nomeTime, nomeJogador, posicao, salario);
			break;
		case 'l':
			cin >> nomeTime;
			times.imprimir_lista_jogadores_time(nomeTime);
			break;
		case 'f':
			cin >> nomeTime;
			times.imprimir_folha_consolidada_time(nomeTime);
			break;
		case 'g':
			times.imprimir_folha_salarial_geral();
			break;
		case 'b':
			avaliacao_basica();
			break;
		default:
			break;
		}
	}
	return 0;
}