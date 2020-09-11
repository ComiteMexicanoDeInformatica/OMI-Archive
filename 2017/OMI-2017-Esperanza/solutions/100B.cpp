#include <bits/stdc++.h>
using namespace std;

set < pair < int, int > > coor;

int mov[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};

int minimo(pair < int, int > pos) {
    queue < pair < int, int > > cola;
    cola.push(pos);
    coor.erase(pos);
    int t = 0;
    while(!cola.empty()) {
        for(int i = cola.size(); i; i--) {
            pos = cola.front();
            cola.pop();
            if(!pos.first && !pos.second) return t;
            for(int k = 0; k < 4; k++) {
                pair < int, int > sig = make_pair(pos.first + mov[k][0], pos.second + mov[k][1]);
                if(coor.find(sig) != coor.end()) {
                    coor.erase(sig);
                    cola.push(sig);
                }
            }
        }
        t++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    pair < int, int > pos;
    coor.insert(pos);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if(c == 'L') pos.first--;
        else if(c == 'R') pos.first++;
        else if(c == 'U') pos.second++;
        else pos.second--;
        coor.insert(pos);
    }
    if(minimo(pos) == n) cout << "S\n";
    else cout << "N\n";
    return 0;
}
