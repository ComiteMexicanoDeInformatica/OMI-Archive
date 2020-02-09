#include "tesoro.h"
#include <vector>
using namespace std;

void BuscaTesoros(int n, int m, int k){
	int ultima = 0;
	int fil, col;
	int ini, fin, mitad;
	vector<vector<int> > cuenta(n+1,vector<int>(m+1));
	if(!k) return;
	for(int i = 1; i <= k ; i ++){
		ini = ultima+1, fin = m;
		mitad = (ini+fin)/2;
		while(ini < fin){
			if(Preguntar(n,mitad) >= i)
				fin = mitad;
			else
				ini = mitad+1;
			mitad = (ini+fin)/2;
		}

		col = ini;

		for(int a = ultima+1; a < col ; a ++)
			for(int b = 0 ; b <= n ; b ++  )
				cuenta[b][a] = cuenta[b][a-1];

		ini = 1, fin = n;
		mitad = (ini+fin)/2;

		while(ini < fin){
			if(Preguntar(mitad,col) == cuenta[mitad][col-1]+1)
				fin = mitad;
			else
				ini = mitad+1;
			mitad = (ini+fin)/2;
		}

		fil = fin;

		for(int j = 1; j < fil; j ++)
			cuenta[j][col] = cuenta[j][col-1];
		for(int j = fil; j <= n ; j++)
			cuenta[j][col] = cuenta[j][col-1]+1;

		Cavar(fil,col);

		ultima = col;

	}

}
