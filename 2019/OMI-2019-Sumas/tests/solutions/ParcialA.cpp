#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

typedef long long int Long;
typedef vector<Long> vL;
typedef vector<vL> vvL;

Long Mejor(vL &ar, int &ini, int &fin){
	int iniAct;	
	Long acum = -1;	
	int n = ar.size();
	Long ret = numeric_limits<Long>::min();
	for(int i = 0; i < n; i ++){
		if(acum < 0){
			acum = 0;
			iniAct = i;			
		}
		acum += ar[i];
		if(acum > ret){
			ret = acum;
			ini = iniAct;
			fin = i;
		}
	}
	return ret;
}

int main(){

	int N, M;

	optimizar_io(0);

	cin >> N >> M; 

	vvL mat(N, vL(M));
	vvL color(N, vL(M));

	for(int i = 0; i < N; i ++)
		for(int j = 0; j < M; j ++)
			cin >> mat[i][j];
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < M; j ++)
			cin >> color[i][j];

	int f1, c1, f2, c2;
	Long mayor = numeric_limits<Long>::min();	
	for(int i = 0; i < N; i ++){
		vL suma(M);
		for(int j = i; j < N; j ++){
			for(int k = 0; k < M; k ++)
				suma[k] += mat[j][k];
			int ini, fin;
			Long act = Mejor(suma, ini, fin);
			if(act > mayor){
				mayor = act;
				f1 = i, f2 = j;
				c1 = ini, c2 = fin;
			}
		}
	}

	cout << f1 << ' ' << c1 << ' ' << f2 << ' ' << c2 << '\n';

	return 0;
}