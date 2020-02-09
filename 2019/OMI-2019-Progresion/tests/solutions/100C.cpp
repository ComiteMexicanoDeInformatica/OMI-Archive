//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define INF 1e9
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

i64 N, ans;
i64 a[MAX];

i64 solve( i64 f , i64 s )
{
    i64 tmp = 0;
    i64 diff = s - f;
    for( i64 i = 0; i < N; i ++ )
    {
        i64 aux = abs( a[i] - ( f + diff * i ) );
        if( aux > 1 )
            return INF;
        tmp += aux;
    }
    return tmp;
}

int main()
{
    optimiza_io
    cin >> N;
    for( i64 i = 0; i < N; i ++ )
        cin >> a[i];
    
    if( N <= 2 )
    {
        cout << "0\n";
        return 0;
    }
    
    // Intenta todas las posibilidades
    ans = solve( a[0] , a[1] );
    for( i64 i = -1; i <= 1; i ++ )
        for( i64 j = -1; j <= 1; j ++ )
            ans = min( ans , solve( a[0] + i , a[1] + j ) );
    
    if( ans == INF )
        ans = -1;
    cout << ans;
    return 0;
}

