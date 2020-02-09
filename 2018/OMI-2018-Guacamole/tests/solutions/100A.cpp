#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,t,mdo[4][101][101],DP[101][101][501],ans;
ll dx[]= {0,1,1,0,-1,-1,-1,0,1};
ll dy[]= {0,0,-1,-1,-1,0,1,1,1};
bool use[101][101][501];

ll fn(ll fila,ll columna, ll tiempo)
{
    if(tiempo>t) return 0LL;

    if(use[fila][columna][tiempo]) return DP[fila][columna][tiempo];

    use[fila][columna][tiempo] = true;

    ll x=0,y;
    bool useY=false;
    if(tiempo>=mdo[1][fila][columna] && (tiempo-mdo[1][fila][columna])%mdo[2][fila][columna]==0) x=mdo[0][fila][columna];

    for(ll k=0; k<9; k++)
    {
        ll f=fila+dy[k];
        ll c=columna+dx[k];
        if(f>=0 && f<n && c>=0 && c<m)
        {
            if(!useY)
            {
                useY=true;
                y=fn(f,c,tiempo+1);
            }
            y=max(y,fn(f,c,tiempo+1));
        }
    }

    return DP[fila][columna][tiempo]=x+y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) cin >> mdo[1][i][j];
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) cin >> mdo[2][i][j];
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) cin >> mdo[0][i][j];

    ans=fn(0,0,1);
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) ans=max(ans,fn(i,j,1));

    cout << ans;

    return 0;
}
