#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll r;
ll men=(1<<30);
bool ok;
int n,m;
ll v[MAX];
ll h[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<m;i++){
			cin>>h[i];
			men=min(men,h[i]);
		}
		int p=-1;
		for(int i=0;i<n;i++){
			if(!v[i]){
				if(p==-1){
					p=i;
				}
			}
			else {
				ok=true;
				int idx,mi=(1<<30);
				for(int j=0;j<m;j++){
					if(p){
						if(abs(h[j]-v[i])+abs(h[j]-v[p-1])<mi){
							mi=abs(h[j]-v[i])+abs(h[j]-v[p-1]);
							idx=j;
						}
					}
					else {
						if(abs(h[j]-v[i])<mi){
							mi=abs(h[j]-v[i]);
							idx=j;
						}
					}
				}
				v[p]=h[idx];
				p=-1;
			}
		}
		if(!ok){
			cout << "0\n";
			for(int i=0;i<n;i++)cout << men<<" ";
		}
		else {
			if(!v[n-1]){
				int idx,mi=(1<<30);
				for(int i=0;i<m;i++){
					if(abs(h[i]-v[p-1])<mi){
						mi=abs(h[i]-v[p-1]);
						idx=i;
					}
				}
				v[p]=h[idx];
			}
			int idx=-1;
			for(int i=0;i<n;i++){
				if(v[i])idx=i;
				else v[i]=v[idx];
			}
			idx=0;
			for(int i=1;i<n;i++){
				idx+=(abs(v[i]-v[i-1]));
			}
			cout << idx<<"\n";
			for(int i=0;i<n;i++){
				cout << v[i]<<" ";
			}
		}
	}
