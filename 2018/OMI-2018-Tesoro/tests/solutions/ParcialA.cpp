/// Complejidad O(M N lg N )
/// Numero de preguntas M lg N
#include "tesoro.h"

int sumasFC[1001][1001],N,M;

void update(int FF,int CC){
    while(CC<=M){
        sumasFC[FF][CC]++;
        CC+=(CC&-CC);
    }
    return;
}

int query(int FF,int CC){
    int x=0;
    while(CC>0){
        x+=sumasFC[FF][CC];
        CC-=(CC&-CC);
    }
    return x;
}

int sumas(int fila,int columna){
    return query(fila,columna);
}

void BuscaTesoros(int n, int m, int k){

        N = n; M = m;
        int ini,fin,md,r,rn;

        for(int i=1; i<=m; i++){

            ini = 1;
            fin = n;
            rn = Preguntar(n,i);
            if(!(rn-sumas(n,i))) continue;

            while(ini!=fin){

                md=(ini+fin)/2;
                r=(md==n)?rn:Preguntar(md,i);
                if(!(r-sumas(md,i))){
                        ini=md+1;
                }else{
                        fin=md;
                }

            }

            for(int f=ini; f<=n; f++) update(f,i);
            Cavar(ini,i);
        }

        return;
}
