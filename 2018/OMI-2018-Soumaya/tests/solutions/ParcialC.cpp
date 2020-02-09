#include <bits/stdc++.h>
using namespace std;
#define MAX 1502
int n,c;
bool m[MAX][MAX];
char auxi[MAX][MAX];
bool memo[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int max_i,min_i,max_j,min_j;
void dfs(int i,int j){
	if(memo[i][j]||!m[i][j])return;
	max_i=max(max_i,i);
	max_j=max(max_j,j);
	min_i=min(min_i,i);
	min_j=min(min_j,j);
	memo[i][j]=true;
	for(int it=0;it<4;it++){
		if(i+dx[it]<n&&i+dx[it]>=0&&j+dy[it]>=0&&j+dy[it]<c){
			dfs(i+dx[it],j+dy[it]);
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>auxi[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				if(auxi[i][j]=='1')m[i][j]=true;
			}
		}
		for(int tron=0;tron<400;tron++){
			for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				if(m[i][j]&&!memo[i][j]){
					max_i=max_j=-MAX;
					min_i=min_j=MAX;
					dfs(i,j);
					bool ok=false,pass;
					while(!ok){
						pass=false;
						for(int a=min_i;a<=max_i;a++){
							for(int b=min_j;b<=max_j;b++){
								if(m[a][b]&&!memo[a][b]){
									dfs(a,b);
									pass=true;
									break;
								}
								else if(!m[a][b]){
									m[a][b]=true;
									memo[a][b]=true;
								}
							}
							if(pass)break;
						}
						if(!pass)ok=true;
					}
				}
			}
		}
		memset(memo,0,sizeof(memo));
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cout << m[i][j];
			}
			cout << "\n";
		}
	}
