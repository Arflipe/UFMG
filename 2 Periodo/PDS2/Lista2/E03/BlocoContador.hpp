#ifndef BLOCOCONTADOR_H
#define BLOCOCONTADOR_H

#include "Bloco.hpp"

class BlocoContador : public Bloco{
	public:
	BlocoContador(Coordenada _coord);
	virtual bool revelar(vector<vector<Bloco*>>& tabuleiro) override;
	virtual ~BlocoContador();
	void incrementarValor();
};

#endif