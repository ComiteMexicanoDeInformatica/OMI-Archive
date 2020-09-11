#include "atrapando.h"
#include <stdlib.h>
#include <algorithm>

using namespace std;

// Main
//  int ponMuro(int f, int c, int d)

const int EAST = 1;
const int NORTH = 2;
const int WEST = 3;
const int SOUTH = 4;

int offset;
int columna,fila;
bool horizontales[11][11];
bool verticales[11][11];

//fila y
//columna x


void muro(int f, int c, int d) {
    char ds[5]= {'a','E','N','W','S'};
    //normalizamos a solo poner paredes de norte o este
    if(d == SOUTH) {
        d = NORTH;
        f++;
    };
    if(d == WEST) {
        d = EAST;
        c--;
    }

    //asegurate de que no quieras poner una pared donde ya existe una
    //printf("pon muro %d %d %c \n",f,c, ds[d]);
    if ((d == NORTH && !horizontales[f][c]) || (d == EAST && !verticales[f][c])) {
        if (d == NORTH) horizontales[f][c] = true;
        if (d == EAST) verticales[f][c] = true;
        int r = ponMuro(f + offset, c + offset, d);
        switch (r) {
            case EAST:
                columna++;
                break;
            case NORTH:
                fila --;
                break;
            case WEST:
                columna--;
                break;
            case SOUTH:
                fila++;
                break;
        }
        
        //printf("karel se movio a %d %d\n",fila,columna);
    } else {
        //printf("muro duplicado\n");
    }
}

void atrapando(int n) {
    int c = (n + 1) / 2;
    int esq[4][2];
    columna = 5;
    fila = 5;
    //usamos un offset para internamente solo suar una cuadriciula del 1,1 al 9,9
    offset = c - 5;
    int izq,der,sup,inf;
    //define los cuatro limites
    izq = 1;
    sup = 1;
    muro(sup, izq, NORTH);
    inf = fila + 3;
    muro(inf, izq, WEST);
    der = columna + 2;
    muro(sup, der, EAST);
    muro(inf, der, SOUTH);

    //llena el perimetro
    int i,x,y,d;
    int m = 100;
    int mx,my,md;
    int alto, ancho;
    do {
        alto = inf - sup + 1;
        ancho = der - izq + 1;
        for (i = 0; i < (ancho + alto) * 2; i++) {
            //horizontales
            m = 100;
            for (x = izq; x <= der; x++) {
                if (!horizontales[sup][x]) {
                    d = abs(fila - sup) + abs(x - columna);
                    if (d < m ) {
                        m = d;
                        mx = x;
                        my = sup;
                        md = NORTH;
                    }
                }

                if (!horizontales[inf + 1][x]) {
                    d = abs(fila - inf) + abs(x - columna);
                    if (d < m ) {
                        m = d;
                        mx = x;
                        my = inf + 1;
                        md = NORTH;
                    }
                }
            }
            //verticales
            for (y = sup; y <= inf; y++) {
                if (!verticales[y][der]) {
                    d = abs(fila - y) + abs(der - columna);
                    if (d < m ) {
                        m = d;
                        mx = der;
                        my = y;
                        md = EAST;
                    }
                }

                if (!verticales[y][izq - 1]) {
                    d = abs(fila - y) + abs(izq - columna);
                    if (d < m ) {
                        m = d;
                        mx = izq -1;
                        my = y;
                        md = EAST;
                    }
                }
            }
            muro(my, mx, md);
        }

        //cambia el pivote que quite mas
        int msup = (fila - sup) * ancho;
        int minf = (inf - fila) * ancho;
        int mder = (der - columna) * alto;
        int mizq = (columna - izq ) * alto;

        m = max(max(msup, minf), max(mizq, mder));

        if (msup == m) {
            sup = fila;
        } else if (minf == m) {
            inf = fila;
        } else if (mizq == m) {
            izq = columna;
        } else if (mder == m) {
            der = columna;
        }
    } while (m > 0);

}