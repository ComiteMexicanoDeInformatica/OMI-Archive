//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 305
#define INF 1e18
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef long long i64;

i64 N, M, ans, ansx1, ansx2, ansy1, ansy2;
i64 a[MAX][MAX];
i64 t[MAX][MAX];
i64 dp[2][MAX];

void solve( i64 in , i64 x1 , i64 x2 )
{
    i64 acty1 = 0;
    i64 tmp = -INF;
    for( i64 i = 1; i <= M; i ++ )
    {
        if( tmp < 0 )
            acty1 = i, tmp = 0;
        tmp += dp[in][i];
        if( tmp > ans )
        {
            ans = tmp;
            ansx1 = x1;
            ansx2 = x2;
            ansy1 = acty1;
            ansy2 = i;
        }
    }
}

int main()
{
    optimiza_io 
    cin >> N >> M;
    for( i64 i = 1; i <= N; i ++ )
        for( i64 j = 1; j <= M; j ++ )
            cin >> a[i][j];
            
    for( i64 i = 1; i <= N; i ++ )
        for( i64 j = 1; j <= M; j ++ )
        {
            cin >> t[i][j];
            if( ( i + j ) & 1 )
                t[i][j] = ! t[i][j]; 
        }
    
    ansx1 = ansy1 = ansx2 = ansy2 = 1;
    ans = a[1][1];
        
    for( i64 i = 1; i <= N; i ++ )
    {
        for( i64 k = 1; k <= M; k ++ )
            dp[0][k] = dp[1][k] = 0;
        for( i64 j = i; j <= N; j ++ )
        {
            for( i64 k = 1; k <= M; k ++ )
            {
                if( t[j][k] )
                    dp[0][k] = -INF, dp[1][k] += a[j][k];
                else
                    dp[1][k] = -INF, dp[0][k] += a[j][k];
            }
            solve( 0 , i , j );
            solve( 1 , i , j );
                
        }
        
    }
    
    cout << ansx1 - 1 << " " << ansy1 - 1 << "\n" << ansx2 - 1 << " " << ansy2 - 1 << "\n";
    // cout << ans << "\n";
    return 0;
}
