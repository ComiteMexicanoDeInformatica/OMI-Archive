El problema se resume en conocer los d�gitos de un n�mero y colocarlos en su lugar correspondiente
(unidades, decenas si tiene y centenas si tiene). Para obtener los primeros 20 puntos puedes checar
si la cantidad de zumbadores es un n�mero entre 0 y 9 (cont�ndolos con par�metros y usando las funciones iszero() y pred()),
tomar zumbadores suficientes del montoncito infinito para poder colocar el n�mero, y teniendo una
funci�n para poner cada d�gito, dibujarlo en el mundo y apagarte.

Para los siguientes casos, siendo $x$ la cantidad de zumbadores en la mochila originalmente,
hay que hacer dos observaciones:

1. Una manera de saber el d�gito de las unidades de $x$ es calcular $x$ m�dulo 10 y eso lo obtienes
   tratando de tomar 10 zumbadores siempre que puedas y cuando no puedas,
   el n�mero que queda es el d�gito de las unidades.
2. Como resultado de lo anterior, $x$ queda como el n�mero original pero con el d�gito de las unidades igual a 0,
   por lo que dividi�ndolo entre 10 se podr�a quitar el 0. Eso lo logras haciendo una
   funci�n que tome de diez en diez y que cuente con par�metro cu�ntas veces se pudo hacer y al final colocar ese n�mero.
   En el caso que $x$ originalmente era un n�mero de dos d�gitos, entonces ya tienes el d�gito de las decenas, de lo contrario
   el n�mero que queda es de dos d�gitos y son el d�gito de las centenas y decenas de $x$ original, por lo que puedes repetir (1) y (2) para obtener estos d�gitos.
