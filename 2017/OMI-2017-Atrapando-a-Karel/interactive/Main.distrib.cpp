#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "atrapando.h"

using namespace std;

const int EAST = 1;
const int NORTH = 2;
const int WEST = 3;
const int SOUTH = 4;

int n;
int columna_karel, fila_karel;
int fcount;
int maxf;

bool muros_filas[502][502];
bool muros_columnas[502][502];
int contador_columna[502];
int contador_fila[502];
int penalty[5];
int last_move;
int nsum,ssum,esum,wsum;

int abortar() {
    exit(0);
}

int puntaje() {
    printf("Has atrapado a karel en %d movimientos\n", fcount);
    exit(0);
}

int move(int dir)
{
    //penaliza a ir en direccion contraria
    penalty[last_move] = 0;
    last_move = ((dir + 1) % 4) + 1;
    penalty[last_move] = 50;

    //actualiza posicion y calcula paredes
    switch(dir) {
        case NORTH:
            nsum -= contador_fila[fila_karel];
            ssum += contador_fila[fila_karel];
            fila_karel--;
            break;
        case EAST:
            esum -= contador_columna[columna_karel];
            wsum += contador_columna[columna_karel];
            columna_karel++;
            break;
        case SOUTH:
            nsum += contador_fila[fila_karel];
            ssum -= contador_fila[fila_karel];
            fila_karel++;
            break;
        case WEST:
            esum += contador_columna[columna_karel];
            wsum -= contador_columna[columna_karel];
            columna_karel--;
            break;
    }

    printf("karel se movio a %d %d\n",fila_karel,columna_karel);

    if (columna_karel < 1 || columna_karel > n || fila_karel < 1 || fila_karel > n) {
            printf("Karel se ha escapado");
            abortar();
        }
}

int ponMuro(int f, int c, int d) {
    fcount ++;

    char ds[5]= {'_','E','N','O','S'};
    printf("(%d) pon muro %d %d %c \n", fcount, f, c, ds[d]);

    if (fcount > maxf) {
        printf("has excedido el maximo de instruccines");
        abortar();
    }

    if (d >= WEST) {
        d -= 2;
        if (d == NORTH) f++;
        if (d == EAST) c--;
    }
    bool pon = false;
    if (c >= 0 && c <= n + 1 && f >= 0 && f <= n + 1) {
        if (d == NORTH && !muros_columnas[c][f]) {
            muros_columnas[c][f] = true;
            pon = true;
        } else if (d == EAST && !muros_filas[c][f]) {
            muros_filas[c][f] = true;
            pon = true;
        }
        if (pon) {
            contador_fila[f]++;
            contador_columna[c]++;
            if (c >= columna_karel) {
                esum ++;
            } else {
                wsum ++;
            }

            if (f <= fila_karel) {
                nsum ++;
            } else {
                ssum ++;
            }
        }
    }

    //evalua a donde moverte
    int ndist = 10000;
    int sdist = 10000;
    int edist = 10000;
    int wdist = 10000;

    if (!muros_columnas[columna_karel][fila_karel]) {
        ndist = penalty[NORTH] + nsum + fila_karel - 1;
    }
    if (!muros_filas[columna_karel][fila_karel]) {
        edist = penalty[EAST] + esum + n - columna_karel;
    }
    if (!muros_columnas[columna_karel][fila_karel+1]) {
        sdist = penalty[SOUTH] + ssum + n - fila_karel;
    }
    if (!muros_filas[columna_karel-1][fila_karel]) {
        wdist = penalty[WEST] + wsum + columna_karel - 1;
    }

    int m = min(min(ndist, sdist), min(edist, wdist));

    int posible[4];
    int p = 0;

    if (m == 10000) puntaje();

    if (ndist == m) {
        posible[p] = NORTH;
        p++;
    }

    if (edist == m) {
        posible[p] = EAST;
        p++;
    }
    if (sdist == m) {
        posible[p] = SOUTH;
        p++;
    }
    if (wdist == m) {
        posible[p] = WEST;
        p++;
    }

    int dir = posible[rand() % p];

    move(dir);

    return dir;
}

void main() {

    scanf("%d", &n);
    srand (n * 87776810);
    fclose(stdin);
    fcount = 0;
    maxf = n*100;
    columna_karel = (n+1) / 2;
    fila_karel = columna_karel;

    printf("El mundo es de %dx%d \n", n, n);
    printf("karel esta en %d %d\n",fila_karel,columna_karel);
    
    atrapando(n);

    printf("No has encerrado a Karel");
    abortar();
}
