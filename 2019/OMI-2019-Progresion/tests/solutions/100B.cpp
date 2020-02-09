//#define _GLIBCXX_USE_C99 1
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
#include<bits/stdc++.h>
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
///Estructura y como hacer que sirva con map,set,etc.
struct cosa
{
    int words;
    int next[26];
};
struct cost
{
    long long int  a,b;
};

struct q
{
    int a;
    string b;
};
//int car[1000000];

//int arr1[10]= {-1,-1,-1,0,0,1,1,1};
//int arr2[10]= {-1,0,1,-1,1,-1,0,1};
int aa1[10]= {-1,1,0,0};
int aa2[10]= {0,0,-1,1};
//char cosa[10]= {'a','b','c','d','e'};
///LEER CON ESPACIOS SEA BUFFER CHAR[1000] scanf ("%[^\n]%*c", buffer);
///char k ='"';
int alfa,beta;
//int act;
char buffer[10];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool operator <(const cost &a,const cost &b)
{
    if(a.a==b.a)
    {
        return a.b > b.b;
    }
    return a.a > b.a;
}
///Apartir de aqui normalmente inician mis codigos , si es que me estas espiando <3
///From here normally my code starts, thats if you are stalking me <3


string k;
string vac,resulta;
long long int troy[800000];
long long int tray[800000];
int main ()
{
//    memset(tablero,-1,sizeof(tablero));
    ios_base::sync_with_stdio(0);
    //freopen ("test.in","r",stdin);
    //freopen ("20.in","w",stdout);
    long long int  z,mal=INF,s=INF,a1=0,b1=0,c1,x1,y1,t=-INF,res=0,e=-1,f;
    long long int  a,b,c,d,x;
    char prof,prof2;
    cin>>a;
    REP(i,0,a)
    {
        cin>>troy[i];
    }
    if(a==1)
    {
        cout<<0;
        return 0;
    }
    if(a==2)
    {
        cout<<0;
        return 0;
    }
    REP(j,0,3)
    {
    res=0;
    e=0;
    f=j-1;
    x=troy[0]-troy[1]-f;
    t=0;
    if(f!=0)
    {
        t++;
    }
    REP(i,1,a-1)
    {
        e=0;
        if(troy[i]+f-troy[i+1]-e!=x)
        {
            e=1;
            if(troy[i]+f-troy[i+1]-e!=x)
            {
                e=-1;
                if(troy[i]+f-troy[i+1]-e!=x)
                {
                   // cout<<troy[i]+f<<" "<<troy[i+1]+e<<endl;
                    res=-1;
                    break;
                }
            }
        }
        f=e;
        if(f!=0)
        {
            t++;
        }
    }
    if(res==0)
    {
        s=min(s,t);
    }
    }
    troy[0]++;
    REP(j,0,3)
    {
    res=0;
    e=0;
    f=j-1;
    x=troy[0]-troy[1]-f;
    t=1;
    if(f!=0)
    {
        t++;
    }
    REP(i,1,a-1)
    {
        e=0;
        if(troy[i]+f-troy[i+1]-e!=x)
        {
            e=1;
            if(troy[i]+f-troy[i+1]-e!=x)
            {
                e=-1;
                if(troy[i]+f-troy[i+1]-e!=x)
                {
                   // cout<<troy[i]+f<<" "<<troy[i+1]+e<<endl;
                    res=-1;
                    break;
                }
            }
        }
        f=e;
        if(f!=0)
        {
            t++;
        }
    }
    if(res==0)
    {
         s=min(s,t);
    }
    }
    troy[0]-=2;
    REP(j,0,3)
    {
    res=0;
    e=0;
    f=j-1;
    x=troy[0]-troy[1]-f;
    t=1;
    if(f!=0)
    {
        t++;
    }
    REP(i,1,a-1)
    {
        e=0;
        if(troy[i]+f-troy[i+1]-e!=x)
        {
            e=1;
            if(troy[i]+f-troy[i+1]-e!=x)
            {
                e=-1;
                if(troy[i]+f-troy[i+1]-e!=x)
                {
                   // cout<<troy[i]+f<<" "<<troy[i+1]+e<<endl;
                    res=-1;
                    break;
                }
            }
        }
        f=e;
        if(f!=0)
        {
            t++;
        }
    }
    if(res==0)
    {
         s=min(s,t);
    }
    }
    if(s!=INF)
    {
        cout<<s;
    }
    else
    cout<<-1;

}
