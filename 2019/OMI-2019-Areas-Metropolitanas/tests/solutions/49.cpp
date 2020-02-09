//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 255
#define INF 1e18
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef long long i64;

struct nodo
{
    i64 i, j, x, t;
};

bool cmp( nodo a , nodo b )
{
    return a.t < b.t;
}

i64 N, M, K, LIM, Q;
i64 a[MAX][MAX];
i64 sum[MAX][MAX];
nodo q[200005];


i64 suma( i64 ax1 , i64 ay1 , i64 ax2 , i64 ay2 )
{
    return sum[ax2][ay2] - sum[ax2][ay1 - 1] - sum[ax1 - 1][ay2] + sum[ax1 - 1][ay1 - 1];
}

bool solve( )
{    
    for( i64 i = 1; i <= N; i ++ )
        for( i64 j = 1; j <= M; j ++ )
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    
    for( i64 i = 1; i + K - 1 <= N; i ++ )
        for( i64 j = 1; j + K - 1 <= M; j ++ )
            if( suma( i , j , i + K - 1 , j + K - 1 ) > LIM )
                return 1;

    return 0;
}

i64 bruteSuma( i64 x , i64 y )
{
    i64 tmp = 0;
    if( x + K - 1 > N or y + K - 1 > M )
        return 0;
    for( i64 i = x; i <= x + K - 1; i ++ )
        for( i64 j = y; j <= y + K - 1; j ++ )
            tmp += a[i][j];
    return tmp;
}

bool solvesmall( i64 x , i64 y )
{
    for( i64 i = max( x - K + 1 , 1LL ); i <= x; i ++ )
        for( i64 j = max( y - K + 1 , 1LL ); j <= y; j ++ )
            if( bruteSuma( i , j ) > LIM )
                return 1;
    
    return 0;
}

int main()
{
    optimiza_io 
    cin >> N >> M >> K >> LIM;
    for( i64 i = 1; i <= N; i ++ )
        for( i64 j = 1; j <= M; j ++ )
            cin >> a[i][j];
            
    if( solve() )
    {
        cout << "0\n";
        exit(0);
    }
    
    cin >> Q;
    for( i64 i = 1; i <= Q; i ++ )
        cin >> q[i].i >> q[i].j >> q[i].x >> q[i].t; 
        
    sort( q + 1 , q + Q + 1 , cmp );
    for( i64 i = 1; i <= Q; i ++ )
    {
        a[q[i].i][q[i].j] += q[i].x;
        if( q[i].t != q[i + 1].t && K <= 3 && solvesmall( q[i].i , q[i].j ) )
        {
            cout << q[i].t << "\n";
            exit(0);
        }
        if( K > 3 && q[i].t != q[i + 1].t && solve() )
        {
            cout << q[i].t << "\n";
            exit(0);
        }
            
    }
    

    cout << "-1\n";
    return 0;
}

