#include <bits/stdc++.h>
#define lld long long int
using namespace std;
const int MAXN = 100002;
const int LOG_N = 52;

int n;
lld arr[MAXN];
int tabla[LOG_N];
int remain[LOG_N];

int potencia(lld x) {
    int c = -1;
    while(x) {
        c++;
        x /= 2;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        lld pot = arr[i] & (-arr[i]);
        if(!(arr[i] - pot)) tabla[potencia(pot)]++;
        else remain[potencia(arr[i]) + 1]++;
    }
    bool solucion = false;
    for(int m = 1; m <= tabla[0]; m++) {
        int cont = m;
        int r = 0;
        for(int j = 0; j < LOG_N; j++) {
            r += remain[j];
            if(tabla[j] < cont) {
                r -= cont - tabla[j];
                r = max(0, r);
                cont = tabla[j];
            } else {
                r += (tabla[j] - cont);
            }
        }
        if(cont >= r) {
            solucion = true;
            cout << m << " ";
        }
    }
    if(!solucion) cout << "-1\n";
    return 0;
}
