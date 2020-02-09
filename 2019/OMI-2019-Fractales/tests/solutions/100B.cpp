#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair < int, int > pii;

const int MAXN = 15000002;

int pot3[20];
int log3[MAXN];
lld cuadro[20];

void init() {
  int i, j;
  pot3[0] = 1;
  cuadro[0] = 1;
  for (i = 1; i <= 16; ++i) {
   pot3[i] = pot3[i-1] * 3;
  	cuadro[i] = cuadro[i-1] * 7ll;
  }
  j = 1;
  for (i = 1; i < MAXN; ++i) {
    while (pot3[j] < i) ++j;
    log3[i] =  j;
  }
}

map < pii, lld > memo;

/*
1 2 3
4 5 6
7 8 9
*/

int cuadrante(int x, int y) {
	int lv = max(log3[x], log3[y]);
	int i = 0, j = 0;
	if (x > pot3[lv-1]) i++;
	if (x > 2*pot3[lv-1]) i++;
	if (y > pot3[lv-1]) j++;
	if (y > 2*pot3[lv-1]) j++;
	return i*3 + j + 1;
}

lld cnt(int x, int y) {
  if (x > y) swap(x, y);
  if (x == 1 && y == 1) return 1;
  int lv = max(log3[x], log3[y]);
  if (x == pot3[lv] && y == pot3[lv]) return cuadro[lv];
  if (!memo.count({x,y})) {
  	int c = cuadrante(x, y);

  	// El cuadrante pasado esto no puede ser 1
  	lld ans = 0;
  	if (c == 2)
  		ans = cnt(x, y-pot3[lv-1]) + cnt(x, pot3[lv-1]);
  	else if (c == 3)
  		ans = cnt(x, y-2*pot3[lv-1]) + 2*cnt(x, pot3[lv-1]);
  	else if (c == 5)
  		ans = cuadro[lv-1] + cnt(x-pot3[lv-1], pot3[lv-1]) + cnt(pot3[lv-1], y-pot3[lv-1]);
  	else if (c == 6)
  		ans = 2*cuadro[lv-1] + cnt(x-pot3[lv-1], y-2*pot3[lv-1]) + cnt(x-pot3[lv-1], pot3[lv-1]) + cnt(pot3[lv-1], y-2*pot3[lv-1]);
  	else if (c == 9)
  		ans = 3*cuadro[lv-1] + 2*cnt(x-2*pot3[lv-1], pot3[lv-1]) + 2*cnt(pot3[lv-1], y-2*pot3[lv-1]);

  	return memo[{x, y}] = ans;
  }
  return memo[{x, y}];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	int x, y;
	cin >> x >> y;
	cout << cnt(x, y) << "\n";
  	return 0;
}
