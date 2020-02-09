#include<bits/stdc++.h>
using namespace std;
long long int x, pot=1;
int t, m;
char p[25];
int main()
{
    scanf("%d", &t);
    if(t==0)
    {
        scanf("%lld", &x);
        printf("1");
    }
    else
    {
        scanf("%s", p);
        for(int i=strlen(p)-1; i>=0; i--)
            x+=pot*(p[i]-'A'+1), pot*=26;
        printf("%lld", x);
    }
    return 0;
}
