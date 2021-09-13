## Subtareas 1 , $n^2$ llamadas (15 puntos)

Esta primer subtarea se puede resolver con una idea simple de ordenar todos los numeros, usando el algoritmo de ordenamiento mas sencillo que hay, que es el bubble sort, cuya complejidad es de hecho menor a $n^2$ asi que resuelve el problema con menos llamadas de las necesarias

```
void buscaExtremos(int n) {
  std::vector<int> numeros;
  for(int i=1;i<=n;i++)
  {
  	numeros.push_back(i);
  }
  for(int i=0;i<n;i++)
  {
  	for(int j=i;j<n-1;j++)
  	{
  		if(!esMenor(j, j + 1))
  		{
  			numeros[j]= numeros[j] xor numeros[j+1];
			numeros[j+1]= numeros[j] xor numeros[j+1];
			numeros[j]= numeros[j] xor numeros[j+1];
		}
	}
  }
  respuesta(numeros[0], numeros[n-1]);
  return;
}
```

## Subtareas 2 , $2n$ llamadas (30 puntos)

La segunda subtarea puede resolverse fácilmente, dándonos cuenta que como solo nos importa el menor y el mayor valor, así que no necesitamos ordenar todos los demas numeros, entonces con una pasada podemos encontrar el mayor numero, y en otra pasada, el menos, y eso en total nos da $2n-2$ llamadas. Cada pasada consisten en llevar nuestro candidato a menor, e intercambiarlo con cualquier numero que sea menor a el, y viceversa con el mayor.

```
void buscaExtremos(int n) {
  std::vector<int> numeros;
  men=1;
  may=1;
  for (int i = 2; i + 1 <= n; i ++) {
    if (esMenor(men, i)) {
      men=i;
    }
    if (esMenor(i,may)) {
      may=i;
    }
  }
  respuesta(men,may);
  return;
}
```

## Subtareas 3 , solucion oficial (55 puntos)

Una forma de ver el problema es que para cada valor de nuestro arreglo de números, tenemos 2 booleanos, que representan si un numero puede ser el mayor y el menor numero respectivamente. Y lo que queremos es hacer operaciones para que al final solo 1 numero tenga el booleano de mayor encendido y uno el de menor encendido.

Ahora, veamos que al comparar 2 números, a lo mucho podemos cambiar 2 valores booleanos de verdadero a falso. Y eso solo podemos asegurarlo cuando ambos números tienen sus dos booleanos encendidos. Más aún, al hacer una comparación entre dos números con sus dos booleanos encendidos, apagaremos un booleano en ambos. Entonces podemos hacer $\lfloor\frac{n}{2}\rfloor$ comparaciones de números, en donde nos aseguramos de cambiar 2 valores booleanos, y en las demás llamadas lo más que podemos asegurar es que cambie 1.

De modo que lo mejor que podemos asegurar es requerir $\lfloor\frac{n}{2}\rfloor + (n - 2)$ si $n$ es par o $\lfloor\frac{n}{2}\rfloor + (n - 1)$ si $n$ es impar.

Existen varias formas de lograr esta cota, una de ella es: comparar por parejas los números y quedarnos con el grupo de números que podrían ser el mayor, y el grupo de números que podrían ser el menor. Y después hacemos $\lceil\frac{n}{2}\rceil-1$ comparaciones entre números que pueden ser el menor, y también $\lceil\frac{n}{2}\rceil-1$ comparaciones entre números que pueden ser el mayor. Y con eso tenemos una solución que nos asegura el mínimo de llamadas posibles en todos los casos, aunque no siempre nos dará la solución optima, basta para sacar 100 puntos.

```
void buscaExtremos(int n) {
  std::vector<int> mins, maxs;
  for (int i = 1; i + 1 <= n; i += 2) {
    if (esMenor(i, i + 1)) {
      mins.push_back(i);
      maxs.push_back(i + 1);
    } else {
      mins.push_back(i + 1);
      maxs.push_back(i);
    }
  }
  if (n % 2 != 0) {
    mins.push_back(n);
    maxs.push_back(n);
  }

  int mn = mins[0];
  for (int i = 1; i < mins.size(); i++)
    if (esMenor(mins[i], mn)) mn = mins[i];

  int mx = maxs[0];
  for (int i = 1; i < maxs.size(); i++)
    if (esMenor(mx, maxs[i])) mx = maxs[i];

  respuesta(mn, mx);
  return;
}
```
