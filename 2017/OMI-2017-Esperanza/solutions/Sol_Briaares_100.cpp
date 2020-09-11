#include <bits/stdc++.h>
using namespace std;
#define P 9001
#define ll unsigned long long
#define MOD 1000000007
ll h;
int n;
string v;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
set<ll>S;
ll hashi(ll a,ll b){
	ll s=a;
	s*=P;
	s+=b;
	s*=P;
	return s;
}
bool solve(){
	pair<int,int>d=make_pair(n+1,n+1);
	h=hashi(d.first,d.second);
	S.insert(h);
	for(int i=0;i<n;i++){
		if(v[i]=='L'){  //Izquierda
			d.second--;
		}
		else if(v[i]=='R'){  //Derecha
			d.second++;
		}
		else if(v[i]=='U'){   //Arriba
			d.first++;
		}
		else if(v[i]=='D'){  //Abajo
			d.first--;
		}
		h=hashi(d.first,d.second);
		if(S.find(h)!=S.end())return false;
		int s=0;
		for(int j=0;j<4;j++){
			ll h2=hashi((d.first+dx[j]),(d.second+dy[j]));
			if(S.find(h2)!=S.end())s++;
			if(s>1)return false;
		}
		S.insert(h);
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>v;
		if(solve())cout << "S\n";
		else cout << "N\n";
	}
