![Ilustración](ilustracion.jpeg)

Ozymandias es un gran rey. Él ama las pirámides, así que mandó a construir una gigantesca. Sin embargo, al ser un proyecto tan ambicioso, hubo fallas.

Algunos escalones no están completos, comprometiendo la estabilidad de la pirámide. Pero esto no será un impedimento para el gran rey.

Por eso te ordenó a ti, su ingeniero civil de confianza, que la completes.

La pirámide está hecha con paredes, y tú debes completar los espacios faltantes con zumbadores.

El mundo de Karel representa una pirámide incompleta. En todos los niveles de la pirámide hay al menos un bloque con material, es decir, puede faltar material en los extremos de un nivel, pero no puede haber huecos en medio. Además, el bloque en el extremo izquierdo del primer nivel debería ir siempre en la segunda columna de la primera fila.

## Ejemplos de pirámides válidas

![valida1](valida1.jpeg)

La pirámide tiene altura 5

![valida2](valida2.jpeg)

La pirámide tiene altura 1

![valida3](valida3.jpeg)

La pirámide tiene altura de 5

## Ejemplos de pirámides inválidas

![invalida1](invalida1.jpeg)

La pirámide tiene altura de 5, sin embargo, al completarla ésta no empezaría en la casilla (1,2). De igual forma habría un bloque con material extra en la casilla (1,10).

![invalida2](invalida2.jpeg)

En el último nivel de la pirámide no hay ningún bloque con material. Debería haber al menos 1.

![invalida3](invalida3.jpeg)

En la primer y tercer fila falta material de en medio.

![invalida4](invalida4.jpeg)

Hay bloques de material extra.

## Problema

Debes completar la pirámide con zumbadores. Ésta tiene que coincidir con la pirámide incompleta inicial.

## Entrada ejemplo

![ejemploentrada1](valida1.jpeg)

## Salida ejemplo

![ejemplosalida1](salida1.jpeg)

## Consideraciones

- Karel inicia orientado al norte en la casilla (1,1).
- La pirámide inicia en la casilla (1,2).
- Karel tiene zumbadores infinitos en la mochila.
- La altura máxima de la pirámide es de 90.
- No importa la posición ni orientación final de karel, solo la posición de los zumbadores.

## Subtareas

- 15 puntos. Sólo hace falta un bloque.
- 15 puntos. Sólo hay un nivel incompleto.
- 20 puntos. La pirámide será de altura 30 en todos los casos.
- 50 puntos. Sin consideraciones adicionales.
