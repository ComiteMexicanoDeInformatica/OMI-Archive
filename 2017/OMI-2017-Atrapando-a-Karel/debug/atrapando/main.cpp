#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

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

vector<int> paredes;

int penalty[5];
int last_move;
int nsum,ssum,esum,wsum;

[[ noreturn ]] void abortar() {
    puts("0.0");
    exit(0);
}

int puntaje() {
    float score = 1;
    float pivot = 0;

    if (fcount <= 53){
        score = 1;
    } else if (fcount <= (10*n)) {
        pivot = sqrt((fcount - 53) / ((10.0 * n) - 53));
        score = (1.0 - pivot) + (0.5 * pivot);
    } else {
        pivot = (fcount - (10.0*n)) / ((100.0*n) - (10.0*n));
        score = (0.5 * (1.0 - pivot)) + (0.2 * pivot);
    }

    printf("%.2f\n", score);
    fprintf(stderr, "%d %.2f\n", fcount, score);
    exit(0);
}

bool move(int dir)
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

    if (columna_karel < 1 || columna_karel > n || fila_karel < 1 || fila_karel > n) {
            abortar();
            return false;
    }
    return true;
}

int its_a_trap(int d) {
    int y = fila_karel;
    int x = columna_karel;
    switch(d) {
        case NORTH:
            y--;
            break;
        case EAST:
            x++;
            break;
        case SOUTH:
            y++;
            break;
        case WEST:
            x--;
            break;
    }
    int r = 0;
    if (muros_filas[x][y]) {
        r++;
    }
    if (muros_filas[x-1][y]) {
        r++;
    }
    if (muros_columnas[x][y]) {
        r++;
    }
    if (muros_columnas[x][y+1]) {
        r++;
    }

    return r * 10;

}

int use_the_force(int ffila, int fcolumna) {
    float fx = 0;
    float fy = 0;
    int i,j;


    for (i=0;i<=n;i++){
        for(j =0;j<=n;j++){
            int dcol, scol;
            int dfil, sfil;

            dcol = (fcolumna != i) ? i - fcolumna: 1;
            dfil = (ffila != j) ? j - ffila: 1;
            scol = (fcolumna >= i) ? 1: -1;
            sfil = (ffila > j) ? 1: -1;
            if (muros_columnas[i][j]) {
                fx += scol/pow(dcol,2);
                fy += sfil/pow(dfil,2);
            }
            if (muros_filas[i][j]) {
                fx += scol/pow(dcol,2);
                fy += sfil/pow(dfil,2);
            }
        }
    }

    if (abs(fx) > abs(fy)){
        if (fx > 0) {
            return EAST;
        } else {
            return WEST;

        }

    } else {
        if (fy > 0) {
            return SOUTH;
        } else {
            return NORTH;
        }
    }
}

int ponMuro(int f, int c, int d) {
    fcount ++;
    char ds[5]= {'_','E','N','O','S'};
    //fprintf(stderr, "(%d) pon muro %d %d %c \n", fcount, f, c, ds[d]);
    if (fcount > maxf) abortar();

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

    int dirf = use_the_force(fila_karel, columna_karel);
    int dir = posible[rand() % p];
    if (dirf == NORTH && ndist < 10000) {
        dir = dirf;
    } else if (dirf == SOUTH && sdist < 10000) {
        dir = dirf;
    } else if (dirf == EAST && edist < 10000) {
        dir = dirf;
    } else if (dirf == WEST && wdist < 10000) {
        dir = dirf;
    }

    move(dir);

    return dir;
}

///////////////////////////////////////////////////////////

void atrapando(int n) {
	int x=(n/2)+1,y=(n/2)+1,d=1;
	int r,c=7;
	r=ponMuro(x,y,4);
	ponMuro(x,y,3);
	//while(r!=0 && c>0){
        d=r;
            if(r==4){
                    y+=8;
                ponMuro(y,x,d);
                ponMuro(y,x-1,4);
                ponMuro(y,x+1,1);
                ponMuro(y,x+1,2);
                ponMuro(y,x+1,4);
                ponMuro(y,x-1,3);
                ponMuro(y,x-1,2);
                r=ponMuro(y,x,2);
                if(r==1)ponMuro(y,x+1,3);
                if(r==3)ponMuro(y,x-1,1);
            }
            if(r==2){
                    y-=8;
                ponMuro(y,x,d);
                ponMuro(y,x-1,4);
                ponMuro(y,x+1,1);
                ponMuro(y,x+1,2);
                ponMuro(y,x+1,4);
                ponMuro(y,x-1,3);
                ponMuro(y,x-1,2);
                r=ponMuro(y,x,4);
                if(r==1)ponMuro(y,x+1,3);
                if(r==3)ponMuro(y,x-1,1);
            }
            if(r==1){
                    x+=8;
                ponMuro(y,x,d);
                ponMuro(y-1,x,2);
                ponMuro(y+1,x,1);
                ponMuro(y+1,x,4);
                ponMuro(y+1,x,3);
                ponMuro(y-1,x,3);
                ponMuro(y-1,x,1);
                r=ponMuro(y,x,1);
                if(r==2)ponMuro(y-1,x,4);
                if(r==4)ponMuro(y+1,x,2);
            }
            if(r==3){
                    x-=8;
                ponMuro(y-1,x,2);
                ponMuro(y+1,x,1);
                ponMuro(y+1,x,4);
                ponMuro(y+1,x,3);
                ponMuro(y-1,x,3);
                ponMuro(y-1,x,1);
                r=ponMuro(y,x,3);
                if(r==2)ponMuro(y-1,x,4);
                if(r==4)ponMuro(y+1,x,2);
            }

        /*cout<<y<<" "<<x<<" "<<d<<"\n";

        printf("%d \n",r);*/
	//}
	//return;
}
///////////////////////////////////////////////////////////////////

int main() {

    scanf("%d", &n);
    srand (n * 15487469);
    fclose(stdin);
    fcount = 0;
    maxf = n*100;
    columna_karel = (n+1) / 2;
    fila_karel = columna_karel;

    atrapando(n);

    abortar();

    return 0;
}
