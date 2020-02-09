#include <bits/stdc++.h>
using namespace std;
#define MAX 100002

long long p,q,d,it;
long long x_i,d_i,q_i;
long long memo[MAX];
long long poss[MAX];

vector<long long>edg[MAX];

long long dfs(int nodo)
{
	if (!edg[nodo].size()) return poss[nodo]=1;
	if (memo[nodo]) return poss[nodo];
	long long sum=0;
	memo[nodo]=true;
	for (int i=0;i<edg[nodo].size();i++) {
		sum+=dfs(edg[nodo][i]);
	}
	if (sum==edg[nodo].size()) return poss[nodo]=1;
	return 0;
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>p>>d>>q;
	for (int i=0;i<d;i++) {
		cin>>x_i>>d_i;
		for (int j=0;j<d_i;j++) {
			long long x;
			cin>>x;
			edg[x_i].push_back(x);
		}
	}
	for (int i=1;i<=p;i++) {
		if (!memo[i]) {
			dfs(i);
		}
	}
	while(q--) {
		cin>>q_i;
		bool ok=true;
		for (int i=0;i<q_i;i++) {
			long long x;
			cin>>x;
			if (!poss[x]) {
				ok=false;
			}
		}
		if (!ok)cout << "N\n";
		else cout << "S\n";
	}
}
