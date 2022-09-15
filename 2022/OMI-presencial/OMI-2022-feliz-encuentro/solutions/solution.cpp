#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, Q;
string s;

int main() {
  cin >> T >> Q;
  cin >> s;

  vector<int> suma_prefijo(T);
  suma_prefijo[0] = 0;
  for (int i = 1; i < T; i++) {
    suma_prefijo[i] = suma_prefijo[i - 1];
    if (s[i] == s[i - 1]) suma_prefijo[i]++;
  }

  while (Q) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << suma_prefijo[b] - suma_prefijo[a] << "\n";
    Q--;
  }

  return 0;
}
