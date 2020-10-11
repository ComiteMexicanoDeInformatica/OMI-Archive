Primero consideremos qué significa que un camino no lleve a Karel a casa. Como sugiere el caso de
ejemplo, resulta que la única forma de que un camino no se salga del mapa es si sus instrucciones
harían que Karel se ciclara.

Dada esta observación, podemos separar el problema en dos tareas principales: determinar si el
camino que está marcado donde está parado Karel lo llevaría a un ciclo, y borrar el camino si ese
es el caso.

Para saber si un camino lleva a Karel en un ciclo basta con seguir las instrucciones recursivamente,
cuidando dejar vacías las casillas que están en la pila de la recursión, de tal manera que si
llegamos a una casilla vacía en nuestro recorrido podamos saber que las instrucciones nos llevarían
a un ciclo.

Si durante la recursión nos topamos con una pared, entonces podemos restaurar los zumbadores que
retiramos al avanzar, porque los tenemos recordados en la pila. Sin embargo, si no llegáramos a una
pared necesitamos una manera de indicar que no hay que restaurar los zumbadores al regresar de
las llamadas recursivas.

Para eso podemos usar una técnica muy útil: utilizar la orientación de Karel como el "valor de
regreso" de una función. Por ejemplo, podemos orientar a Karel al sur si sí queremos restaurar
los zumbadores, y al norte si no.

Por último, hay que repetir esta búsqueda recursiva en cada una de las casillas del mundo.
(¿Por qué funciona esto? ¿Qué pasa si Karel se encuentra una casilla que se dejó vacía en una
búsqueda recursiva anterior?)

El siguiente código implementa la solución anterior.

```
class program {
	void turnright() {
		turnleft();
		turnleft();
		turnleft();
	}

	void bump() { while (frontIsClear) move(); }
	void turn() { turnleft(); turnleft(); }

	void north() { while (notFacingNorth) turnleft(); }
	void south() { while (notFacingSouth) turnleft(); }

	void countAndStep(n){
		if (nextToABeeper){
			pickbeeper();

			countAndStep(succ(n));

			if (facingSouth) putbeeper();
		} else {
			north();
			iterate (pred(n)) turnleft();

			if (frontIsBlocked) {
				south();
				return();
			}

			move();
			go();

			if (facingSouth){
				iterate (pred(n)) turnleft();
				move();

				south();
			} else {
				south();

				iterate (pred(n)) turnleft();
				move();

				north();
			}
		}
	}

	void go(){
		if (notNextToABeeper){
			north();
			return();
		}

		countAndStep(0);
	}

	program () {
		while (iszero(0)){
			go();
			north();

			if (frontIsClear){
				move();
			} else if (rightIsClear){
				turnright();
				move();
				turnright();
				bump();
				turn();
			} else turnoff();
		}
	}
}
```
