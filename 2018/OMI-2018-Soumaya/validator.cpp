#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>
using namespace std;

const int INF = 1<<30;

bool valido(int N, int M, vector<string> &orig, vector<string> &mat){

	for(int i = 0; i < N ; i ++)
		for(int j = 0; j < M ; j ++)
			if(orig[i][j] == '1' && mat[i][j] == '0')
				return false;

	int menorF, menorC, mayorF, mayorC;
	vector< vector<bool> > visi(N,vector<bool>(M));

	function<void(int,int)> busca = [&](int f,int c){

		if( f < 0 || f >= N || c < 0 || c >= M ) return;
		if( visi[f][c] ) return;
		if( mat[f][c] == '0' ) return;

		visi[f][c] = true;
		if(f < menorF) menorF = f;
		if(f > mayorF) mayorF = f;
		if(c < menorC) menorC = c;
		if(c > mayorC) mayorC = c;

		busca(f-1,c);
		busca(f,c+1);
		busca(f+1,c);
		busca(f,c-1);

	};

	for(int i = 0; i < N ; i ++){
		for(int j = 0; j < M ; j++){
			if(visi[i][j] || mat[i][j] == 0) continue;
			menorF = menorC = INF;
			mayorF = mayorC = -INF;
			busca(i,j);
			for(int v = menorF; v <= mayorF; v++)
				for(int h = menorC; h <= mayorC ; h++)
					if(mat[v][h] == '0') return false;	
		}
	}

	return true;

}

bool lectura(int &N,int &M,vector<string> &orig, vector<string> &mat, int &menor, int &unos){

	try{
		ifstream case_in("data.in");	

		case_in >> N >> M;
		orig = vector<string>(N);
		mat = vector<string>(N);

		for(int i = 0; i < N ; i++)
			case_in >> orig[i];	

		case_in.close();

		ifstream case_out("data.out");

		case_out >> menor ;
		
		case_out.close();

		for(int i = 0; i < N ; i++)	{
			cin >> mat[i];
			if(mat[i].size() != M) return false;
			for(int j = 0; j < M ; j ++)
				if(mat[i][j] == '1') unos++;
				else if(mat[i][j] != '0') return false;
		}
	} catch(...){
		return false;
	}
	return true;
}

int main(){
	
	int N, M;
	int menor;
	int unos = 0;
	vector<string> orig, mat;
	int AC, resultado;
	double individual;
	int puntos, obtenidos;	

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	if(!lectura(N,M,orig,mat,menor,unos)){
		cout << "0\n";
		return 0;
	}
	
	AC = N*M - menor;
	resultado = N*M - unos;


	if(valido(N,M,orig,mat)){

		if( N > 50 && M > 50 ) puntos = 6;
		else if( N == 4 && M == 13) puntos = 2;
		else puntos = 4;

		obtenidos = resultado*puntos/AC;
		individual = 1.0/puntos;

		cout << double(obtenidos)*individual << '\n';
		
	} else 
		cout << "0\n";
}
