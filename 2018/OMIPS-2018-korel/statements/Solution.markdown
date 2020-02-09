# Solución Primo Korel
En este problema , nos piden realizar un ciclo sencillo para 83 puntos. Los pasos serian.

1.- Agarra todos los zumbadores en donde te encuentras.
2.- Hacer un ciclo que mientras tengas beepers en la mochila busques una pared, cuando la encuentres pongas un beeper y dobles a la derecha, en java se ve asi:

    while(anyBeepersInBeeperBag)
    {
    while(frontIsClear)
    move();
    putbeeper();
    turnleft();
    }
Para la solución de 100 puntos es necesario hacer uso de la recursión. En nuestra función ,si estamos sobre un beeper , tomamos el beeper y mandamos llamar a nuestra función. Depués , hacemos el mismo ciclo que arriba:

    define recursion()
    {
    if(nextToABeeper)
    {
    pickbeeper();
    recursion();
    while(frontIsClear)
    move();
    putbeeper();
    turnleft();
    }
    }


