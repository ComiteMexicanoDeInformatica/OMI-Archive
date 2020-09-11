#include "atrapando.h"
#include <stdlib.h>
#include <algorithm>

using namespace std;

// Main
//	int ponMuro(int f, int c, int d)

const int EAST = 1;
const int NORTH = 2;
const int WEST = 3;
const int SOUTH = 4;

int offset;
int columna,fila;
bool horizontales[11][11];
bool verticales[11][11];

void muro(int f, int c, int d) {
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
    if ((d == NORTH && !horizontales[f][c]) || (d == EAST && !verticales[f][c])) {
        //printf("pon muro %d %d %c \n",f,c, ds[d]);
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
    for (i = 0; i < 32; i++) {
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
    //encierra con binaria

    int pizq = izq - 1;
    int pder = der;
    int psup = sup;
    int pinf = inf + 1;
    int alto, ancho;
    int pivote;

    for (i = 0; i< 10; i++) {
        ancho = pder - pizq;
        alto = pinf - psup;
        //decide si vas a hacer horizontal o vertical
        if (ancho < alto) {
            //pon paredes horizontales
            pivote = (psup + pinf) / 2;
            for (x=pizq+1; x <= pder; x++) {
                muro(pivote, x, NORTH);
            }

            if (fila < pivote) {
                //estoy arriba
                pinf = pivote -1;
            } else {
                //estoy abajo
                psup = pivote;
            }

        } else {
            //pon paredes verticales
            pivote = (pizq + pder) / 2;
            for (y=psup; y < pinf; y++) {
                muro(y, pivote, EAST);
            }

            if (columna <= pivote) {
                //estoy a la izquierda
                pder = pivote;

            } else {
                //estoy a la derecha
                pizq = pivote;
            }
        }

    }

}

