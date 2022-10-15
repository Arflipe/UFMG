#include "Alimentacao.hpp"

// Destrutor de alimentação
Alimentacao::Alimentacao(){}

// Construtor de alimentação
Alimentacao::Alimentacao(int _pesoPorcao, string _comida) : pesoPorcao(_pesoPorcao), comida(_comida){}

// Retorna o peso da alimentação do animal
double Alimentacao::pesoRefeicao(double numPorcoes){
	return numPorcoes * pesoPorcao;
}

// Altera a descrição da alimentação
void Alimentacao::setDescricao(string _descricao){
	descricao = _descricao;
}

// Retorna o tipo de comida da alimentação
string Alimentacao::getTipo(){
	return comida;
}

// Retorna a descrição da alimantação
string Alimentacao::getDescricao(){
	return descricao;
}