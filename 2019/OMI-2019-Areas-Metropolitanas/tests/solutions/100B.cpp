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
i64 nd[MAX][MAX];
i64 tree[2000000];
bool lazy[2000000];
i64 vlazy[2000000];
nodo q[200005];

void updLazy( i64 x ) 
{
    if( ! lazy[x] )
        return;
    lazy[x] = 0;
    lazy[4 * x + 1] = 1; vlazy[4 * x + 1] += vlazy[x];
    lazy[4 * x + 2] = 1; vlazy[4 * x + 2] += vlazy[x];
    lazy[4 * x + 3] = 1; vlazy[4 * x + 3] += vlazy[x];
    lazy[4 * x + 4] = 1; vlazy[4 * x + 4] += vlazy[x];
    tree[x] += vlazy[x];
    vlazy[x] = 0;
}

void upd( i64 x , i64 ax1 , i64 ay1 , i64 ax2 , i64 ay2 , i64 qx1 , i64 qy1 , i64 qx2 , i64 qy2 , i64 v )
{
    updLazy( x );
    if( ax1 > ax2 or ay1 > ay2 )
        return;
    if( ax1 > qx2 or ax2 < qx1 or ay1 > qy2 or ay2 < qy1 )
        return;
        
    if( ax1 >= qx1 && ax2 <= qx2 && ay1 >= qy1 && ay2 <= qy2 )
    {
        // Total overlap
        lazy[x] = 1;
        vlazy[x] += v;
        updLazy( x );
        return;
    }

    i64 mx = ( ax1 + ax2 ) / 2;
    i64 my = ( ay1 + ay2 ) / 2;
        
    upd( 4 * x + 1 , ax1 , ay1 , mx , my , qx1 , qy1 , qx2 , qy2 , v );
    upd( 4 * x + 2 , ax1 , my + 1 , mx , ay2 , qx1 , qy1 , qx2 , qy2 , v );
    upd( 4 * x + 3 , mx + 1 , ay1 , ax2 , my , qx1 , qy1 , qx2 , qy2 , v );
    upd( 4 * x + 4 , mx + 1 , my + 1 , ax2 , ay2 , qx1 , qy1 , qx2 , qy2 , v );
    tree[x] = -INF;
    tree[x] = max( tree[x] , tree[4*x+1] );
    tree[x] = max( tree[x] , tree[4*x+2] );
    tree[x] = max( tree[x] , tree[4*x+3] );
    tree[x] = max( tree[x] , tree[4*x+4] );
    
}

void initTree( i64 x , i64 ax1 , i64 ay1 , i64 ax2 , i64 ay2 )
{
    if( ax1 > ax2 or ay1 > ay2 )
        return;
    
    if( ax1 == ax2 && ay1 == ay2 )
    {
        tree[x] = nd[ax1][ay1];
        return;
    }
    
    i64 mx = ( ax1 + ax2 ) / 2;
    i64 my = ( ay1 + ay2 ) / 2;
    
    initTree( 4 * x + 1 , ax1 , ay1 , mx , my );
    initTree( 4 * x + 2 , ax1 , my + 1 , mx , ay2 );
    initTree( 4 * x + 3 , mx + 1 , ay1 , ax2 , my );
    initTree( 4 * x + 4 , mx + 1 , my + 1 , ax2 , ay2 );
    tree[x] = -INF;
    tree[x] = max( tree[x] , tree[4*x+1] );
    tree[x] = max( tree[x] , tree[4*x+2] );
    tree[x] = max( tree[x] , tree[4*x+3] );
    tree[x] = max( tree[x] , tree[4*x+4] );
}

i64 suma( i64 ax1 , i64 ay1 , i64 ax2 , i64 ay2 )
{
    return sum[ax2][ay2] - sum[ax2][ay1 - 1] - sum[ax1 - 1][ay2] + sum[ax1 - 1][ay1 - 1];
}
int main()
{
    optimiza_io 
    cin >> N >> M >> K >> LIM;
    for( i64 i = 1; i <= N; i ++ )
        for( i64 j = 1; j <= M; j ++ )
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    for( i64 i = 1; i + K - 1 <= N; i ++ )
        for( i64 j = 1; j + K - 1 <= M; j ++ )
            nd[i][j] = suma( i , j , i + K - 1 , j + K - 1 );
    
    N = N - K + 1;
    M = M - K + 1;
    initTree( 0 , 1 , 1 , N , M );
    
    cin >> Q;
    for( i64 i = 1; i <= Q; i ++ )
        cin >> q[i].i >> q[i].j >> q[i].x >> q[i].t; 
    
    if( tree[0] > LIM )
    {
        cout << "0\n";
        exit(0);
    }
    
    sort( q + 1 , q + Q + 1 , cmp );
    for( i64 i = 1; i <= Q; i ++ )
    {
        upd( 0 , 1 , 1 , N , M , max( 1LL , q[i].i - K + 1 ) , max( 1LL , q[i].j - K + 1 ) , min( N , q[i].i ) , min( M , q[i].j ) , q[i].x );
        if( q[i].t == q[i + 1].t )
            continue;
        if( tree[0] > LIM )
        {
            cout << q[i].t << "\n";
            exit(0);
        }
    }
    cout << "-1\n";
    return 0;
}
