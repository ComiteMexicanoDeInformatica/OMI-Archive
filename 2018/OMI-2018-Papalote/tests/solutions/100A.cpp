#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define debug(x) {cerr << #x << " = " << x << endl;}
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int NMAX = 2000;

int a[NMAX][NMAX], r[NMAX], c[NMAX], mr[NMAX], mc[NMAX];
int n, m;

int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif

    srand(time(NULL));

    scanf("%d%d", &n, &m);
//    n = rand()%100+1;
//    m = rand()%100+1;

    forn(i, n)
        forn(j, m){
            scanf("%d", &a[i][j]);
//            a[i][j] = rand()%100 - 50;
        }

    forn(i, n){
        forn(j, m){
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }

    forn(i, n)
        mr[i] = 1;
    forn(j, m)
        mc[j] = 1;

    #ifdef myproject
    cout << n << " " << m << endl;
    forn(i, n){
        forn(j, m){
            cout << a[i][j]*mr[i]*mc[j] << " ";
        }
        cout << endl;
    }
    #endif


    int iter = 0;

    while(true){

        iter++;

        int rid = -1;
        forn(i, n){
            if(r[i] < 0){
                rid = i;
                break;
            }
        }

        if(rid != -1){
            forn(j, m){
                c[j] -= a[rid][j] * mr[rid] * mc[j];
            }
            mr[rid] *= -1;
            forn(j, m){
                c[j] += a[rid][j] * mr[rid] * mc[j];
            }

            r[rid] *= -1;
            continue;
        }


        int cid = -1;
        forn(j, m){
            if(c[j] < 0){
                cid = j;
                break;
            }
        }

        if(cid != -1){
            forn(i, n){
                r[i] -= a[i][cid] * mc[cid] * mr[i];
            }
            mc[cid] *= -1;
            forn(i, n){
                r[i] += a[i][cid] * mc[cid] * mr[i];
            }
            c[cid] *= -1;
            continue;
        }

        break;
    }

    vector<int> nr(n), nc(m);
    forn(i, n){
        forn(j, m){
            nr[i] += a[i][j] * mr[i] * mc[j];
            nc[j] += a[i][j] * mr[i] * mc[j];
        }
    }

    assert(*min_element(all(nr)) >= 0);
    assert(*max_element(all(nc)) >= 0);

    /*
    cout << endl;
    forn(i, n){
        forn(j, m){
            cout << a[i][j]*mr[i]*mc[j] << " ";
        }
        cout << endl;
    }*/

    vector<int> rr, cc;
    forn(i, n)
        if(mr[i] == -1)
            rr.pb(i);
    forn(j, m)
        if(mc[j] == -1)
            cc.pb(j);

    cout << sz(rr) << " ";
    forn(i, sz(rr))
        cout << rr[i]+1 << " ";
    cout << endl;
    cout << sz(cc) << " ";
    forn(i, sz(cc))
        cout << cc[i]+1 << " ";
    cout << endl;


    #ifdef myproject
    cerr << "Iterations = " << iter << endl;
    #endif

    return 0;

    }
