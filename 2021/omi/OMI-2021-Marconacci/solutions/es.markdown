## Subtareas 1 y 2, $i \leq 30$ (5 puntos), $P = 1$ (10 puntos)

Calcular cada término de la serie requiere de una suma. Si $i$ (el término que se pide es menor o igual que $30$) implica que por cada pregunta en el archivo de entrada se requieren a lo más $30$ sumas. La cantidad máxima de preguntas es $10^5$ por lo que resolver el problema calculando todo requiere en total $3 \times 10^6$ sumas que puede ejecutarse en el tiempo del problema.

Para el caso de una sola pregunta igualmente el máximo de sumas que se requiere es $10^6$.

Un posible código para ambas subtareas es el siguiente:

```
int main()
{
    cin >> q;
    while(q--){
        cin >> a >> b >> t;

        if (t == 1) cout << a << nl;
        else if (t == 2) cout << b << nl;
        else {
            for (int c = 3; c <= t; c++){
                x = a + b;
                x %= MOD;
                a = b;
                b = x;
            }
            cout << x << nl;
        }
    }

    return 0;
}
```

## Subtarea 3, en todas las preguntas se usa el mismo valor de $A$ y $B$ (15 puntos)

Si se calcula cada término en todas las preguntas el tiempo no es suficiente. Sin embargo, como los valores de $A$ y $B$ son siempre los mismos, es posible calcular la serie completa una vez, memorizarla y posteriormente contestar las preguntas a partir de los datos memorizados.

Un posible código para esta subtarea es el siguiente:

```
int main()
{
    cin >> q;
    while(q--){
        cin >> a >> b >> t;

        if (!s[1]){
            s[1] = a;
            s[2] = b;
            for (int c = 3; c < MAX_N; c++) s[c] = (s[c - 1] + s[c - 2]) % MOD;
        }

        cout << s[t] << nl;
    }

    return 0;
}
```

Este código también puede resolver la subtarea 2, ya que al ser sólo una pregunta, se cumple que el valor de $A$ y $B$ no cambia.

## Subtarea 4, $P, i \leq 1000$ (30 puntos).

Al igual que en las subtareas 1 y 2, es posible ver que la cantidad máxima de sumas que se requieren para contestar una pregunta son $1000$ y que al haber $1000$ preguntas, el máximo de operaciones necesarias será de $10^6$ que corre en el tiempo del problema.

Para esta subtarea se puede utilizar el mismo código que para las tareas 1 y 2.

## Subtarea 5, sin restricciones (40 puntos).

Llamemos $M_i$ al _i-ésimo_ término de la _serie de Marconacci_. Si se escriben los términos de la serie en función de $A$ y $B$ se obtiene lo siguiente:

- $M_1 = A$
- $M_2 = B$
- $M_3 = A + B$
- $M_4 = (A + B) + B = A + 2B$
- $M_5 = (A + 2B) + (A + B) = 2A + 3B$
- $M_6 = (2A + 3B) + (A + 2B) = 3A + 5B$
- ...

Si se observan los coeficientes de $A$ a partir de $M_3$ podemos ver que son $1, 1, 2, 3, 5, 8, ...$ los términos de la _serie de Fibonacci_.

Igualmente los coeficientes de $B$ a partir de $M_2$ son $1, 1, 2, 3, 5, 8, ...$, nuevamente los términos de _Fibonacci_.

En general, es posible ver que $M_i = F_{i - 2} * A + F_{i - 1} * B$ por lo que para obtener los puntos de esta subtarea era necesario precalcular los números de la _serie de Fibonacci_ y usarlos, en cada pregunta, para calcular el término de la _serie de Marconacci_.

Un posible código para obtener los $100$ puntos es el siguiente:

```
int main()
{
    f[1] = f[2] = 1;
    rep(i, 3, MAX_N - 1) f[i] = (f[i - 1] + f[i - 2]) % MOD;

    cin >> q;
    while(q--){
        cin >> a >> b >> t;

        if (t == 1) cout << a << nl;
        else if (t == 2) cout << b << nl;
        else {
            t = (((a * f[t - 2]) % MOD) + ((b * f[t - 1]) % MOD)) % MOD;
            cout << t << nl;
        }
    }

    return 0;
}
```
