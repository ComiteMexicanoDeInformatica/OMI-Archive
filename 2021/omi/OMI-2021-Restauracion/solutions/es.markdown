## Observaciones necesarias

### Determinar viabilidad de la restauración

Para que la restauración de una pirámide sea viable, se requiere que se cumplan los siguiente puntos:

- Que los $K$ escalones fijos formen una secuencia creciente.
- Que la diferencia de altura entre dos escalones fijos consecutivos sea mayor o igual que la distancia entre ellos $h_{k_{i + 1}} - h_{k_i} \geq k_{i + 1} - k_i$. Si la desigualdad no se cumple, es imposible crear una secuencia creciente entre los escalones fijos.
- Que la altura del primer escalón fijo sea al menos igual a su posición menos uno. Esto es necesario para poder construir el tramo que va del inicio al primer escalón fijo sin que el primer escalón tenga que tener altura menor a cero.

Si alguno de los puntos anteriores falla, la pirámide no se puede restaurar.

Un posible código que hace dicha validación es el siguiente:

```
  rep(i, 2, k) {
    if ((intactas[i] - intactas[i - 1]) >
        (a[intactas[i]] - a[intactas[i - 1]])) {
      std::cout << -1 << nl;
      return 0;
    }
  }
  if (a[intactas[1]] < intactas[1] - 1) {
    std::cout << -1 << nl;
    return 0;
  }
```

### Obtención del mínimo de escalones a restaurar

Para que un escalón se pueda dejar como está es necesario que su altura esté entre las de los dos escalones fijos a su izquierda y a su derecha. Sin embargo, esta condición no es suficiente, además se requiere que su altura permita _ajustar_ las alturas de los escalones intermedios entre él y los escalones fijos entre los que está.

La observación anterior nos permite quedarnos con los escalones viables para dejar sin restauración y descartar todos los demás.

Un posible código para hacer esta selección es el siguiente:

```
  a[0] = -1; // ESCALON INTACTO VIRTUAL AL INICIO DE LA ESCALERA
  intactas[0] = 0;
  a[n + 1] = 2e9; // ESCALON VIRTUAL AL FINAL DE LA ESCALERA
  intactas[k + 1] = n + 1;
  rep(i, 1, k + 1){
      lli anterior = intactas[i - 1];
      lli siguiente = intactas[i];
      rep(j, anterior + 1, siguiente - 1){
          if (a[j] - a[anterior] < j - anterior) a[j] = -1;
          if (a[siguiente] - a[j] < siguiente - j) a[j] = -1;
      }
  }
```

Luego de ejecutar este código todos los escalones no viables tendrán altura $-1$ y los viables conservarán su altura inicial.

Observa que si queremos elegir algunos escalones de entre los viables, los que elijamos deben a su vez formar una secuencia creciente. De modo que el problema, luego de la observación previa, se transforma en obtener la secuencia creciente más larga entre las nuevas alturas.

Existen formas no óptimas de elegir la secuencia creciente más larga, en la descripción de las subtareas se detallarán formas que eligen de forma correcta la secuencia más larga.

## Subtarea 1, $N \leq 20$ Siempre es posible restaurar (23 puntos)

Los límites permiten probar todas las opciones posibles de restaurar o no restaurar cada escalón usando una máscara de $20$ bits.

Un posible código para obtener el máximo es el siguiente:

```
  rep(i, 1, k) deja[intactas[i]] = 1;
  lli maxmascara = 1 << n;
  rep(mascara, 0, maxmascara - 1){
      lli ult = -1;
      lli ultpos = 0;
      lli cnt = 0;
      for(int bit = 1, pos = 1; bit < maxmascara; bit <<= 1, ++pos){
        if (bit & mascara){ // SE DESEA DEJAR ESA POSICION INTACTA
            if (a[pos] == -1) break; // NO ES UN ESCALON VIABLE
            if (a[pos] - ult < pos - ultpos) break;
            ++cnt; // AUMENTA LA CUENTA DE POSICIONES INTACTAS
            ultpos = pos;
            ult = a[pos];
        }
        else if (deja[pos]) break; // ES UNO DE LOS ESCALONES FIJOS
        if (pos == n && cnt > maxlis){
            maxlis = cnt;
            mskmaxlis = mascara;
        }
      }
  }

  for(int bit = 1, pos = 1; bit < maxmascara; bit <<= 1, ++pos)
    if (!(bit & mskmaxlis)) a[pos] = a[pos - 1] + 1;
  rep(i, 1, n) std::cout << a[i] << " ";
  std::cout << nl;
```

