## Observaciones

- Observa que para un tablero de $N \times M$ siempre será posible formar una _columna completa_, ya que para que no fuera posible sería necesario que existiera un grupo de fichas de $K$ colores que estuvieran completamente contenidas en $K - 1$ filas.  Dado que $K - 1$ filas tienen $(K - 1) \times M$ espacios y en total hay $K \times M$ fichas por acomodar, dicho arreglo es imposible.

- Observa que si en un tablero de $N \times M$ se forma una _columna completa_ esta se puede _remover_ del tablero (con las fichas que contiene) y eso nos deja un tablero de $N \times (M - 1)$ que cumple con las características descritas en el problema.

Las dos observaciones anteriores permiten concluir que para cualquier tablero inicial es posible llegar, mediante movimientos válidos, a un tablero que tenga todas sus _columnas completas_.

Sabiendo que siempre es posible llenar el tablero, existen varias formas de tratar de construir la solución.


## Idea 1

Un posible acercamiento es: para cada columna probar todas las permutaciones de N elementos y verificar si con las fichas que aun quedan _sin usar_ se puede formar esa permutación. En caso de que sí, formarla y avanzar a la siguiente columna.

La complejidad de esta idea es $O(N! * M)$ que en tiempo de examen debe ser capaz de resolver, dependiendo de la implementación, los primeros 10 a 11 casos. Sin embargo podrías usar este algoritmo para calcular el mayor número de columnas correctas posible y sacar puntos parciales en cada caso.


## Idea 2

### Observación

Observa que en realidad el acomodo de las fichas _sin usar_ no es importante.  La única información importante es cuántas fichas de cada color hay en cada fila.

Con esta observación se puede transformar el problema a una tabla de $N \times N$ de frecuencias de aparición de cada color en cada fila.

Con esta transformación se pueden de nuevo probar todas las permutaciones de $N$ elementos y para cada permutación, si hay fichas de los colores requeridos en las filas requeridas, formar una columna y restar esas fichas de las filas respectivas.

La complejidad de esta idea es $O((N + 1)!)$ que en tiempo de examen debe ser capaz de resolver uno o dos casos más que la _idea 1_.

## Idea 3

Las ideas anteriores pueden completarse con diversas heurísticas glotonas para podar y mejorar los tiempos de búsqueda logrando conseguir más puntos.

## Solución 

Una posible forma de solucionar todos los casos en tiempo es la siguiente:  

Partiendo de la matriz de $N \times N$ de frecuencias de aparición de cada color en cada fila podemos construir un grafo bipartito con $N$ nodos del lado izquierdo, uno por cada color y $N$ nodos del lado derecho, uno por cada fila. Existe una arista del nodo $i$ al nodo $j$ si $mat[i][j] > 0$.

Observa que en este grafo, un _bipartite matching_ de $N$ aristas corresponde al acomodo de una _columna completa_.  Un _bipartite matching_ es un conjunto de aristas tales que ningún par de aristas tienen nodos en común.  Un _bipartite matching_ de $N$ aristas tendría cada nodo de color asignado a un nodo de fila distinta, dando por tal una _columna completa_ válida.

Existen varios algoritmos conocidos para encontrar un _bipartite matching_ máximo, sin embargo, aun sin conocer ninguno se puede llegar de forma intuitiva al siguiente:

- Para cada nodo entre los nodos de color, busca un nodo de fila al que esté conectado que todavía no esté usado.
- Si encuentras una fila libre, marca dicha fila como usada por el color y detén la búsqueda.
- Si ninguna de las filas con las que el color tiene arista están libres entonces:
  - Elige una fila ocupada
  - Asígnala al color que estás procesando
  - Inicia la búsqueda para el color que tenía originalmente asignado, marcando esa fila como no disponible
  
De las observaciones iniciales y el hecho de que siempre será posible formar una nueva _columna completa_ se puede intuir que este algoritmo siempre va a encontrar el _matching_ deseado.

En cuanto a la complejidad, observa que el algoritmo puede verse como $N$ búsquedas en profundidad (una por cada nodo), cada búsqueda con el potencial de recorrer todas las aristas del grafo que en el peor caso son $N^2$ de modo que la complejidad de ejecución para obtener un _matching_ es de $O(N^3)$ dando una complejidad total para un tablero de $O(N^3M)$ que en el mayor de los casos equivale a $50^3 \times 10000 = 1.25 \times 10^9$ que dependiendo de la máquina debería correr en pocos segundos.

El siguiente código es capaz de resolver todos los casos de prueba en pocos segundos:

```
bool dfs(lli color){
    visitado[color] = 1;
    rep(fila, 1, n){
        if (mat[color][fila] && !colorAsignado[fila]){
            colorAsignado[fila] = color;
            filaAsignada[color] = fila;
            break;
        }
    }

    if (!filaAsignada[color]){
        rep(fila, 1, n){
            if (mat[color][fila] && !visitado[colorAsignado[fila]]){
                lli ctmp = colorAsignado[fila];

                colorAsignado[fila] = color;
                filaAsignada[color] = fila;
                filaAsignada[ctmp] = 0;

                if (dfs(ctmp)) break;

                colorAsignado[fila] = ctmp;
                filaAsignada[ctmp] = fila;
                filaAsignada[color] = 0;
            }
        }
    }

    return filaAsignada[color];
}

int main()
{
    std::cin >> n >> m;

    rep(fil, 1, n){
        rep(col, 1, m){
            std::cin >> color;
            mat[color][fil]++;
            if (mat[color][fil] == 1) aristas[color].push_back(fil);
        }
    }

    rep(col, 1, m){
        rep(i, 1, n) filaAsignada[i] = colorAsignado[i] = 0;
        rep(color, 1, n){
            rep(j, 1, n) visitado[j] = 0;
            dfs(color);
        }
        rep(fila, 1, n){
            tablero[fila][col] = colorAsignado[fila];
            mat[colorAsignado[fila]][fila]--;
        }
    }

    std::cout << nl;
    rep(fil, 1, n){
        rep(col, 1, m) std::cout << tablero[fil][col] << " ";
        std::cout << nl;
    }

    return 0;
}
```





