Anoche te desvelaste instalando una red de $N$ computadoras (numeradas de $1$ a $N$). El día de hoy, al llegar a tu trabajo, te informaron que un virus de computadora se propagó por la red y tuvieron que apagar todas las computadoras de emergencia.

Tu jefe te está pidiendo que le des un estimado del daño, es decir, que le digas ¿cuál es el mínimo y el máximo de computadoras que pueden estar infectactas?.

Como las computadoras están apagadas no puedes revisarlas, pero por suerte tienes la bitácora del switch de red. Esta bitácora te indica los mensajes que se intercambiaron entre las computadoras de la red.

En total se intercambiaron $M$ mensajes antes de que apagaran las computadoras. El _i-ésimo_ mensaje fue de la computadora $a_i$ a la computadora $b_i$. Sabes que si una computadora infectada mandó un mensaje a una computadora no infectada, la computadora receptora queda infectada. El switch te dice todos los mensajes que se transmitieron, pero no te indica el orden en que sucedieron.

Finalmente, después de un poco de ingeniería social descubres que el virus venía en un correo el cual fue abierto por $K$ personas, por lo que conoces cuáles fueron las $K$ computadoras que iniciaron infectadas.

Ahora ya tienes todo para poder contestar la pregunta de tu jefe.

# Problema

Escribe un programa que dadas las $K$ computadoras inicialmente infectadas y los $M$ mensajes que se transmitieron en la red determine ¿cuál es el número mínimo y el número máximo de computadoras que pueden estar infectadas?

# Entrada

- En la primera línea los números $N$, $M$ y $K$. La cantidad total de computadoras, de mensajes intercambiados y de computadoras inicialmente infectadas.
- En la segunda línea hay $K$ números que representan las computadoras inicialmente infectadas.
- En las últimas $M$ líneas hay dos números, $a_i$ y $b_i$ que representan el _i-ésimo_ mensaje. **Recuerda que los mensajes en la bitácora no vienen en el orden en que sucedieron.**

# Salida

- Una línea con dos números separados por espacio que representen el mínimo y el máximo de computadoras que pueden estar infectadas.

# Ejemplo

||input
4 6 1
1
1 2
2 4
3 2
1 3
3 4
4 1
||output
3 4
||description
Originalmente sólo la computadora $1$ está infectada.

Si los mensajes suceden en este orden:

- $2 \to 4$ Como $2$ no está infectada, no pasa nada
- $1 \to 2$ Se infecta la computadora $2$ (van dos computadoras infectadas)
- $3 \to 4$ Como $3$ no está infectada, no pasa nada
- $1 \to 3$ Se infecta la computadora $3$ (van tres computadoras infectadas)
- $3 \to 2$ Ambas están infectadas, no pasa nada
- $4 \to 1$ Aunque $1$ está infectada, a $4$ no le pasa nada.

En total se infectan tres computadoras $1$, $2$ y $3$. Este es el mínimo posible para esta configuración.

El máximo, cuatro computadoras, puede obtenerse si los mensajes transcurren en el siguiente orden:

$3 \to 4$, $3 \to 2$, $1 \to 2$, $2 \to 4$, $1 \to 3$, $4 \to 1$
||end

# Límites

- $1 \leq N, M \leq 10^5$
- $1 \leq a_i, b_i \leq N$

# Evaluación

Para cada subtarea tu programa se evaluará de la siguiente forma:

- Si tu programa escribe correctamente el número mínimo de computadoras infectadas, obtendrás **40% puntos**.
- Si tu programa escribe correctamente el número máximo de computadoras infectadas, obtendrás **60% puntos**.

# Subtareas

- **(40 puntos)**: Sólo hay una computadora infectada y es la computadora $1$.
- **(8 puntos)**: $N \leq 3$
- **(12 puntos)**: $M \leq 10$
- **(20 puntos)**: $a_i < b_i$ para todos los mensajes
- **(20 puntos)**: Sin restricciones adicionales
