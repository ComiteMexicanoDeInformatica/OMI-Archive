En tu visita a la Ciudad de México marcaste en un mapa los lugares de la ciudad que te gustaría visitar.

Tu mapa de la Ciudad de México es una cuadrícula de $N\times M$ casillas donde las casillas marcadas indican un posible lugar a visitar.

Desafortunadamente tienes poco tiempo y sólo puedes visitar $K$ lugares. Por la magnitud de la ciudad, el mapa es bastante grande y sólo te gustaría llevar un rectángulo (submapa) del mapa que tenga exactamente $K$ lugares a visitar.

Como aún no sabes qué $K$ lugares te gustaría visitar, quieres saber cuántas posibilidades de submapa rectangular podrías tener.

# Problema

Dado el mapa con los lugares a visitar marcados, tienes que calcular la cantidad de rectángulos distintos del mapa que tengan exactamente $K$ lugares a visitar.

# Entrada
Tres enteros: $N, M, K$; Seguidos de $N$ líneas con $M$ carácteres cada una: los carácteres pueden ser $0$ (no es un lugar a visitar) o $1$ (es un lugar que se puede visitar).

# Salida

Un entero que representa la cantidad de submapas rectangulares que contengan exactamente $k$ lugares a visitar.

# Ejemplo
||input
3 3 2
101
000
101
||output
8
||description
En el ejemplo se pueden obtener 8 rectángulos con exactamente 2 lugares para visitar. 

Por ejemplo, un posible rectángulo con 2 lugares para visitar es:  
101  
---  
---  

Otro rectángulo distinto con dos lugares para visitar sería:  
101  
000  
---  
||end

# Límites
 * $0\leq k \leq 6$
 * $1 \leq N,M \leq 1500$

# Subtareas
 * En el 20% de los casos $1 \leq N,M \leq 20$.
 * En el 80% restante no hay restricciones adicionales.
