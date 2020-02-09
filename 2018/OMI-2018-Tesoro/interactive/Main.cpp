#include <bits/stdc++.h>
#include "tesoro.h"
using namespace std;

int n, m, k;
int encontrados, no_preguntas;
int suma[1002][1002], A[1002][1002];
bool error = false;

bool Cavar(int i, int j) {
	if(i <= 0 || j <= 0 || i > n || j > m) {
		error = true;
		return false;
	}
	if(A[i][j]) {
		A[i][j] = 0;
		encontrados++;
		return true;
	} else {
		error = true;
		return false;
	}
}

int Preguntar(int i, int j) {
	no_preguntas++; // Una pregunta más
	if(i <= 0 || j <= 0 || i > n || j > m)
		return -1;
	return suma[i][j];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			char car; scanf(" %c", &car);
			suma[i][j] = suma[i-1][j] + suma[i][j-1] - suma[i-1][j-1];
			if(car == '1') {
				A[i][j] = 1;
				suma[i][j]++;
				k++;
			}
		}
	fclose(stdin);
	const int AC = 4*k*(ceil(log2(n))+ceil(log2(m)));
	const int PA60 = k*ceil(log2(n))*ceil(log2(m));

	BuscaTesoros(n, m, k);

	if(error || encontrados < k) {
		printf("0\n");
	} else {
		double puntos = 0;
		if(no_preguntas <= AC) puntos = 1.0;
		else if(no_preguntas <= PA60) puntos = 0.50;
		else puntos = 0.25;
		printf("%f\n", puntos);
	}

	return 0;
}
