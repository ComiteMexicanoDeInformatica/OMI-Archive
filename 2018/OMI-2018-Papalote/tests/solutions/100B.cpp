#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int n,m;
bool ok;
int f[MAX];
int c[MAX];
int mat[MAX][MAX];
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	while(1){
		ok=true;
		for(int i=0;i<n;i++){
			int s=0;
			for(int j=0;j<m;j++){
				if(f[i]^c[j])s-=mat[i][j];
				else s+=mat[i][j];
			}
			if(s<0){
				ok=false;
				f[i]^=1;
			}
		}
		for(int j=0;j<m;j++){
			int s=0;
			for(int i=0;i<n;i++){
				if(f[i]^c[j])s-=mat[i][j];
				else s+=mat[i][j];
			}
			if(s<0){
				ok=false;
				c[j]^=1;
			}
		}
		if(ok)break;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(f[i])sum++;
	}
	cout << sum<<" ";
	for(int i=0;i<n;i++){
		if(f[i])cout << (i+1)<<" ";
	}
	cout << "\n";
	sum=0;
	for(int i=0;i<m;i++){
		if(c[i])sum++;
	}
	cout << sum<<" ";
	for(int i=0;i<m;i++){
		if(c[i])cout << (i+1)<<"\n";
	}
	cout << "\n";
}
