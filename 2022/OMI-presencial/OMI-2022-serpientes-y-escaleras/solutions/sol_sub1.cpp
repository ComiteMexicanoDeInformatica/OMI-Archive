#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";

#define MAX 1000000
#define MAXP 2000001

int n, m, l, r, c, d, pos, res, pareja[MAXP + 2], ciclo[MAXP + 2], tam[MAXP + 2];
std::vector<int> ciclosPorTamano;

int main() {

    std::cin >> n >> m;
    std::iota(pareja, pareja + MAXP + 1, 1);
    for(int i = 1; i <= n; ++i){
        std::cin >> l >> r;

        // PARA CADA POSICION CONFIGURA COMO SU PAREJA LA POSICION
        // DONDE ESTA EL OTRO EXTREMO DEL PORTAL
        pareja[l] = r;
        pareja[r] = l;
    }

    // SIMULA EL RECORRIDO
    pos = 1;
    while(pos <= 2 * n){
        pos = pareja[pos];
        ++pos;
        ++res;
    }

    std::cout << res << "\n";

    return 0;
}
