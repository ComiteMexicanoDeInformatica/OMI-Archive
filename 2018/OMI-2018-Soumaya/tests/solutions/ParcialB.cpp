#include <bits/stdc++.h>
#define fi first
#define se second
#define t first.first
#define d first.second
#define l second.first
#define r second.second
using namespace std;

int n,m,ans;
pair< pair<int,int> , pair<int,int> > lados;
char xyz;
bool mdo[1501][1501],done;
bool use[1501][1501];
int dy[]= {1,0,-1,0};
int dx[]= {0,1,0,-1};
queue< pair<int,int> > cola;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) { cin >> xyz; mdo[i][j]=(xyz=='1')?true:false;}

    done=false;

    while(!done){

        done = true;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) use[i][j]=false;

        for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
                if(mdo[i][j] && !use[i][j]){
                    lados=fn(i,j);
                    for(int f=lados.t; f<=lados.d; f++){
                        for(int c=lados.l; c<=lados.r; c++){
                            done=done&mdo[f][c];
                            mdo[f][c]=true;
                        }
                    }
                }
        }

    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cout << (int)mdo[i][j];
        cout << "\n";
    }
    
    return 0;
}
