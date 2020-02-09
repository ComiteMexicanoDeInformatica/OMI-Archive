#include <bits/stdc++.h>
#include "tesoro.h"
using namespace std;

int n, m;
vector < pair < int, int > > tesoros; // Guarda las coordenadas de los tesoros
vector < pair < int, int > > reportados; // Guarda los tesoros reportados
int no_preguntas; // Guarda el número de preguntas que llevas hechas
int llamadas_cavar;

bool error_cavar = false;
// En el momento que Cavar regrese false ya no podrás llamar a Cavar nuevamente
bool Cavar(int i, int j) {
	printf("\nLlamada a Cavar(%d, %d)\n", i, j);
	llamadas_cavar++;

	if(error_cavar)
		puts("Ya no puedes llamar a Cavar.");

	// Verifica si hay un tesoro en esa casilla
	bool encontrado = false;
	for(int k = 0; k < tesoros.size() && !encontrado; ++k) {
		if(tesoros[k].first == i && tesoros[k].second == j)
			encontrado = true;
	}

	// Verifica si ya habías reportado ese tesoro
	bool ya_reportado = false;
	for(int k = 0; k < reportados.size(); ++k)
		if(reportados[k].first == i
		&& reportados[k].second == j)
			ya_reportado = true;

	if(encontrado && !ya_reportado && llamadas_cavar <= tesoros.size()) {
		puts("Encontraste un tesoro!");
		reportados.push_back({i,j});
		return true;
	}


	if(llamadas_cavar > tesoros.size())
		puts("Has excedido la cantidad de llamadas a Cavar.");
	else if(!encontrado)
		puts("Lo siento. No hay un tesoro en esa casilla.");
	else
		puts("Tesoro anteriormente reportado.");

	error_cavar = true;

	return false;
}

int Preguntar(int i, int j) {
	no_preguntas++; // Una pregunta más
	printf("\nLlamada a preguntar(%d, %d)\n", i, j);

	// Checa si la casilla consultada está fuera del mapa
	if(i <= 0 || j <= 0 || i > n || j > m) {
		puts("Consulta fuera del espacio de cobertura.");
		return -1;
	}

	// Recorre todos los tesoros para contestar la pregunta
	int respuesta = 0;
	for(int k = 0; k < tesoros.size(); ++k) {
		if(tesoros[k].first <= i && tesoros[k].second <= j)
			respuesta++;
	}
	return respuesta;
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			char car; scanf(" %c", &car);
			if(car == '1') tesoros.push_back({i, j});
		}

	fclose(stdin);

	printf("Llamando a BuscaTesoros(%d, %d, %lu)\n", n, m, tesoros.size());
	BuscaTesoros(n, m, tesoros.size()); // Llamada inicial a tu función

	printf("\nHiciste %d preguntas.\n", no_preguntas);

	if(tesoros.size() > reportados.size())
		printf("\nSolo encontraste %lu tesoros :(\n", reportados.size());
	else
		puts("Excelente! Encontraste todos los tesoros.");

	return 0;
}
