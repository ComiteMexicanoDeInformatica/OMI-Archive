#include<bits/stdc++.h>
using namespace std;
int N, M, tabla[15][15], cfilas, ccolumnas, suma;
bool cambiosfila[15], cambioscolumna[15], checar;
int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", &tabla[i][j]);
    for(int i=0; i<(1<<(N+M)); i++)
    {
        cfilas=ccolumnas=0;
        memset(cambiosfila, false, sizeof(cambiosfila));
        memset(cambioscolumna, false, sizeof(cambioscolumna));
        for(int j=0; j<N; j++)
            if(i&(1<<j))
                cambiosfila[j+1]=true, cfilas++;
        for(int j=N; j<N+M; j++)
            if(i&(1<<j))
                cambioscolumna[j-N+1]=true, ccolumnas++;
        checar=false;
        for(int k=1; k<=N; k++)
        {
            suma=0;
            for(int j=1; j<=M; j++)
                if((cambiosfila[k] && !cambioscolumna[j]) || (!cambiosfila[k] && cambioscolumna[j]))
                    suma-=tabla[k][j];
                else
                    suma+=tabla[k][j];
            if(suma<0)
            {
                checar=true;
                break;
            }
        }
        if(checar)
            continue;
        for(int k=1; k<=M; k++)
        {
            suma=0;
            for(int j=1; j<=N; j++)
                if((cambiosfila[j] && !cambioscolumna[k]) || (!cambiosfila[j] && cambioscolumna[k]))
                    suma-=tabla[j][k];
                else
                    suma+=tabla[j][k];
            if(suma<0)
            {
                checar=true;
                break;
            }
        }
        if(checar)
            continue;
        printf("%d ", cfilas);
        for(int k=1; k<=N; k++)
            if(cambiosfila[k])
                printf("%d ", k);
        printf("\n");
        printf("%d ", ccolumnas);
        for(int k=1; k<=M; k++)
            if(cambioscolumna[k])
                printf("%d ", k);
        return 0;
    }
}
