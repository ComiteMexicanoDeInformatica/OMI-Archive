// Solucion: Julian Rodríguez 
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;

ll N,M,K,H,V,aux,ans;

int main()
{
    scanf("%lld %lld %lld %lld %lld",&N,&M,&K,&H,&V);

    if(H>V)
    {
        swap(H,V);
        swap(N,M);
    }

    aux=K/((H*(M-1LL))+V);

    if(aux>=N)
    {
        printf("%lld",N*M);
        return 0;
    }
    ans=aux*M;
    K-=aux*((H*(M-1LL))+V);
    aux=K/H;
    if(aux>=(M-1LL))
        ans+=M;
    else
        ans+=aux+1LL;
    printf("%lld",ans);
    return 0;
}
