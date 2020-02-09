#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

using ll = int64_t;
template<typename T>
using Matriz = vector<vector<T>>;

int F, C;
Matriz<int> Valor;
Matriz<int> Color;
Matriz<int> MaxPatronHorizontal;
Matriz<int> NumColumnasOptimo;
Matriz<ll> Sumas;

template<typename T>
Matriz<T> CrearMatriz(int filas, int columnas) {
    return Matriz<T>(filas, vector<T>(columnas));
}

struct SubMatriz {
    int f1;
    int c1;
    int f2;
    int c2;
    ll w;
    bool operator<(const SubMatriz& b) const {
        return w < b.w;
    }
};

template<typename T>
T& operator<<(T& ostream, SubMatriz b) {
        ostream << b.f1 << " " << b.c1 << " " << b.f2 << " " << b.c2;
        return ostream;
}

void LeerEntrada() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> F >> C;
    Valor = CrearMatriz<int>(F, C);
    Color = CrearMatriz<int>(F, C);
    for (auto& fila : Valor) {
        for (auto& celda : fila) {
            cin >> celda;
        }
    }
    for (auto& fila : Color) {
        for (auto& celda : fila) {
            cin >> celda;
        }
    }
}

void CalculaMaxHorizontal() {
    MaxPatronHorizontal = CrearMatriz<int>(F, C);
    for (int i = 0; i < F; ++i) {
        for (int k = 0; k < C; ++k) {
            auto& val = MaxPatronHorizontal[i][k];
            val = 1;
            if (k > 0 && Color[i][k - 1] != Color[i][k]) {
                val += MaxPatronHorizontal[i][k - 1];
            }
        }
    }
}

void CalculaSumas() {
    Sumas = CrearMatriz<ll>(F, C);
    for (int i = 0; i < F; ++i) {
        for (int k = 0; k < C; ++k) {
            auto &val = Sumas[i][k];
            val = Valor[i][k];
            if (i > 0) {
                val += Sumas[i - 1][k];
            }
            if (k > 0) {
                val += Sumas[i][k - 1];
            }
            if (k > 0 && i > 0) {
                val -= Sumas[i - 1][k - 1];
            }
        }
    }
}

ll ObtenSuma(int fila_arriba, int col_izq, int fila_abajo, int col_der) {
    ll ret = Sumas[fila_abajo][col_der];
    if (col_izq > 0) {
        ret -= Sumas[fila_abajo][col_izq - 1];
    }
    if (fila_arriba > 0) {
        ret -= Sumas[fila_arriba - 1][col_der];
    }
    if (col_izq > 0 && fila_arriba > 0) {
        ret += Sumas[fila_arriba - 1][col_izq - 1];
    }
    return ret;
}

SubMatriz CalculaMaxValorEnPosicion(int fila_abajo, int col_der) {
    SubMatriz ret {0, 0, 0, 0, 0};
    for (int fila_arriba = fila_abajo, max_longitud_base = col_der + 1; fila_arriba >= 0; --fila_arriba) {
        if (fila_arriba != fila_abajo && Color[fila_arriba][col_der] == Color[fila_arriba + 1][col_der]) {
            return ret;
        }
        auto num_columnas_optimo_anterior = NumColumnasOptimo[fila_arriba][fila_abajo];
        auto suma_con_columna_unica = ObtenSuma(fila_arriba, col_der, fila_abajo, col_der);
        max_longitud_base = min(max_longitud_base, MaxPatronHorizontal[fila_arriba][col_der]);
        NumColumnasOptimo[fila_arriba][fila_abajo] = 1;
        int mejor_col_izq = col_der;
        ll mejor_suma = suma_con_columna_unica;
        if (col_der > 0 && max_longitud_base > num_columnas_optimo_anterior) {
            int col_izq = col_der - num_columnas_optimo_anterior;
            auto suma_con_varias_columnas = ObtenSuma(fila_arriba, col_izq, fila_abajo, col_der);
            if (mejor_suma < suma_con_varias_columnas) {
                mejor_suma = suma_con_varias_columnas;
                NumColumnasOptimo[fila_arriba][fila_abajo] = num_columnas_optimo_anterior + 1;
                mejor_col_izq = col_izq;
            }
        }
        if (mejor_suma > ret.w) {
            ret = SubMatriz {fila_arriba, mejor_col_izq, fila_abajo, col_der, mejor_suma};
        }
    }
    return ret;
}

SubMatriz CalculaRespuesta() {
    SubMatriz respuesta {0, 0, 0, 0, 0};
    NumColumnasOptimo = CrearMatriz<int>(F, F);
    for (int c = 0; c < C; ++c) {
        for (int f = 0; f < F; ++f) {
            auto valor = CalculaMaxValorEnPosicion(f, c);
            respuesta = max(respuesta, valor);
        }
    }
    return respuesta;
}

int main()
{
    LeerEntrada();
    CalculaMaxHorizontal();
    CalculaSumas();
    cout << CalculaRespuesta() << endl;
    return 0;
}
