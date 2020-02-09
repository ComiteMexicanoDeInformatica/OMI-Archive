#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for (int i=a;i<b;++i)
const int N=2505;
int n,m,K,a[2][N][N],L[N][8],R[N][8],Lc[N][8],Rc[N][8]; char s[N]; long long ans;
void work(int x1,int x2,int y1,int y2,int d)
{
	if (y2-y1>x2-x1){swap(x1,y1),swap(x2,y2),d^=1;}
	if (x1+1==x2){ans+=a[d][y1][x2]-a[d][y1][x1]==K; return;}
	int mid=x1+x2>>1; work(x1,mid,y1,y2,d),work(mid,x2,y1,y2,d);
	rep(i,y1,y2){
		rep(k,0,K+1) L[i][k]=x1,Lc[i][k]=0,R[i][k]=x2,Rc[i][k]=0;
		rep(j,y1,i+1){
			rep(k,0,K+1){
				Lc[j][k]+=a[d][i][mid]-a[d][i][L[j][k]];
				while (Lc[j][k]>k) Lc[j][k]-=a[d^1][L[j][k]][i+1]-a[d^1][L[j][k]][j],++L[j][k];
				Rc[j][k]+=a[d][i][R[j][k]]-a[d][i][mid];
				while (Rc[j][k]>k) --R[j][k],Rc[j][k]-=a[d^1][R[j][k]][i+1]-a[d^1][R[j][k]][j];
			}
			rep(k,0,K+1) ans+=((k?L[j][k-1]:mid)-L[j][k])*(R[j][K-k]-(K-k?R[j][K-k-1]:mid));
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	rep(i,0,n){scanf("%s",s); rep(j,0,m) a[0][i][j+1]=a[1][j][i+1]=s[j]-48;}
	rep(i,0,n) rep(j,0,m) a[0][i][j+1]+=a[0][i][j];
	rep(j,0,m) rep(i,0,n) a[1][j][i+1]+=a[1][j][i];
	work(0,n,0,m,1); printf("%I64d\n",ans); return 0;
}
