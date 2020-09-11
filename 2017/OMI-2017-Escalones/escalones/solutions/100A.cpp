#include <bits/stdc++.h>
#define lld long long int
using namespace std;
const int MAXN = 1000002;

lld S;
int n, m;
int arr[MAXN];
int bucket[MAXN];

int higher[MAXN]; // el primer mas alto a i
int lower[MAXN]; // el primer mas bajo a i

int f(int a, int b) {
    if(a > b) swap(a, b);
    if(!a) a = b;
    if(lower[b] >= a) return lower[b];
    return 2 * higher[b] - (a + b) < (a + b) - 2 * lower[a] ? higher[b] : lower[a];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= m; i++) {
        int h;
        cin >> h;
        bucket[h] = h;
    }
    fill(higher, higher + MAXN, 1e9);
    fill(lower, lower + MAXN, -1e9);
    for(int i = 1; i < MAXN; i++) {
        lower[i] = lower[i - 1];
        if(bucket[i]) lower[i] = i;
    }
    for(int i = MAXN - 2; i >= 0; i--) {
        higher[i] = higher[i + 1];
        if(bucket[i]) higher[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(arr[i]) continue;
        int j = i;
        for(j = i; j < n && !arr[j + 1]; j++);
        int x = f(arr[i - 1], arr[j + 1]);
        for(int k = i; k <= j; k++) arr[k] = x;
    }
    for(int i = 1; i < n; i++)
        S += abs(arr[i] - arr[i + 1]);
    cout << S << "\n";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
