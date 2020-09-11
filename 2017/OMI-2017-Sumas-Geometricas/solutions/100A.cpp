#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
#define MAXN 1e16
int n;
int cota;
ll v[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==1)++cota;
    }
    int r=cota+1,l=0;
    while(l+1<r){
        int mid=(l+r)/2;
        int aux=mid;
        int pos=1;
        queue<ll>sobras;
        for(ll num=1;num<=MAXN;num*=2){
            int res=0;
            while(pos<=n&&v[pos]<=num){
                if(v[pos]==num&&res<aux)res++;
                else sobras.push(v[pos]);
                pos++;
            }
            if(res<aux){
                int fin=aux-res;
                for(int i=1;i<=fin;i++){
                	if(!sobras.empty()&&num>=sobras.front())sobras.pop();
				}
                aux=res;
            }
        }
        if (sobras.empty())r=mid;
        else l=mid;
    }
    if(r==cota+1) cout<<"-1\n";
    else{
        for(int i=r;i<=cota;i++){
        	cout<<i<<" ";
		}
        cout << "\n";
    }
}
