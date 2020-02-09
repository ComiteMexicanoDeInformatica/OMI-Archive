#include <bits/stdc++.h>
#define fi first
#define se second
#define t first.first
#define d first.second
#define l second.first
#define r second.second
using namespace std;

int n,m,ans;
char xyz;
bool mdo[1501][1501];
bool use[1501][1501];
bool salida[1501][1501];
int dy[]= {1,0,-1,0};
int dx[]= {0,1,0,-1};
set< pair< pair< int,int>, pair<int,int> > > fig;
set< pair< pair< int,int>, pair<int,int> > > :: iterator ini,it;
vector< pair< pair< int,int>, pair<int,int> > > eliminar;
queue< pair<int,int> > cola;
pair< pair< int,int>, pair<int,int> > newVal;

pair< pair< int,int>, pair<int,int> > fn(int f,int c)
{

    int t_=f,d_=f,l_=c,r_=c;
    cola.push({f,c});
    use[f][c]=true;

    pair<int,int> padre,hijo;

    while(!cola.empty())
    {
        padre=cola.front();
        cola.pop();

        for(int k=0; k<4; k++)
        {
            hijo=padre;
            hijo.fi+=dy[k];
            hijo.se+=dx[k];
            if(hijo.fi>=1 && hijo.fi<=n && hijo.se>=1 && hijo.se<=m && !use[hijo.fi][hijo.se] && mdo[hijo.fi][hijo.se])
            {
                use[hijo.fi][hijo.se]=true;
                t_=min(t_,hijo.fi);
                d_=max(d_,hijo.fi);
                l_=min(l_,hijo.se);
                r_=max(r_,hijo.se);
                cola.push(hijo);
            }
        }
    }
    return { {t_,d_},{l_,r_} };

}



bool choca(pair< pair< int,int>, pair<int,int> >  a, set< pair< pair< int,int>, pair<int,int> > > :: iterator b)
{
    if(a.r+1<b->l || a.d+1<b->t || a.l-1>b->r || a.t-1>b->d) return false;
    if(a.d+1==b->t && a.r+1==b->l) return false;
    if(a.t-1==b->d && a.r+1==b->l) return false;
    if(a.t-1==b->d && a.l-1==b->r) return false;
    if(a.d+1==b->t && a.l-1==b->r) return false;
    return true;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) { cin >> xyz; mdo[i][j]=(xyz=='1')?true:false; }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(mdo[i][j] && !use[i][j]) fig.insert(fn(i,j));

    bool change=true;

    while(change)
    {
        change = false;
        eliminar.clear();
        for(ini=fig.begin(); ini!=fig.end(); ini++)
        {
            it=ini;
            it++;
            if(it==fig.end()) break;
            newVal=*ini;

            for(; it!=fig.end(); it++)
            {
                if(choca(newVal,it))
                {
                    change=true;
                    eliminar.push_back( { {it->t,it->d}, {it->l,it->r}} );
                    newVal = { { min(newVal.t,it->t), max(newVal.d,it->d) }, { min(newVal.l,it->l), max(newVal.r,it->r) } };
                }
            }
            for(int i=0; i<eliminar.size(); i++) fig.erase(eliminar[i]);
            if(change) break;
        }
        if(change)
        {
            fig.erase(ini);
            fig.insert(newVal);
        }
    }



    for(it=fig.begin(); it!=fig.end(); it++)
    {
        for(int f=it->t; f<=it->d; f++) for(int c=it->l; c<=it->r; c++) salida[f][c]=true;
    }



    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout << (int)salida[i][j];
        }
        cout << "\n";
    }

    return 0;
}
