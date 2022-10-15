#include <stdio.h>

void calcCoord(int ponto, int *x, int *y){
	switch (ponto % 4){
	case 0:
		*x = ponto / 2;
		*y = 0;
		break;
	case 1:
		*x = -1;
		*y = (ponto + 1) / 2;
		break;
	case 2:
		*x = -((ponto + 2) / 2);
		*y = 0;
		break;
	case 3:
		*x = 0;
		*y = -((ponto + 1) / 2);
		break;
	}
}

int main(){
	int ponto, x, y;
	scanf("%d", &ponto);
	calcCoord(ponto, &x, &y);
	printf("%d %d\n", x, y);
	return 0;
}