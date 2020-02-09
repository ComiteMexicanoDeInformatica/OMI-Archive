#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
const int INF = 1<<30;

vector<vector< char > > mapa;
vector<vector< bool > > visi;

int N,M;
int menorF, menorC , mayorF , mayorC;

void busca(int f,int c){
	if(f < 0 || f >= N || c < 0 || c >= M ) return;
	if(visi[f][c]) return;
	if(mapa[f][c] == '0') return;	

	if(f < menorF) menorF = f;
	if(f > mayorF) mayorF = f;
	if(c < menorC) menorC = c;
	if(c > mayorC) mayorC = c;

	visi[f][c] = true;

	busca(f-1,c);
	busca(f,c+1);
	busca(f+1,c);
	busca(f,c-1);
}

int main(){

	optimizar_io(0);

	cin >> N >> M;
	mapa = vector< vector< char > >(N, vector< char > (M));	
	for(int i = 0; i < N ; i ++){
		for(int j = 0; j < M ; j ++){
			cin >> mapa[i][j];
		}
	}
	
	visi = vector< vector< bool > >(N , vector< bool > (M));
	for(int i = 0; i < N ; i ++){
		for(int j = 0; j < M ; j ++){
			if(mapa[i][j] == '1' && !visi[i][j]){
				menorF = menorC = INF;
				mayorF = mayorC = -INF;
				busca(i,j);
				for(int a = menorF ; a <= mayorF ; a ++)
					for(int b = menorC; b <= mayorC ; b++){
						visi[a][b] = true;
						mapa[a][b] = '1';
					}
			}
		}
	}	
	
	for(int i = 0; i < N ; i ++){
		for(int j = 0; j < M ; j ++){
			cout << mapa[i][j];		
		}
		cout << '\n';
	}

	return 0;
}
