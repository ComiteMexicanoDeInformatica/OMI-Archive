/*
Imprime:
PM
X
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
typedef long long int lld;

const int MAXN = 15;

int pares = 0;
int bucket[10];
const int maximo[] = {0, 0, 1, 1, 2, MAXN, 1, MAXN, MAXN, MAXN};

int digitos;
int best[10];
int PM;

void print(int pm, int arr[ ]) {
  cout << pm << "\n";
  for (int d = 2; d < 10; ++d) {
    for (int i = 0; i < arr[d]; ++i)
      cout << d;
  }
  cout << "\n";
}

void multiply(vector < int > &v, int d) {
  for (int i = 0; i < v.size(); ++i)
    v[i] *= d;
  for (int i = 0; i < v.size()-1; ++i) {
    v[i+1] += v[i]/10;
    v[i] %= 10;
  }
  int last = v[v.size()-1];
  if (last > 9) {
    v[v.size()-1] = last % 10;
    v.push_back(last / 10);
  }
}

int persistencia() {
  int pm = 0;
  int cnt = 0;
  int b[10];
  for (int d = 0; d < 10; ++d) {
    b[d] = bucket[d];
    cnt += bucket[d];
  }

  while (cnt > 1) {
    pm++;
    if (b[0]) break;

    b[1] = 0;

    b[4] += b[2]/2;
    b[2] &= 1;

    b[9] += b[3]/2;
    b[3] &= 1;

    b[4] += b[6]/2;
    b[9] += b[6]/2;
    b[6] &= 1;

    b[8] += 2*(b[4]/3);
    b[4] %= 3;


    vector < int > num;
    num.push_back(1);
    for (int d = 2; d < 10; ++d) {
      for (int i = 0; i < b[d]; ++i)
        multiply(num, d);
    }
    fill(b, b+10, 0);
    cnt = 0;
    for (int d : num) {
      b[d] ++;
      cnt ++;
    }
  }
  return pm;

}

// tamaño k
void exhaustiva(int d, int k) {
  if (pares && bucket[5]) return;
  if (d > 9 || k >= MAXN) {
    int pm = persistencia();
    if (pm > PM || (pm == PM && k < digitos)) {
      PM = pm;
      digitos = k;
      for (int i = 2; i < 10; ++i)
        best[i] = bucket[i];
    }
  } else {
    // agarra
    if (bucket[d] < maximo[d]) {
      bucket[d]++;
      pares += d & 1;
      exhaustiva(d, k+1);
      bucket[d]--;
      pares -= d & 1;
    }
    // no agarra
    exhaustiva(d+1, k);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  exhaustiva(2, 0);
  print(PM, best);
  return 0;
}
