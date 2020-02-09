#include <bits/stdc++.h>
using namespace std;

struct rectangle {
    int x1, y1;
    int x2, y2;

    rectangle(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}

    void expande(int x1, int y1, int x2, int y2) {
        this -> x1 = min(x1, this->x1);
        this -> y1 = min(y1, this->y1);
        this -> x2 = max(x2, this->x2);
        this -> y2 = max(y2, this->y2);
    }
    void expande(int i, int j) { expande(i, j, i, j); }
    void expande(const rectangle &r) { expande(r.x1, r.y1, r.x2, r.y2); }

    bool colisiona(rectangle r) {
        return !(r.y1 > y2 + 1 || r.y2 < y1 - 1
                 || r.x1 > x2 + 1 || r.x2 < x1 - 1
                 || (r.x2 == x1-1 && r.y1 == y2+1)
                 || (r.x1 == x2+1 && r.y1 == y2+1)
                 || (r.x2 == x1-1 && r.y2 == y1-1)
                 || (r.x1 == x2+1 && r.y2 == y1-1));
    }
};

int n, m;
bool **A, **vis;
vector < rectangle > arr;
const int movs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void dfs(int i, int j, rectangle &r) {
    stack < pair < int, int > > pila;
    pila.push({i, j});
    while(!pila.empty()) {
        tie(i, j) = pila.top();
        pila.pop();
        if(i < 0 || j < 0 || i >= n || j >= m) continue;
        if(vis[i][j] || !A[i][j]) continue;
        vis[i][j] = true;
        r.expande(i, j);
        for(int k = 0; k < 4; k++)
            pila.push({i + movs[k][0], j + movs[k][1]});
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    A = new bool*[n];
    vis = new bool*[n];

    for(int i = 0; i < n; ++i) {
        A[i] = new bool[m];
        vis[i] = new bool[m];
        for(int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            A[i][j] = (c == '1');
            vis[i][j] = false;
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(A[i][j] && !vis[i][j]) {
                rectangle r(i, j, i, j);
                dfs(i, j, r);
                arr.push_back(r);
            }

    for(int k = arr.size(); k; --k)
        for(int i = 0; i < arr.size(); ++i)
            for(int j = i + 1; j < arr.size(); ++j)
                if(arr[i].colisiona(arr[j])) {
                    arr[i].expande(arr[j]);
                    swap(arr[j], arr[arr.size()-1]);
                    arr.pop_back();
                }

    for(auto r : arr)
        for(int i = r.x1; i <= r.x2; ++i)
            for(int j = r.y1; j <= r.y2; ++j)
                A[i][j] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cout << A[i][j];
        cout << "\n";
    }
    return 0;
}
