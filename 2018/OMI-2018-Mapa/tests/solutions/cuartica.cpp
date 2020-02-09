#include <iostream>
#define MAXN 1505

using namespace std;

long long N, M, k, sum[MAXN][MAXN], zeros[MAXN][MAXN], ans;
char a[MAXN][MAXN];

long long getsum ( int x1, int y1, int x2, int y2 )
{
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

int main()
{
    cin >> N >> M >> k;
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; j++ )
            cin >> a[i][j];
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; j++ )
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + (a[i][j] == '1');

    for ( int x1 = 1; x1 <= N; x1++ )
    {
        for ( int y1 = 1; y1 <= M; y1++ )
        {
            for ( int x2 = x1; x2 <= N; x2++ )
            {
                if ( getsum(x1, y1, x2, y1) > k )
                    break;
                for ( int y2 = y1; y2 <= M; y2++ )
                {
                    if ( getsum(x1, y1, x2, y2) > k )
                        break;
                    if ( getsum(x1, y1, x2, y2) == k )
                        ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
