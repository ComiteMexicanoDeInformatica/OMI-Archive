# Solución Pegadito

La solución esperada para este problema involucraba búsquedas. Podemos darnos cuenta de que no es posible resolver el problema con una sola búsqueda, pues necesitaríamos marcar dos tipos de casillas: las que están junto a una pared con 1 zumbador, y las que no están junto a una pared con 0 zumbadores; pero una casilla con 0 zumbadores indica una casilla no visitada, así que no podríamos distinguir entre casillas que no hemos visitado y casillas que ya visitamos pero no están junto a una pared.

Supongamos entonces que inicialmente todo el mundo está coloreado con montones de 2 zumbadores y hagamos una búsqueda en este mapa. En esa búsqueda las casillas que aún no se visitan son las que tienen 2 zumbadores, y las casillas visitadas las marcaremos de dos formas: visitaremos con 1 zumbador las que estén junto a una pared, y con 0 zumbadores las casillas que no están junto a una pared.

El código de la búsqueda quedaría así:

```
void paredes(){
	if(nextToABeeper){
		pickbeeper();
		if(nextToABeeper){
			pickbeeper();
			iterate(4){
				if(frontIsBlocked && notNextToABeeper){
					putbeeper();
				}
				turnleft();
			}
			norte();
			if(frontIsClear){
				move();
				paredes();
				sur();
				move();
			}
			este();
			if(frontIsClear){
				move();
				paredes();
				oeste();
				move();
			}
			oeste();
			if(frontIsClear){
				move();
				paredes();
				este();
				move();
			}
			sur();
			if(frontIsClear){
				move();
				paredes();
				norte();
				move();
			}
		} else {
			putbeeper();
		}
	}
}
```

La búsqueda primero verifica que Karel se encuentre en una casilla no visitada (para esto comprueba que esté en una casilla con dos zumbadores), si esto pasa entonces visita la casilla. Para visitar la casilla primero verifica si está junto a una pared, de ser así la visita con 1 zumbador, si no, la deja con 0 zumbadores. Por último la búsqueda intenta moverse a sus casillas adyacentes.

Así, la solución completa primera colorea todo el mapa con montones de 2 zumbadores, y luego hace la búsqueda que describimos arriba para dejar con 1 zumbador sólo las casillas que están junto a una pared.
