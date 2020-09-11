#include <iostream>
#include <algorithm>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool completo(int u, int v, vector< vector<int> > &E){
	int n = v - u + 1;
	int sum = E[v][v] + (u > 0 ? - E[v][u - 1] - E[u - 1][v] + E[u - 1][u - 1] : 0);
	return sum == n * n;
}

int main(){
	optimizar_io
	
	int n, m;
	cin >> n >> m;
	
	vector< vector<int> > E(n, vector<int>(n, 0) );

	int i, j;
	int u, v;
	
	for(i = 0; i < m; i++){
		cin >> u >> v;		
		E[u][v]++;
		E[v][u]++;
	}
	
	for(i = 0; i < n; i++)
		E[i][i] = 1;
	
	for(i = 1; i < n; i++)
		E[i][0] += E[i - 1][0];
	for(j = 1; j < n; j++)
		E[0][j] += E[0][j - 1];
	for(i = 1; i < n; i++)
		for(j = 1; j < n; j++)
			E[i][j] += E[i][j - 1] + E[i-1][j] - E[i - 1][j - 1];
	
	int res = 1;
	for(i = 0; i < n; i++)
		for(j = i + res; j < n; j++)
			if( completo(i, j, E) )
				res = j - i + 1;
			else 
				break;
			
	cout << res << "\n";
	
	return 0;
}