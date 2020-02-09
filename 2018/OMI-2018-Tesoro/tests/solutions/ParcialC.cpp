#include "tesoro.h"
#include <vector>
using namespace std;

void BuscaTesoros(int n, int m, int k){
	
	
	if(!k) return;
	int ultimo = 0;
	int columna = 0, fila , act;
	vector<vector<int> > manual(n+1,vector<int>(m+1));

	for(int i = 1; i <= k ; i ++){		
		columna ++;
		act = Preguntar(n,columna);
		while(act == ultimo){
			for(int i = 1 ; i <= n ; i++)
				manual[i][columna] = manual[i][columna - 1];
			columna++;
			act = Preguntar(n,columna);
		}
		ultimo ++;		
		manual[n][columna] = act;
		
		fila = n;
		for(int i = 1; i < n-1; i ++){
			manual[i][columna] = Preguntar(i,columna);
			if(manual[i][columna] - manual[i-1][columna] - manual[i][columna-1] + manual[i-1][columna-1] == 1)
				fila = i;
		}			
		
		Cavar(fila,columna);

	}

}
