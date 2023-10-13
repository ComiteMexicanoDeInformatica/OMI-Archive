#include <iostream>
#include <queue>

void optimize() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
}

// Definiciones tecnicas.

int n, m, f, p;
long long b, c;

const int MAXN = 1000002;

long long F[MAXN];

struct offi {
  int pos, cnt;
};

offi P[MAXN];
long long acum_prog[MAXN];

struct rango {
  int l, r;
  int pos;
  int posL, posR;
  long long mx_gan;

  // La ganancia maxima de abrir exactamente una franquicia en el rango.
  void Calc() {
    int L = l;
    int R = l;
    int new_pos = l;
    if (l > r) {
      mx_gan = 0;
      return;
    }
    long long mx = mx_gan = 0;
    while (new_pos <= r) {
      while (L > l && l + (new_pos - l + 1) / 2 <= L) {
        L--;
      }
      while (R < r && new_pos + (new_pos - l + 1) / 2 >= R) {
        R++;
      }
      mx = std::max(mx, acum_prog[R] - acum_prog[L - 1]);
      if (mx > mx_gan) {
        mx_gan = mx;
        pos = new_pos;
        posL = L;
        posR = R;
      }
      new_pos++;
    }
  }
  rango(int L, int R) {
    if (L > R) {
      l = r = mx_gan = pos = -1;
    } else {
      l = L;
      r = R;
      Calc();
    }
  }
};

struct comp {
  bool operator()(rango A, rango B) { return A.mx_gan < B.mx_gan; }
};

std::priority_queue<rango, std::vector<rango>, comp> pq;

// Comienzo del programa.
int main() {
  optimize();
  // Tamaños y cantidades se definen y se leen como entrada.
  std::cin >> n >> m;
  std::cin >> f >> p;
  std::cin >> b >> c;
  // Franquicias extra para evitar edge-cases.
  F[0] = 0;
  F[f + 1] = m;
  // Las franquicias se leen como entrada.
  for (int i = 1; i <= f; i++) {
    std::cin >> F[i];
  }
  // Las posiciones y el numero de programadores se leen como entrada.
  for (int i = 0; i < p; i++) {
    std::cin >> P[i].pos >> P[i].cnt;
  }
  // El numero de programadores en cada edificio de izquierda a derecha se
  // acumulan.
  for (int i = 0; i < p; i++) {
    acum_prog[P[i].pos] = P[i].cnt * b;
  }
  for (int i = 1; i <= f; i++) {
    acum_prog[F[i]] = 0;
  }
  for (int i = 1; i < MAXN; i++) {
    acum_prog[i] += acum_prog[i - 1];
  }
  // Segmentos de Edificios sin franquicias se forman y se insertan a un
  // monticulo a modo de inicializacion.
  for (int i = 1; i <= f + 1; i++) {
    // Un segmento se forma.
    int l, r;
    l = F[i - 1];
    r = F[i];
    // Un rango se forma sin edificios por lo tanto se descarta.
    if (l >= r) {
      continue;
    }
    // El rango formado lo insertamos en el monticulo.
    pq.push(rango(l + 1, r - 1));
  }
  long long mx_gan = 0;
  // Se obtienen a lo mas n rangos del monticulo y sus ganancias maximas se
  // suman.
  while (!pq.empty() && n > 0) {
    rango act = pq.top();
    pq.pop();
    if (act.mx_gan <= c) {
      break;
    }
    mx_gan += act.mx_gan - c;
    // A los sobrantes rangos [l, posL - 1] y [posR + 1, r] los insertamos al
    // monticulo.
    if (act.posL > act.l) {
      pq.push(rango(act.l, act.posL - 1));
    }
    if (act.posR < act.r) {
      pq.push(rango(act.posR + 1, act.r));
    }
    n--;
  }
  std::cout << mx_gan << "\n";
}
