#include <bits/stdc++.h>
using namespace std;
int n,s;
string v;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
map<pair<int,int>,bool>memo;
bool solve(){
	bool ok=false;
	pair<int,int>d=make_pair(0,0),aux;
	memo[d]=true;
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
		if(!memo[d]){
			memo[d]=true;
			s=0;
			for(int j=0;j<4;j++){
				aux=make_pair(d.first+dx[j],d.second+dy[j]);
				if(memo[aux])s++;
			}
			if(s>1)return false;
		}
		else return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>v;
	if(solve()){
		cout << "S\n";
	}
	else {
		cout << "N\n";
	}
}
