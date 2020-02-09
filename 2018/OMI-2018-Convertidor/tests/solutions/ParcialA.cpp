#include<bits/stdc++.h>
using namespace std;
long long int x;
int t, m;
char p[25];
vector < char > res;
int main()
{
    scanf("%d", &t);
    if(t==0)
    {
        scanf("%lld", &x);
        while(x)
        {
            m=x%26;
            if(m==0)
                m=26;
            x/=26;
            if(m==26)
                x--;
            res.push_back('A'+m-1);
        }
        for(int i=res.size()-1; i>=0; i--)
            printf("%c", res[i]);
    }
    else
    {
        scanf("%s", p);
        printf("-1");
    }
    return 0;
}
