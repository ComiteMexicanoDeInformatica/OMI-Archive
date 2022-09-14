#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <vector>
#include <queue>

#define MAX 1000

#define libre 0
#define fuente 1
#define ocupado 2
#define agua 3

int64_t N, M, n, m, F, L, A, tot;
int64_t mapaIni[MAX + 2][MAX + 2];
int64_t mapaFin[MAX + 2][MAX + 2];
int vis[MAX + 2][MAX + 2], df[4], dc[4];
std::string s;
std::queue<std::pair<int, int> > q;
double score;

int cuentaAgua(int fil, int col){
    int nf, nc, res = 0;

    if (vis[fil][col] || mapaFin[fil][col] != libre) return 0;

    for(int d = 0; d < 4; ++d){
        nf = fil + df[d];
        nc = col + dc[d];
        if (mapaFin[nf][nc] == fuente || mapaFin[nf][nc] == agua) ++res;
    }
    return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  df[0] = df[1] = 0;
  df[2] = 1;
  df[3] = -1;

  dc[2] = dc[3] = 0;
  dc[0] = 1;
  dc[1] = -1;

  // LEE LA ENTRADA
  std::ifstream f("data.in");
  f >> N >> M;
  for (int i = 1; i <= N; i++){
    f >> s;
    for (int j = 0; j < M; j++){
        if(s[j] == '#') mapaIni[i][j + 1] = ocupado;
        else mapaIni[i][j + 1] = libre;
    }
  }

  // LEE EL RESULTADO DEL COMPETIDOR
  std::cin >> n >> m;

  // SI EL TAMANIO DEL MAPA DE RESPUESTA ES DISTINTO DEL ORIGINAL, CALIFICA CON 0
  if (n != N || m != M){
    std::cerr << "El tamaño del mapa difiere del original\n";
    printf("%.2f\n", 0.0);
    return 0;
  }

  for(int fil = 1; fil <= N; ++fil){
    // SI NO TIENE SUFICIENTES RENGLONES, CALIFICA CON 0
    if(!(std::cin >> s)){
        std::cerr << "El resultado no tiene suficientes filas\n";
        printf("%.2f\n", 0.0);
        return 0;
    }

    if (s.size() != M){
        std::cerr << "La fila " << fil << " no tiene suficientes columnas\n" << s.size() << std::endl;
        printf("%.2f\n", 0.0);
        return 0;
    }

    for(int col = 0; col < M; ++col){
        if(s[col] == '#') mapaFin[fil][col + 1] = ocupado;
        else if (s[col] == '.') mapaFin[fil][col + 1] = libre;
        else if (s[col] == 'F') mapaFin[fil][col + 1] = fuente;
        else{
            // USA OTROS CARACTERES ADEMAS DE LOS PERMITIDOS, CALIFICA CON 0
            std::cerr << "La posicion (" << fil << ", " << col << ") tiene un caracter invalido\n";
            printf("%.2f\n", 0.0);
            return 0;
        }
    }
  }

  // VALIDA QUE EL MAPA RESPETE LOS OCUPADOS Y LOS LIBRES
  for(int fil = 1; fil <= N; ++fil){
    for(int col = 1; col <= M; ++col){
        if((mapaIni[fil][col] == ocupado && mapaFin[fil][col] != ocupado) ||
           (mapaIni[fil][col] == libre && mapaFin[fil][col] == ocupado)){

            // NO RESPETO EL MAPA, CALIFICA CON 0
            std::cerr << "Las posiciones libres y ocupadas no se respetaron en el resultado\n";
            printf("%.2f\n", 0.0);
            return 0;
        }
    }
  }

  // SIMULA LAS FUENTES
  for(int fil = 2; fil < N; ++fil){
    for(int col = 2; col < M; ++col){
        if (cuentaAgua(fil, col) >= 2){
            vis[fil][col] = 1;
            q.push({fil, col});
        }
    }
  }

  while(!q.empty()){
    int nf, nc;
    int fil = q.front().first;
    int col = q.front().second;
    q.pop();

    mapaFin[fil][col] = agua;
    for(int d = 0; d < 4; ++d){
        nf = fil + df[d];
        nc = col + dc[d];
        if(mapaFin[nf][nc] == libre && !vis[nf][nc] && cuentaAgua(nf, nc) >= 2){
            vis[nf][nc] = 1;
            q.push({nf, nc});
        }
    }
  }

  // CUENTA LAS FUENTES Y LOS ESPACIOS LIBRES
  F = L = A = tot = 0;
  for(int fil = 1; fil <= N; ++fil){
    for(int col = 1; col <= M; ++col){
        if (mapaFin[fil][col] == fuente) ++F;
        else if (mapaFin[fil][col] == libre) ++L;
        else if (mapaFin[fil][col] == agua) ++A;
    }
  }
  tot = F + L + A;

  score = double(F + 2 * L) / double(2 * tot);

  printf("%.2f\n", double(1 - score));
  return 0;

}
