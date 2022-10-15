#include <iostream>

class No {
	public:
		No(char letra){
			this->letra = letra;
			esq = nullptr;
			dir = nullptr;
		}
		
	private:
		char letra;
		No *esq;
		No *dir;
		friend class ArvoreBinaria;
};

class ArvoreBinaria {
	public:
		ArvoreBinaria(){
			raiz = nullptr;
		}

		~ArvoreBinaria(){
			Limpa();
		}

		void Insere(char valoraiz, char valorfolha, int lado){
			if(valoraiz == valorfolha){
				raiz = new No(valoraiz);
			}
			else{
				acharNo().
			}
			InsereRecursivo(raiz,letra);
		}

		void Caminha(int tipo){

		}

		void Limpa(){
			ApagaRecursivo(raiz);
			raiz = nullptr;
		}

	private:
		void InsereRecursivo(No* &p, char letra){
			if(p==nullptr){
				p = new No();
				p->letra = letra;
			}
			else{
				if(letra < p->letra)
					InsereRecursivo(p->esq, letra);
				else
					InsereRecursivo(p->dir, letra);
			}
		}
		void ApagaRecursivo(No* p){
			if(p!=nullptr){
				ApagaRecursivo(p->esq);
				ApagaRecursivo(p->dir);
				delete p;
			}
		}

		void PorNivel(){

		}

		void PreOrdem(No* p){
			if(p!=nullptr){
				std::cout << p->letra<< std::endl;
				PreOrdem(p->esq);
				PreOrdem(p->dir);
			}
		}

		void InOrdem(No* p){
			if(p!=nullptr){
				InOrdem(p->esq);
				std::cout << p->letra<< std::endl;
				InOrdem(p->dir);
			}
		}

		void PosOrdem(No* p){
			if(p!=nullptr){
				PosOrdem(p->esq);
				PosOrdem(p->dir);
				std::cout << p->letra<< std::endl;
			}
		}

		No* acharNo(){

		}

		No* raiz;
};

int main(){
	ArvoreBinaria* arvore = new ArvoreBinaria();
	char prefixo[26];
	char infixo[26];
	std::cin >> prefixo;
	std::cin >> infixo;
	char raiz = prefixo[0];
	arvore->Insere(raiz);
	int posRaiz;

	for(int i = 0; i < 26; i++){
		if(raiz == infixo[i]){
			posRaiz = i;
		}
	}

	for(int i = 1; i < 26; i++){
		int posPre = 0;
		int posLetra;
		char letra = prefixo[i];
		for(int j = 0; j < posRaiz; j++){
			if(letra == infixo[j]){
				posLetra = j;
			}
			if(j == i){

			}
		}
	}

	// while(std::cin >> letra){
	// 	arvore->Insere(letra);
	}
}