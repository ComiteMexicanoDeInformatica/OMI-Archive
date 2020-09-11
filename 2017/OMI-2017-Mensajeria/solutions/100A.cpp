#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
bool ok;
int n,k;
int v[MAX];
int s,mayor=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>v[i];
		mayor=max(mayor,v[i]);
		if(v[i]>k){
			s+=k;
			ok=true;
		}
		else s+=v[i];
	}
	if(!ok)s+=abs(mayor-k);
	cout << s<<"\n";
}
