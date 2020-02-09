/// Solucion O( N^3 ) , determinar inicio, fin y ver si el rango cumple
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
        for(ll j=i; j<n; j++){
            bool valido=true;
            for(ll k=i+1; k<=j && valido; k++) if(A[k]>=A[k-1]) valido=false;
            if(valido) ans=max(ans,j-i+1);
        }
    }

    cout << ans;

    return 0;
}
