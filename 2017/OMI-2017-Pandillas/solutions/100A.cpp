#include <iostream>
#include <algorithm>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){
	optimizar_io
	
	int n, m;
	cin >> n >> m;
	
	vector< pair<int, int> > E(m);
	vector<int> largo(n), maximo(n);
	int i;
	
	for(i = 0; i < m; i++){
		cin >> E[i].first >> E[i].second;
		if( E[i].first > E[i].second )
			swap(E[i].first, E[i].second);
	}
	sort(E.begin(), E.end());
	
	for(i = 0; i < n; i++)
		largo[i] = i;
	
	for(i = m - 1; i >= 0; i--)
		if( largo[ E[i].second ] == E[i].first + 1 )
			largo[ E[i].second ] = E[i].first;

	maximo[0] = 0;
	int res = 1;
	for(i = 1; i < n; i++){
		maximo[i] = max(maximo[i - 1], largo[i]);
		res = max(res, i - maximo[i] + 1);
	}
	
	cout << res << "\n";
	
	return 0;
}
