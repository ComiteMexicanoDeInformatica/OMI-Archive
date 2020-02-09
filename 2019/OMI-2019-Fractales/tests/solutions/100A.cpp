#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll MayorPotencia3LE(ll n) {
    ll i = 1;
    while (true) {
        ll k = i * 3;
        if (k > n) {
            return i;
        }
        i = k;
    }
}

ll LogBase3(ll n) {
    ll ret = 0;
    ll num = 1;
    while (true) {
        num *= 3;
        if (num > n) {
            return ret;
        }
        ret++;
    }
}

ll IntPow(ll base, ll exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp % 2 == 0) {
        ll ret = IntPow(base, exp / 2);
        return ret*ret;
    } else {
        ll ret = IntPow(base, exp / 2);
        return ret*ret*base;
    }
}

ll TilesCompletos(ll tile_size, ll m, ll n) {
    auto a = (m + 1) / tile_size;
    auto b = (n + 1) / tile_size;
    auto ret = a * b;
    if (2 <= a && 2 <= b) {
        ret--;
    }
    if (3 <= a && 3 <= b) {
        ret--;
    }
    return ret;
}

ll Cuenta(ll m, ll n) {
    if (n < m) {
        swap(n, m);
    }
    ll tile_size = MayorPotencia3LE(n);
    // Caso de cuadrado de 3 a la n por 3 a la n
    if (n == m && n == tile_size * 3 - 1) {
        ll exponente = LogBase3(tile_size * 3);
        return IntPow(7, exponente);
    }
    ll tile_a = m / tile_size;
    ll tile_b = n / tile_size;
    ll ret = 0;
    ll tile_por_n_count = 0;
    ll m_por_tile_count = 0;
    ll complete_tile_count = IntPow(7, LogBase3(tile_size));
    for (ll i = 0; i <= tile_a; i++) {
        for (ll k = 0; k <= tile_b; k++) {
            if (i == k && i >= 1) {
                continue;
            } else if (tile_size * (i + 1) <= m + 1 && tile_size * (k + 1) <= n + 1) {
                ret += complete_tile_count;
            } else if (tile_size * (i + 1) <= m + 1) {
                // ret += Cuenta(tile_size - 1, n % tile_size);
                tile_por_n_count++;
            } else if (tile_size * (k +1 ) <= n + 1) {
                // ret += Cuenta(m % tile_size, tile_size - 1);
                m_por_tile_count++;
            } else {
                ret += Cuenta(m % tile_size, n % tile_size);
            }
        }
    }
    if (tile_por_n_count > 0) {
        ret += tile_por_n_count * Cuenta(tile_size - 1, n % tile_size);
    }
    if (m_por_tile_count > 0) {
        ret += m_por_tile_count * Cuenta(m % tile_size, tile_size - 1);
    }
    return ret;
}

int main() {
    ll x, y;
    cin >> x >> y;
    cout << Cuenta(x - 1, y - 1) << endl;
    return 0;
}
