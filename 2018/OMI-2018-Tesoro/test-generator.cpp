#include <bits/stdc++.h>
#define se second
#define fi first
#define ll long long
using namespace std;

int main()
{
    pair<ll,ll> casos[40]=
    {
        { 7,9 }, { 10,17 }, { 21,45 }, { 20,116 }, { 432,500 }, { 123,456 }, { 449,399 }, { 500,499 }, { 500,500 }, { 500,500 },
        { 785,894 }, { 607,895 }, { 799,1000 }, { 999,887 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 },
        { 900,950 }, { 456,789 }, { 997,789 }, { 795,456 }, { 845,1000 }, { 845,684 }, { 875,568 }, { 648,684 }, { 599,799 }, { 949,890 },
        { 785,894 }, { 607,895 }, { 799,1000 }, { 999,887 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }, { 1000,1000 }
    };


    /**generador de aleatorios**/
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> porcentaje(1, 100);

    /**Ciclo para generar los casos en archivos .in**/
    for (long long n=0; n<40; ++n)
    {
        ofstream in;
        stringstream ss;
        ss << n+1;
        string str = ss.str();
        in.open(str+".in");

        int N = casos[n].fi , M = casos[n].se;

        in << N << " " << M << "\n";
        std::uniform_int_distribution<> fila(0,N-1);
        bool mdo[N][M];
        for(int i=0; i<N; i++) for(int j=0; j<M; j++) mdo[i][j]=false;

        for(int i=0; i<M; i++) if(porcentaje(gen)<=75) mdo[fila(gen)][i]=true;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) in << (int)mdo[i][j];
            in << "\n";
        }
        in << "\n";

        in.close();
    }
    return 0;
}
