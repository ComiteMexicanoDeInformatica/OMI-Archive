#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,t,mdo[4][101][101],DP[101][101],ans;
bool use[101][101];

ll fn(ll fila,ll columna, ll tiempo)
{
    if(tiempo>t) return 0LL;
    if(use[fila][columna]) return DP[fila][columna];

    use[fila][columna]=true;
    ll x=mdo[0][fila][columna],y=0;
    if(columna<m-1) y=fn(fila,columna+1,tiempo+1);
    if(fila<n-1) y=max(y,fn(fila+1,columna,tiempo+1));

    return DP[fila][columna]=x+y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) cin >> mdo[1][i][j];
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) cin >> mdo[2][i][j];
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++) cin >> mdo[0][i][j];

    cout << fn(0,0,1);

    return 0;
}
