#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll p,q,d,it;
ll x_i,d_i,q_i;
bool memo[MAX];
bool poss[MAX];
vector<ll>edg[MAX];
bool dfs(int nodo){
	if(memo[nodo]){
		return false;
	}
	memo[nodo]=true;
	if(edg[nodo].size()==0){
		return poss[nodo]=true;
	}
	for(int i=0;i<edg[nodo].size();i++){
		poss[nodo]=dfs(edg[nodo][i]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>p>>d>>q;
		for(int i=0;i<d;i++){
			cin>>x_i>>d_i;
			for(int j=0;j<d_i;j++){
				ll x;
				cin>>x;
				edg[x_i].push_back(x);
			}
		}
		for(int i=1;i<=p;i++){
			if(!memo[i]){
				dfs(i);
			}
		}
		while(q--){
			cin>>q_i;
			bool ok=true;
			for(int i=0;i<q_i;i++){
				ll x;
				cin>>x;
				if(!poss[x]){
					ok=false;
				}
			}
			if(!ok)cout << "N\n";
			else cout << "S\n";
		}
	}
