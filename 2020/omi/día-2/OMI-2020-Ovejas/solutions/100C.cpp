#include <iostream>

using namespace std;

/// Solución alternativa a Ovejas
/// Créditos: Luis Martín Jim. Rdz.

const int MAX = 1000;

/// oveja[i][j] es el número de ovejas en la posición (i,j)
int oveja[MAX+1][MAX+1];

/// Sumas acumuladas
int ac[MAX+1][MAX+1];

void calculaSumas() {
    for (int i=0; i<=MAX; i++) {
        for (int j=0; j<=MAX; j++) {
            ac[i][j] = oveja[i][j];
            if (i-1 >= 0) {
                ac[i][j] += ac[i-1][j];
            }
            if (j-1 >= 0) {
                ac[i][j] += ac[i][j-1];
            }
            if (i-1 >= 0 && j-1 >= 0) {
                ac[i][j] -= ac[i-1][j-1];
            }
        }
    }
}

/// Regresa la suma acumulada de (x1,y1) a (x2,y2)
int sum(int x1, int y1, int x2, int y2) {
    int ans = ac[x2][y2];
    if (x1-1 >= 0) {
        ans -= ac[x1-1][y2];
    }
    if (y1-1 >= 0) {
        ans -= ac[x2][y1-1];
    }
    if (x1-1 >= 0 && y1-1 >= 0) {
        ans += ac[x1-1][y1-1];
    }
    return ans;
}

/// Número de ovejas encontradas en el cuadrado con radio d y centro en (x,y)
int found(int x, int y, int d) {
    return sum(max(x-d,0), max(y-d,0), min(x+d,MAX), min(y+d,MAX));
}

int dist(int x, int y) {
    int lo = 0;
    int hi = MAX;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (found(x,y, mid)) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    return lo;
}

/// Es suficiente para obtener 100 pts, sin necesidad de la búsq. binaria
int distIterativa(int x, int y) {
    for (int i=0; i<=MAX; i++) {
        if (found(x,y,i)) {
            return i;
        }
    }
}

int N,Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for (int i=0; i<N; i++) {
        int x,y;
        cin>>x>>y;
        oveja[x][y]++;
    }
    calculaSumas();
    for (int i=0; i<Q; i++) {
        int x,y;
        cin>>x>>y;
        cout<<dist(x,y)<<'\n';
    }
}
