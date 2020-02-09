/// Solucion O( N^2 ) , para cada posicion determinar la ola continua mas larga
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,A[1000010],ans=-1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i=0; i<n; i++) cin >> A[i];

    for(ll i=0; i<n; i++){
        ll j = i+1;
        while(j<n && A[j]<A[j-1]) j++;
        ans = max(ans,j-i);
    }

    cout << ans;

    return 0;
}
