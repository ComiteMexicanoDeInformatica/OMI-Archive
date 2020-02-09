#include <cstdlib>
#include<iostream>
#include<numeric>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<fstream>
using namespace std;
#define INF 2000000000 // 2 billion
typedef  long long  ll;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
#define PI 3.14159265
typedef map<string,int> msi;
#define REP(i, a, b) \
for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
int tabla[150][150];
int newcin(int a)
{
    if(cin>>a)
    {
        return a;
    }
    else
    {
        return -1;
    }
}
int operaciones[1000][2];
int main ()
{
    ios_base::sync_with_stdio(0);
    int  x=0,suma_actual,verificador=0;
    int  a,b,c,d,y=1;
    fstream troy;
    troy.open ("data.in",fstream::in);
    troy>>a>>b;
    REP(i,0,a)
    {
        REP(j,0,b)
        {
            troy>>tabla[i][j];
        }
    }
    d=a*b;
    x=newcin(0);
    if(x<=-1)
    {
        cout<<"0.0"<<endl;
        return 0;
    }
    if(a*b<x)
    {
        cout<<"0.0"<<endl;
        return 0;
    }
    REP(i,0,x)
    {
        c=newcin(0);
        if(c<=0 || c>a)
        {
            cout<<"0.0"<<endl;
            return 0;
        }
        operaciones[c][0]++;
    }
     REP(i,0,a+1)
    {
        if(operaciones[i][0]%2==1)
        {
        c=i;
        REP(j,0,b)
        {
            tabla[c-1][j]*=-1;
        }
        }
    }
    y=newcin(0);
    if(y<=-1)
    {
        cout<<"0.0"<<endl;
        return 0;
    }
    //d-=y;
    if(a*b<y)
    {
        cout<<"0.0"<<endl;
        return 0;
    }
    REP(i,0,y)
    {
        c=newcin(0);
        if(c<=0 || c>b)
        {
            cout<<"0.0"<<endl;
            return 0;
        }
        operaciones[c][1]++;
    }
    REP(i,0,b+1)
    {
        if(operaciones[i][1]%2==1)
        {
        c=i;
        REP(j,0,a)
        {
            tabla[j][c-1]*=-1;
        }
        }
    }
    REP(i,0,a)
    {
        suma_actual=0;
        REP(j,0,b)
        {
            suma_actual+=tabla[i][j];
        }
        if(suma_actual<0)
        {
            verificador=1;
        }
    }
    REP(i,0,b)
    {
        suma_actual=0;
        REP(j,0,a)
        {
            suma_actual+=tabla[j][i];
        }
        if(suma_actual<0)
        {
            verificador=1;
        }
    }
    if(cin>>a)
    {
     cout<<"0.0"<<endl;
     return 0;
    }
    if(verificador==0)
    {
        cout<<"1.0"<<endl;
    }
    else
    {
        cout<<"0.0"<<endl;
    }
}
