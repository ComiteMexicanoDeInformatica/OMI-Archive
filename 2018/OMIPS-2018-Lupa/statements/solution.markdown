El problema se resume en conocer los dígitos de un número y colocarlos en su lugar correspondiente
(unidades, decenas si tiene y centenas si tiene). Para obtener los primeros 20 puntos puedes checar
si la cantidad de zumbadores es un número entre 0 y 9 (contándolos con parámetros y usando las funciones iszero() y pred()),
tomar zumbadores suficientes del montoncito infinito para poder colocar el número, y teniendo una
función para poner cada dígito, dibujarlo en el mundo y apagarte.

Para los siguientes casos, siendo $x$ la cantidad de zumbadores en la mochila originalmente,
hay que hacer dos observaciones:

1. Una manera de saber el dígito de las unidades de $x$ es calcular $x$ módulo 10 y eso lo obtienes
tratando de tomar 10 zumbadores siempre que puedas y cuando no puedas,
el número que queda es el dígito de las unidades.
2. Como resultado de lo anterior, $x$ queda como el número original pero con el dígito de las unidades igual a 0, 
por lo que dividiéndolo entre 10 se podría quitar el 0. Eso lo logras haciendo una
función que tome de diez en diez y que cuente con parámetro cuántas veces se pudo hacer y al final colocar ese número.
En el caso que $x$ originalmente era un número de dos dígitos, entonces ya tienes el dígito de las decenas, de lo contrario 
el número que queda es de dos dígitos y son el dígito de las centenas y decenas de $x$ original, por lo que puedes repetir (1) y (2) para obtener estos dígitos. 