## Subtarea 2, $N \leq 1000$ (37 puntos)

En la subtarea 2 los límites permiten calcular la secuencia creciente más larga mediante un algoritmo cuadrado.

Una forma de hacerlo es guardando para cada escalón viable la cadena creciente más larga que se puede formar terminando en él. Si dicha longitud se guarda en $maxlis[i]$ una forma de calcularlo es:

- Para cada escalón viable $i$...
- $maxlis[i] = \large max \normalsize (maxlis[j]) + 1$ para todos los $j < i$ tales que sean un escalón viable y las alturas y distancias permitan a $i$ seguir de $j$ en la secuencia creciente.

Para poder construir el resultado es necesario guardar además un apuntador al escalón previo.

El siguiente código resuelve la subtarea 1 y 2:

```
  for(int i = 1; i <= n; ++i){
     if (a[i] > -1){
        for(int j = 0; j < i; ++j){
            if ((a[j] > -1 || !j) && a[i] - a[j] >= i - j){
                if (maxlis[j] >= maxlis[i]){
                    maxlis[i] = maxlis[j] + 1;
                    prev[i] = j;
                }
            }
        }
     }
  }

  for(int i = n; i > 0; --i){
     if (a[i] > -1){
        p = i;
        while (p){
            deja[p] = 1;
            p = prev[p];
        }
        break;
     }
  }
  for (int i = 1; i <= n; ++i){
    if (!deja[i]) a[i] = a[i - 1] + 1;
    std::cout << a[i] << " ";
  }
  std::cout << nl;
```

## Subtarea 3, (40 puntos)

Para resolver la subtarea 3 se requiere un método de calcular la secuencia creciente más larga en tiempo logarítmico. Existen varios algoritmos para hacer esta operación, sin embargo no toman en cuenta la restricción adicional de este problema de que además de ser creciente, la diferencia de altura entre dos escalones debe ser mayor o igual que la distancia entre ellos.

Una forma de eliminar la variable de la distancia entre escalones es _normalizar_ las alturas.

De la observación se concluyó que dos escalones $j$ e $i$ con $j < i$ pueden estar en la misma escalera si $a[i] - a[j] >= i - j$. Manipulando la desigualdad se obtiene que

$a[i] - a[j] >= i - j \implies a[i] - a[j] - (i - j) = a[i] - (a[j] + (i - j)) >= 0$

Es decir, si a cada $a[j]$ se le suma $i - j$ basta con revisar que la diferencia de altura de $a[j]$ con $a[i]$ sea mayor o igual que cero. Esto se puede hacer de manera sencilla sumando a cada altura de los escalones viables $n - i$.

Una vez teniendo las alturas normalizadas se puede buscar la secuencia más larga de números iguales o crecientes para obtener la solución. Al igual que en el caso anterior, es necesario guardar un apuntador al elemento previo para poder construir la escalera final.

Un posible código para resolver la subtarea 3 y obtener los 100 puntos es:

```
  // NORMALIZA LAS ALTURAS
  for(int i = 0; i <= n; ++i) if (a[i] > -1 || !i) a[i] += n - i;

  std::vector<std::pair<lli, lli> > lis;
  lis.push_back({a[0], 0});
  lli l, r, mitad, mayor;
  for(int i = 1; i <= n; ++i){
     if (a[i] > -1){
        l = 0;
        r = lis.size() - 1;
        mayor = -1;
        while (l <= r){
            mitad = (l + r) / 2;
            if (lis[mitad].first > a[i]){
                mayor = mitad;
                r = mitad - 1;
            }
            else l = mitad + 1;
        }
        if (mayor == -1){
            prev[i] = lis.back().second;
            maxlis[i] = lis.size();
            lis.push_back({a[i], i});
        }
        else{
            prev[i] = lis[mayor - 1].second;
            lis[mayor] = {a[i], i};
            maxlis[i] = mayor;
        }
     }
  }
```
