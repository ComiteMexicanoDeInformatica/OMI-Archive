//Solución de Julián Rodríguez Cárdenas
#include "moebius.h"
typedef long long ll;

ll pos,dir,pasos,ant,ini,fin,dist,aux;
ll v[3];
ll mid=-9223372036854775807;

void encuentraCasa(long long origen,long long destino)
{
    if(origen==destino)
        return;

    v[0]=origen;

    for(ll i=1;i<=2;i++)
    {
        v[i]=avanza(1);
        if(v[i]==destino)
            return;
    }
    if(v[0]<v[1] && v[1]<v[2])
        dir=1;
    else
    {
        if(v[0]>v[1] && v[1]>v[2])
            dir=-1;
        else
        {
            if((v[2]>v[1] && v[2]>v[0]) || (v[0]<v[1] && v[0]<v[2]))
                dir=-1;
            else
                dir=1;
        }
    }

    if(dir==1)
    {
        pos=v[2];
        ant=pos;
        pasos=2LL;

        if(pos<destino)
        {
            ant=pos;
            while(pos<destino && pos>=ant)
            {
                ant=pos;
                pos=avanza(pasos);
                if(pos==destino)
                    return;
                pasos+=pasos;
            }

            if(pos>ant)
            {
                ///binaria normal
                dist=pasos/2;
                mid=pos;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(1);
                        while(mid!=destino)
                            mid=avanza(-1);
                        return;
                    }

                    mid=avanza(mid<destino?dist:(dist*-1));
                    if(mid==destino)
                        return;
                }
            }
            else
            {
                dist=pasos/2;

                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(1);
                        while(mid!=destino)
                            mid=avanza(-1);
                        return;
                    }
                    mid=avanza((mid<pos || mid>destino)?(dist*-1):dist);
                    if(mid==destino)
                        return;
                }
            }
        }
        else
        {
            ant=pos;
            while(pos>destino && pos<=ant)
            {
                ant=pos;
                pos=avanza(pasos*-1);
                if(pos==destino)
                    return;
                pasos+=pasos;
            }

            if(pos<ant)
            {
                mid=pos;
                dist=pasos/2;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(1);
                        while(mid!=destino)
                            mid=avanza(-1);
                        return;
                    }

                    mid=avanza(mid<destino?dist:(dist*-1));
                    if(mid==destino)
                        return;
                }
            }
            else
            {
                dist=pasos/2;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(1);
                        while(mid!=destino)
                            mid=avanza(-1);
                        return;
                    }
                    if(mid>pos)
                        mid=avanza(dist);
                    else
                        mid=avanza(mid<destino?(dist):(dist*-1));
                    if(mid==destino)
                        return;
                }
            }
        }
    }

    pos=v[2];
        ant=pos;
        pasos=2LL;

        if(pos<destino)
        {
            ant=pos;
            while((!(ant>destino && pos<destino)) && (!(pos<destino && ant<destino && pos>ant)))
            {
                ant=pos;
                pos=avanza(pasos);
                if(pos==destino)
                    return;
                pasos+=pasos;
            }

            if(ant>destino)
            {
                dist=pasos/2;
                mid=pos;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(-1);
                        while(mid!=destino)
                            mid=avanza(1);
                        return;
                    }

                    mid=avanza(mid<destino?(dist*-1):dist);
                    if(mid==destino)
                        return;
                }
            }
            else
            {
                dist=pasos/2;

                mid=pos;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(-1);
                        while(mid!=destino)
                            mid=avanza(1);
                        return;
                    }
                    mid=avanza((mid<destino && mid>=pos)?(dist*-1):(dist));
                    if(mid==destino)
                        return;
                }
            }
        }
        else
        {
            ant=pos;
            while(pos>destino && pos<=ant)
            {
                ant=pos;
                pos=avanza(pasos);
                if(pos==destino)
                    return;
                pasos+=pasos;
            }

            if(pos<ant)
            {
                mid=pos;
                dist=pasos/2;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(-1);
                        while(mid!=destino)
                            mid=avanza(1);
                        return;
                    }

                    mid=avanza(mid<destino?(dist*-1):dist);
                    if(mid==destino)
                        return;
                }
            }
            else
            {
                dist=pasos/2;
                mid=pos;
                while(true)
                {
                    dist/=2;
                    if(dist==0)
                    {
                        while(mid<destino)
                            mid=avanza(-1);
                        while(mid!=destino)
                            mid=avanza(1);
                        return;
                    }
                    mid=avanza((mid<destino || mid>=pos)?(dist*-1):(dist));
                    if(mid==destino)
                        return;
                }
            }
        }
}
