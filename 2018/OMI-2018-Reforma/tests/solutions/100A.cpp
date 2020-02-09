#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll n;
ll v[MAX];
ll resp,tam;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		tam=1;
		reverse(v,v+n);
		for(int i=1;i<n;i++){
			if(v[i]<=v[i-1]){
				resp=max(resp,tam);
				tam=1;
			}
			else tam++;
		}
		resp=max(resp,tam);
		cout << resp<<"\n";
	}
