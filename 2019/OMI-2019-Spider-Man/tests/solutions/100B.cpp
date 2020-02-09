//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved. With publishing of Alberto Ramirez Valadez.
#include<bits/stdc++.h>
#define MAX 300005
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef unsigned long long i64;

i64 N, M, K, H, V;

int main()
{
    optimiza_io 
    cin >> N >> M >> K >> H >> V;
    
    i64 costH = ( M - 1 ) * H + V;
     i64 costV = ( N - 1 ) * V + H;
    if( costH * N - V <= K or costV * M - V <= K )
        cout << N * M << "\n";
    else if( H < V )
    {
        i64 rows = K / costH;
        K -= rows * costH;
        cout << M * rows + min( K / H , M - 1 ) + 1  << "\n";
    }
    else
    {
        i64 cols = K / costV;
        K -= cols * costV;
        cout << N * cols + min( K / V , N - 1 ) + 1 << "\n";
    }
    return 0;
}
