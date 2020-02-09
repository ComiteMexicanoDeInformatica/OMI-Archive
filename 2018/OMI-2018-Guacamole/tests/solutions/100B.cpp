#include <bits/stdc++.h>
using namespace std;
#define MAX 512
#define MAXN 112
#define ll long long
ll n,m,t;
ll P[MAXN][MAXN];
ll S[MAXN][MAXN];
ll I[MAXN][MAXN];
ll memo[MAXN][MAXN][MAX];
bool vis[MAXN][MAXN][MAX];
int dx[9]={0,1,1,0,-1,-1,-1,0,1};
int dy[9]={0,0,-1,-1,-1,0,1,1,1};
ll gan(int i,int j,int ti){
	if(S[i][j]>ti)return 0;
	if(S[i][j]==ti)return P[i][j];
	if(((ti-S[i][j])%I[i][j])==0)return P[i][j];
	return 0;
}
ll dp(int i,int j,int p){
	if(p>t)return 0;
	if(vis[i][j][p])return memo[i][j][p];
	ll res,cost=gan(i,j,p);
	vis[i][j][p]=true;
	bool passed=false;
	for(int it=0;it<9;it++){
		if(i+dx[it]>=0&&i+dx[it]<n&&j+dy[it]>=0&&j+dy[it]<m){
			if(!passed){
				passed=true;
				res=dp(i+dx[it],j+dy[it],p+1)+cost;
			}
			else {
				res=max(res,dp(i+dx[it],j+dy[it],p+1)+cost);
			}
		}
	}
	return memo[i][j][p]=res;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m>>t;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>S[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>I[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>P[i][j];
			}
		}
		ll res=dp(0,0,1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!(!i&&!j)){
					res=max(res,dp(i,j,1));
				}
			}
		}
		cout << res << "\n";
	}
