#include <iostream>

using namespace std;

int main()
{
	// 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
	int var;
	cin >> var;
	// 2) Declare um ponteiro para inteiros e inicialize com valor nulo
	int *ptr = nullptr;
	// 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com os dados passados
	int tamanho;
	cin >> tamanho;
	int vet[tamanho];
	for (int i = 0; i < tamanho; i++)
	{
		cin >> vet[i];
	}
	// 4) Imprima o ENDEREÇO da variável declarada em (1)
	cout << &var << endl;
	// 5) Imprima o VALOR da variável declarada em (1)
	cout << var << endl;
	// 6) Imprima o ENDEREÇO da variável declarada em (2)
	cout << &ptr << endl;
	// 7) Imprima o VALOR da variável declarada em (2)
	cout << ptr << endl;
	// 8) Imprima o ENDEREÇO da variável declarada em (3)
	cout << &vet << endl;
	// 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
	cout << &vet[0] << endl;
	// 10) Imprima o VALOR da primeira posição da variável declarada em (3)
	cout << vet[0] << endl;
	// 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
	ptr = &var;
	// 12) Imprima o VALOR da variável declarada em (2)
	cout << ptr << endl;
	// 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
	cout << *ptr << endl;
	// 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
	cout << (&var == ptr) << endl;
	// 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
	*ptr = 5;
	// 16) Imprima o VALOR da variável declarada em (1)
	cout << var << endl;
	// 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
	ptr = vet;
	// 18) Imprima o VALOR da variável declarada em (2)
	cout << ptr << endl;
	// 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
	cout << *ptr << endl;
	// 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
	ptr = &vet[0];
	// 21) Imprima o VALOR da variável declarada em (2)
	cout << ptr << endl;
	// 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
	cout << *ptr << endl;
	// 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
	for(int i = 0; i < tamanho; i++)
	{
		*(ptr + i) *= 10;
	}
	// 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
	for(int i = 0; i < tamanho; i++)
	{
		cout << vet[i];
		if(i < (tamanho - 1))
		{
			cout << ' ';
		}
	}
	cout << endl;
	// 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
	// Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
	for(int i = 0; i < tamanho; i++)
	{
		cout << *(vet + i);
		if(i < (tamanho - 1))
		{
			cout << ' ';
		}
	}
	cout << endl;
	// 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
	// Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
	for(int i = 0; i < tamanho; i++)
	{
		cout << *(ptr + i);
		if(i < (tamanho - 1))
		{
			cout << ' ';
		}
	}
	cout << endl;
	// 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
	ptr = &vet[4];
	// 28) Imprima o VALOR da variável declarada em (2)
	cout << ptr << endl;
	// 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
	cout << *ptr << endl;
	// 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4
	cout << *(ptr - 4) << endl;
	// 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
	int **ptrptr = &ptr;
	// 32) Imprima o VALOR da variável declarada em (31)
	cout << ptrptr << endl;
	// 33) Imprima o ENDEREÇO da variável declarada em (31)
	cout << &ptrptr << endl;
	// 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
	cout << *ptrptr << endl;
	// 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
	cout << **ptrptr << endl;
}