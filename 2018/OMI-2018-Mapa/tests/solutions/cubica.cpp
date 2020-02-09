#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,m,k,mdo[510][510],ans,sum;
char c;
unordered_map< int,int > cub;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> c;
            mdo[i][j]=c-'0';
            mdo[i][j]+=mdo[i-1][j]+mdo[i][j-1]-mdo[i-1][j-1];
        }
    }

    for(int l=1; l<=m; l++)
    {
        for(int r=l; r<=m; r++)
        {
            cub.clear();
            cub[0]=1;
            for(int t=1; t<=n; t++)
            {
                sum=mdo[t][r]-mdo[t][l-1];
                ans+=cub[k-sum];
                sum=mdo[t][l-1]-mdo[t][r];
                cub[sum]++;
            }
        }
    }

    cout << ans;

    return 0;
}
