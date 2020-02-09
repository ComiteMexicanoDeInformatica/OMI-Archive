#include<bits/stdc++.h>
#define MAX 305
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef long long i64;

void fail(const string &msg){
	cerr << msg << endl;
	cout << 0 << endl;
	exit(0);
}

void success(){
	cout << 1 << endl;
	exit(0);
}

void consumeChar(char c){
	char x = cin.get();

	if (x != c)
		fail("unexpected character!");
}

long long readInt( long long lo ,  long long hi ) {
	long long x;
	cin >> x;
    if( x < lo or x > hi )
        fail("out of bounds");
	return x;
}

i64 N, M;
i64 t[MAX][MAX];
i64 a[MAX][MAX];
i64 actx1, actx2, acty1, acty2;
i64 ans, ans2;

i64 solve( i64 tx1 , i64 ty1 , i64 tx2 , i64 ty2 )
{
    i64 tmp = 0;
    i64 cnt = 0;
    for( i64 i = tx1; i <= tx2; i ++ )
        for( i64 j = ty1; j <= ty2; j ++ )
        {
            tmp += a[i][j];
            cnt += t[i][j];
        }
        
    if( cnt && cnt != ( tx2 - tx1 + 1 ) * ( ty2 - ty1 + 1 ) )
        fail("not a chessboard");
    return tmp;
}

int main()
{
    optimiza_io 
    
    
    // Fill Input
    
    ifstream datain("data.in");
    datain >> N >> M;
    for( i64 i = 0; i < N; i ++ )
        for( i64 j = 0; j < M; j ++ )
            datain >> a[i][j];
    
    for( i64 i = 0; i < N; i ++ )
        for( i64 j = 0; j < M; j ++ )
        {
            datain >> t[i][j];
            if( ( i + j ) & 1 )
                t[i][j] = ! t[i][j];
        }
        
    ifstream dataout("data.out");
    dataout >> actx1 >> acty1 >> actx2 >> acty2;
    ans = solve( actx1 , acty1 , actx2 , acty2 );
    actx1 = readInt( 0 , N - 1 );

    acty1 = readInt( 0 , M - 1 );

    actx2 = readInt( actx1 , N - 1 );

    acty2 = readInt( acty1 , M - 1 );
    ans2 = solve( actx1 , acty1 , actx2 , acty2 );
    if( ans != ans2 )
        fail("incorrect answer");
        
    success();
    return 0;
}
