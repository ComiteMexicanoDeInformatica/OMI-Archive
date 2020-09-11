#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
#define ll long long
int n,m;
int pos;
bool ok;
ll r,x,y;
ll v[MAX];
ll h[MAX];
int bs(int in,int fin){
	if(x>=h[fin])return fin;
	if(y<=h[in])return in;
	int up=0,low=0,mid;
	while(in<=fin){
		mid=(in+fin)/2;
		if(x<=h[mid]&&h[mid]<y)return mid;
		if(h[mid]>=y){
			up=mid;
			fin=mid-1;
		}
		if(h[mid]<x){
			low=mid;
			in=mid+1;
		}
	}
	if(abs(h[low]-x)<abs(h[up]-y)){
		return low;
	}
	else return up;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		r=0;
		for(int i=0;i<n;i++)cin>>v[i];
		for(int i=0;i<m;i++)cin>>h[i];
		sort(h,h+m);
		int p=-1,in=1,pos,idx=0,take=0;
		for(int i=0;i<n;i++){
			if(v[i])ok=true;
			if(v[i]&&in){
				if(p!=-1)r+=abs(v[i]-p);
				p=v[i];
			}
			else if(v[i]&&!in){
				if(p==-1){
					x=v[i],y=v[i];
					pos=bs(0,m-1);
					r+=abs(v[i]-h[pos]);
				}
				else {
					x=p,y=v[i];
					if(x>y)swap(x,y);
					pos=bs(0,m-1);
					r+=abs(v[i]-h[pos]);
					r+=abs(p-h[pos]);
				}
				if(take)while(idx<i)v[idx++]=h[pos];
				take=0;
				in=1;
				p=-1;
				i--;
			}
			else if(!v[i]){
				in=0;
				if(!take){
					idx=i;
					take=1;
				}
			}
		}
		if(!v[n-1]){
			if(p!=-1){
				x=y=p;
				pos=bs(0,m-1);
				r+=abs(p-h[pos]);
				if(take)while(idx<n)v[idx++]=h[pos];
			}
		}
		if(!ok){
			for(int i=0;i<n;i++)v[i]=h[0];
		}
		cout << r<<"\n";
		for(int i=0;i<n;i++)cout << v[i]<<" ";
		cout << "\n";
	}
