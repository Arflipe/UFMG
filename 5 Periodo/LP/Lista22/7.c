#include <stdlib.h>

const int N = 600;

void mult1(int Z[N][N], int X[N][N], int Y[N][N]) {
	int i, j, k;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				Z[i][j] += X[i][k] * Y[k][j];
}

void mult2(int Z[N][N], int X[N][N], int Y[N][N]) {
	int i, j, k;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				Z[i][k] += X[i][j] * Y[j][k];
}

void init(int X[N][N]) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			X[i][j] = rand() % 100;
}

void zero(int X[N][N]) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			X[i][j] = 0;
}

int main() {
	int X[N][N], Y[N][N], Z[N][N];
	init(X);
	init(Y);
	zero(Z);
	mult1(Z, X, Y);
}
