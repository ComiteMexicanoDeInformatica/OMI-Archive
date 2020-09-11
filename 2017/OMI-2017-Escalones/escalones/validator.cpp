#include <bits/stdc++.h>
#define lld long long int
using namespace std;
const int MAXN = 1000002;

lld S;
int n, m;
int inicial[MAXN], sol_user[MAXN];
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
    FILE * pfile;
    pfile = fopen("data.in", "r");
    fscanf(pfile, "%d %d", &n, &m);;
    for(int i = 1; i <= n; i++) {
        fscanf(pfile, "%d", &inicial[i]);
        arr[i] = inicial[i];
    }
    for(int i = 1; i <= m; i++) {
        int h;
        fscanf(pfile, "%d", &h);
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

    lld s_user;
    scanf("%lld", &s_user);
    if(S != s_user) {
        printf("0\n");
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sol_user[i]);
        if((inicial[i] && inicial[i] != sol_user[i]) || (!inicial[i] && !bucket[sol_user[i]])) {
            printf("0\n");
            return 0;
        }
    }
    s_user = 0;
    for(int i = 1; i < n; i++)
        s_user += abs(sol_user[i] - sol_user[i + 1]);
    if(S != s_user) {
        printf("0\n");
        return 0;
    }
    printf("1\n");
    return 0;
}
