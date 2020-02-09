# Navegante.

![Entrada](1.png)

La observación clave para este problema es que no importa el orden en que Karel se mueve (ni los movimientos del viento que mueven a Karel, ni los movimientos que Karel decide hacer). Habiendo entendido esta observación podremos visualizar al problema de una forma distinta: dejar que el viento mueva a Karel durante $n$ dias, y al final, partiendo de la coordenada donde nos dejó el viento realizar $n$ movimientos para llegar a la coordenada destino.

A partir de ahora entenderemos como la coordenada $(xMarea,yMarea)$ a la coordenada a la que llegamos desde la coordenada $(xOrigen,yOrigen)$ si dejamos que el viento nos lleve durante $n$ dias sin que Karel realice ningún otro movimiento en cada día.

Dado que cada movimiento que decidamos hacer nos acercará una unidad más a la coordenada objetivo, Karel podrá llegar a la coordenada objetivo sí y solo sí la [distancia Manhattan][1] entre la coordenada $(xMarea,yMarea)$ y $(xObjetivo,yObjetivo)$ es menor o igual al **número de días**.

A partir de aquí podemos dividir el problema en sub-problemas más sencillos que en conjunto nos permitan resolver el problema completo.

## Contar la cantidad de dias.
Dado que necesitamos saber la cantidad de dias que el viento sopló para poder compararlo con la distancia Manhattan, necesitamos contar la cantidad de montones de zumbadores que aparecen en la primer fila del mundo.

Para el siguiente fragmento del código Karel inicia viendo hacia el Este en la casilla (1,1).

	define contar(n) {
		if(nextToABeeper && frontIsClear) {
			move();
			contar(succ(n));
		}
		else {
			if(frontIsClear)
				dejarBeepers(n);
			else
				dejarBeepers(succ(n));
		}
	}

De esta manera contaremos dejaremos la cantidad de montones de zumbadores que hay y lo dejaremos en en la casilla (3,2).

![Contar el numero de dias](2.png)

### Obtener la casilla $(xMarea,yMarea)$

Debemos mover la coordenada $(xOrigen,yOrigen)$ en cada una de las direcciones a las que sopla el viento para obtener la coordenada $(xMarea,yMarea)$. Para esto debemos sumar 1 al $xOrigen$ por cada montón de 3 zumbadores en la fila 1, restar 1 al $xOrigen$ por cada montón de 2 zumbadores, sumar 1 al $yOrigen$ por cada montón de un zumbador y restar 1 al $yOrigen$ por cada montón de 4 zumbadores.

Obsérvese que es posible que al estar restando y sumando estos valores es posible que las coordenadas se salgan del mundo de Karel, incluso a coordenadas negativas. Como en Karel no existen números negativos, podemos simular un desplazamiento negativo si en vez de restar 1 al $xOrigen$ sumamos 1 al $xDestino$ y así también para el $yOrigen$ y $yDestino$. Esta tarea podemos hacerla fácilmente utilizando recursión, guardando en cada paso la cantidad de zumbadores que tomó Karel para luego decidir la coordenada donde restará o sumará un zumbador.

	define marea() {
		//Caso base.
		if(notNextToABeeper) {
			backturn();
			while(frontIsClear)
				move();
			turnright();
			return();
		}
		//Saber cuántos zumbadores hay.
		while(nextToABeeper) {
			pickbeeper();
			turnleft();
		}
		if(facingNorth) {
			turnEast();
			if(frontIsClear)
				move();
			marea();
			move();
			turnright();
			move();
			putbeeper();
			backturn();
			move();
			turnleft();
			move();
			backturn();
		}
		else if(facingWest) {
			turnEast();
			if(frontIsClear)
				move();
			marea();
			move();
			if(nextToABeeper) {
				pickbeeper();
				backturn();
			}
			else {
				move();
				putbeeper();
				backturn();
				move();
			}
			move();
			backturn();
		}
		else if(facingSouth) {
			turnEast();
			if(frontIsClear)
				move();
			marea();
			move();
			turnright();
			move();
			if(nextToABeeper) {
				pickbeeper();
			}
			else {
				turnleft();
				move();
				putbeeper();
				backturn();
				move();
				turnleft();
			}
			backturn();
			move();
			turnleft();
			move();
			backturn();
		}
		else {
			turnEast();
			if(frontIsClear)
				move();
			marea();
			move();
			putbeeper();
			backturn();
			move();
			backturn();
		}
	}

De esta forma obtendremos la coordenada $(xMarea,yMarea)$ en las casillas $(1,2)$ y $(2,2)$

![Coordenada Marea](3.png)

### Obtener la distancia Manhattan.

La distancia Manhattan entre las coordenadas $(xMarea,yMarea)$ y $(xDestino,yDestino)$ se obtiene con la suma de las diferencias de $xDestino$ con $xMarea$ y $yDestino$ con $yMarea$, formalmente, $|xDestino-xMarea| + |yDestino-yMarea|$.

Podemos obtener la diferencia de 2 números utilizando este par de  funciones:

	define restar(n) {
		if(nextToABeeper && !iszero(n)) {
			pickbeeper();
			restar(pred(n));
		}
		else if(notNextToABeeper && !iszero(n)) {
			iterate(n)
				putbeeper();
		}
	}

	define diferencia(n) {
		if(nextToABeeper) {
			pickbeeper();
			diferencia(succ(n));
		}
		else {
			move();
			restar(n);
		}
	}

En la casilla (1,3) se encontrará la la diferencia entre $xMarea$ y $xDestino$, en la (2,3) la diferencia entre $yMarea$ y $yDestino$.

![Diferencias](4.png)

### Comparar la distancia Manhattan con el número de dias.

Finalmente debemos sumar las diferencias y comparar la cantidad con el número de dias.

![Distancia Manhattan](5.png)

Si la distancia es menor o igual al número de dias, Karel deberá voltear al Norte, de lo contrario, al Sur.

	define comparar(n) {
		if(nextToABeeper && !iszero(n)) {
			pickbeeper();
			comparar(pred(n));
		}
		else if(notNextToABeeper && !iszero(n))
			turnSouth();
		else
			turnNorth();
	}
![Salida](6.png)


  [1]: https://es.wikipedia.org/wiki/Geometr%C3%ADa_del_taxista
