#include <iostream>
#include <algorithm>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool completo(int u, int v, vector< vector<int> > &E){
	int i, j;
	for(i = u; i <= v; i++)
		for(j = i + 1; j <= v; j++)
			if( !E[i][j] )
				return false;
	return true;
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
		if(u > v)
			swap(u, v);
		
		E[u][v]++;
	}
	
	int res = 1;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if( completo(i, j, E) )
				res = max( res, j - i + 1 );
			
			
	cout << res << "\n";
	
	return 0;
}