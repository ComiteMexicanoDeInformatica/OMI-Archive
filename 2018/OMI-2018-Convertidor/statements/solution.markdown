Nos podemos dar cuenta que primero van todas las cadenas de longitud 1:

```A, B, C, ..., Z.```

Que en total son 26 cadenas.

Después vienen las cadenas de longitud 2:

```AA, AB, ..., AZ, BA, BB, ..., BZ, CA, ..., CZ, ..., ZA, ..., ZZ.```

Por cada A del lado izquierdo en su lado derecho aparecen las 26 letras. Lo mismo pasa para todas las letras,
por lo que el total de cadenas de longitud 2 es $26 \cdot 26$ = $26^2$. De esta forma, hasta el
momento llevamos $26 + 26^2$ cadenas.

Análogamente, hay $26^3$ cadenas diferentes de longitud 3, $26^4$ cadenas de longitud 4, ...,
$26^k$ cadenas de longitud $k$ en los cuales hay en total $26 + 26^2 + 26 ^3$ cadenas,
$26 + 26^2 + 26^3 + 26^4$ cadenas, ..., $26 + 26^2 + \cdots + 26^k$ cadenas, respectivamente.

De aquí, podemos observar que el valor decimal de una cadena de la forma `AAAA...AAA`
con $k$ `A`s es $26 + 26^2 + \cdots + 26^{k-1} + 1$ $=$ $1 \cdot 26^0 + 1 \cdot 26^1 + 1 \cdot 26^2 + \cdots + 1 \cdot 26^{k-1}$.

Si cambiamos la última `A` por una `B`, su valor decimal es $2 \cdot 26^0 + 1 \cdot 26^1 + 1 \cdot 26^2 + \cdots + 1 \cdot 26^{k-1}$.

Si de la cadena de puras `A`s, cambiamos la penúltima por una `B`, quedará de la forma `AAAA...ABA`, y su
valor decimal es $1 \cdot 26^0 + 1 \cdot 26^1 + 1 \cdot 26^2 + \cdots + 1 \cdot 26^{k-1} + 26$ $=$
$1 \cdot 26^0 + 2 \cdot 26^1 + 1 \cdot 26^2 + \cdots + 1 \cdot 26^{k-1}$ porque la última `A` pasó
por las 26 letras y después esa penúltima `A` se convirtió en `B`. Análogamente, si de la original cambiamos
la penúltima `A` por `C`, su valor decimal es $1 \cdot 26^0 + 3 \cdot 26^1 + 1 \cdot 26^2 + \cdots + 1 \cdot 26^{k-1}$.

Siguiendo esta idea, podemos concluir que si cambiamos la $m$ésima `A` de derecha a izquierda de la cadena de puras `A`s,
su valor decimal será $1 \cdot 26^0 + 1 \cdot 26^1 + 1 \cdot 26^2 + \cdots + v \cdot 26^{m-1} + \cdots + 1 \cdot 26^{k-1}$,
donde $v$ es su valor como si cada letra fuera un dígito: `A` = $1$ , `B` = $2$, ..., `Z` = $26$.

Con todo lo anterior, podemos decir que una cadena de la forma [$c_{k}$][$c_{k-1}$][$c_{k-2}$]$\ldots$[$c_2$][$c_1$]
tiene como valor decimal $v_{k} \cdot 26^{k-1} + v_{k-1} \cdot 26^{k-2} + \cdots + v_2 \cdot 26^1 + v_1 \cdot 26^0$,
donde $v_i$ depende de $c_i$.
