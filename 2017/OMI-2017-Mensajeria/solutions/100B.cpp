#include <bits/stdc++.h>
using namespace std;

int n, k;
int S;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int mayor = -(1 << 30);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mayor = max(mayor, x);
        S += x < k ? x : k;
    }
    if(mayor < k) S += k - mayor;
    cout << S << "\n";
    return 0;
}
