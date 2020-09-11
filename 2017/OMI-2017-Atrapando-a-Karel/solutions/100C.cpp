#include <bits/stdc++.h>
#include "atrapando.h"
using namespace std;
const int MAXN = 502;
const int E = 1, N = 2, W = 3, S = 4;
// Main
//	int ponMuro(int f, int c, int d)

int f, c;
int muro[MAXN][MAXN];

bool pared(int i, int j, int d) {
    return muro[i][j] & (1 << d);
}

void ponPared(int i, int j ,int d) {
    int mov = ponMuro(i, j, d);
    if(mov == N) f--;
    else if(mov == S) f++;
    else if(mov == E) c++;
    else c--;
    muro[i][j] |= (1 << d);
    if(d == N) muro[i - 1][j] |= (1 << S);
    else if(d == S) muro[i + 1][j] |= (1 << N);
    else if(d == E) muro[i][j + 1] |= (1 << W);
    else muro[i][j - 1] |= (1 << E);
}

void checkBorder(const int &i1, const int &j1, const int &i2, const int &j2) {
    if(f == i1 && !pared(f, c, N)) ponPared(f, c, N);
    else if(f == i2 && !pared(f, c, S)) ponPared(f, c, S);
    else if(c == j1 && !pared(f, c, W)) ponPared(f, c, W);
    else if(c == j2 && !pared(f, c, E)) ponPared(f, c, E);
    else return;
    checkBorder(i1, j1, i2, j2);
}

void encierra(int i1, int j1, int i2, int j2) {
    for(int a = j1; a <= j2; a++) {
        checkBorder(i1, j1, i2, j2);
        if(!pared(i1, a, N)) ponPared(i1, a, N);
        checkBorder(i1, j1, i2, j2);
        if(!pared(i2, a, S)) ponPared(i2, a, S);
    }
    for(int a = i1; a <= i2; a++) {
        checkBorder(i1, j1, i2, j2);
        if(!pared(a, j1, W)) ponPared(a, j1, W);
        checkBorder(i1, j1, i2, j2);
        if(!pared(a, j2, E)) ponPared(a, j2, E);
    }
    if(i2 == i1 && j2 == j1) return;
    if(i2 - i1 >= j2 - j1) {
        if(i2 - f < f - i1) encierra(f, j1, i2, j2);
        else encierra(i1, j1, f, j2);
    } else {
        if(j2 - c < c - j1) encierra(i1, c, i2, j2);
        else encierra(i1, j1, i2, c);
    }
}

void atrapando(int n) {
    f = c = (n + 1) / 2;
    int i1 = f - 4, j1 = c - 4, i2 = f + 4, j2 = c + 4;
    ponPared(i1, j1, N);
    ponPared(i1, j2, N);
    ponPared(i2, j1, S);
    ponPared(i2, j2, S);
    encierra(i1, j1, i2, j2);
}
