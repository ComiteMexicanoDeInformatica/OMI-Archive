#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define FOR(_i,_l,_r) for(int _i=_l;_i<=_r;_i++)
const int maxn=2533;
char str[maxn];
int n,m,K;
int s[2][maxn][maxn];
int U[7],D[7];

long long ans;

int sum(const int &xl,const int &xr,const int &yl,const int &yr,const int &d)
{return s[d][xr][yr]-s[d][xl-1][yr]-s[d][xr][yl-1]+s[d][xl-1][yl-1];}

void init()
{
	scanf("%d%d%d\n",&n,&m,&K);
	FOR(i,1,n)
	{
		scanf("%s",str+1);
		FOR(j,1,m)
			s[0][i][j]+=s[0][i-1][j]+s[0][i][j-1]-s[0][i-1][j-1]+(str[j]=='1'),
			s[1][j][i]+=s[1][j-1][i]+s[1][j][i-1]-s[1][j-1][i-1]+(str[j]=='1');
	}
}

void work(int xl,int xr,int yl,int yr,int d)
{
	if(xr-xl>yr-yl)
		swap(xl,yl),swap(xr,yr),d^=1;
	if(yl==yr)
	{
		ans+=sum(xl,xr,yl,yr,d)==K;
		return;
	}
	int mid=yl+yr>>1;
	FOR(l,xl,xr)
	{
		FOR(t,0,K)D[t]=yl,U[t]=yr;
		FOR(r,l,xr)
		{
			FOR(t,0,K)
			{
				for(;sum(l,r,mid+1,U[t],d)>t;U[t]--);
				for(;sum(l,r,D[t],mid,d)>t;D[t]++);
			}
			FOR(t,0,K)
				ans+=(U[t]-(t?U[t-1]:mid))*((t<K?D[K-t-1]:mid+1)-D[K-t]);
		}
	}
	work(xl,xr,yl,mid,d);
	work(xl,xr,mid+1,yr,d);
}

int main()
{
	init();
	work(1,n,1,m,0);
	printf("%I64d\n",ans);
	return 0;
}
