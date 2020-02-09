# Repositorio oficial de problemas de la OMI

Este repositorio sirve como archivo oficial con con redacciones, casos, soluciones y explicaciones de los problemas usados en competencias nacionales de la Olimpiada Mexicana de Informática.

Todo este material didáctico se distribuye libremente para que los maestros y alumnos se preparen para futuras competencias.

Estos problemas están disponibles en [omegaUp](https://omegaup.com/), el sistema de evaluación oficial de la OMI. Para que los alumnos puedan intentarlos.

Si detectas algun problema puedes [reportar el problema](https://github.com/ComiteMexicanoDeInformatica/OMI-Archive/issues) o mandar un [PR](https://github.com/ComiteMexicanoDeInformatica/OMI-Archive/pulls) con la corrección.

Cualquier cambio aquí aprobado actualizará automáticamente el problema en omegaUp.

## Cómo Colaborar

Prerrequisitos:
- [Saber hacer problemas para omegaUp.](https://github.com/omegaup/omegaup/wiki/C%C3%B3mo-escribir-problemas-para-omegaUp)
- Saber usar git, y conocimiento básico de Python y C++.

Usamos git para coordinar el trabajo, así como pruebas automáticas
que revisan que los problemas tienen entradas válidas y que las
soluciones de prueba sacan los puntos que esperamos. Todo se coordina
con el archivo `problems.json` en la raíz del proyecto, y los
archivos individuales `settings.json` en las carpetas de los problemas.

La descripción del formato de estos archivos y la organización de las carpetas
está en
[este documento](https://docs.google.com/document/d/1OKOIdPMv3BasGZXqVmtVBWVIATrPfyPUbK8qXjXPwGU/edit).
Te recomendamos leerlo **después** de leer este archivo.

El flujo de trabajo para hacer un problema es *estrictamente*
el siguiente. En todos los casos, se debe hacer un branch y posteriormente
un pull request conteniendo una unidad de trabajo. Es importante no
mezclar trabajo de distintos problemas en el mismo branch o pull request.

1. Especificación del problema. Se escribe en el `es.markdown`,
   pero no es la redacción final. Debe contener:
  - Descripción corta del problema. (Sin historia)
  - Descripción del formato de entrada y salida.
  - Para Karel, ser muy específico con las dos anteriores
    (e.g. Karel empieza viendo al norte, Karel empieza en la casilla (1,1)).
  - Descripción de las subtareas, de haber. Cada subtarea tiene que
    tener un identificador único que las distinga. (Más detalles
    en la sección de pruebas.)
  - Agrega por lo menos un caso de prueba válido
    (el de ejemplo, probablemente) en `cases/0.in` y `cases/0.out`. Agrega
    un `testplan` que contenga solamente ese caso y obtenga 100 puntos.
2. Pruebas. (`tests`)
  - Escribir pruebas que verifiquen los casos de prueba.
  - En el caso de Karel, revisar **todas** las condiciones del problema y
    tener cuidado de que el `.in` contenga las condiciones de evaluación
    correctas para el problema.
  - Para C++, el evaluador debe checar que la entrada sea válida y que
    sigue *exactamente* el formato descrito, cuidando en particular los
    espacios en blanco y saltos de línea.
  - Las pruebas tienen que considerar los límites especiales que pueden existir
    para las distintas subtareas. Esto se logra dándole nombres de archivo
    a los casos conteniendo el identificador de su subtarea,
    para poder distinguir a qué subtarea pertenecen.
    [Aquí hay un ejemplo.](https://github.com/ComiteMexicanoDeInformatica/OMI-2018/tree/master/omi/Convertidor)
  - En este punto se agrega el `settings.json` y el problema a `problems.json`.
    El alias del problema **no** se determina hasta que se escribe la redacción
    final. Puedes usar el alias temporal `dummy-omi` mientras tanto.
  - A partir de aquí, los pull requests deben pasar las pruebas automáticas
    para poder ser integrados.
  Tanto para Karel como para C++ hay bibliotecas que simplifican el trabajo:
  revisa ejemplos de otros problemas de OMIs anteriores para ver cómo usarlas.
3. Soluciones. (`tests/solutions`)
  - Agrega tu solución en `tests/solutions/[sol].[lang]`, así como
    en `tests/tests.json`, con el veredicto o puntaje esperado.
  - La solución modelo (i.e. la que se usa para generar los `.out`)
    además debe venir como un symlink de `generator.[lang]` en la
    raíz del problema hacia `tests/solutions/[sol].[lang]`. Cuando
    esté lista la solución modelo, se puede trabajar tanto en soluciones
    como en casos al mismo tiempo.
  - No olvides borrar `0.out` cuando ya esté lista la solución modelo.
4. Casos. (`cases`)
  - Escribe casos ya sea manualmente o autogenerados, siguiendo la
    especificación de la entrada. No olvides agruparlos de ser necesario,
    y si hay subtareas, de incluir en su nombre el identificador de la
    subtarea.
  - En caso de que tus casos sean autogenerados, incluye el código que los
    generó en la raíz del problema, con el nombre `case-generator.[lang]`.
  - Haz un `testplan` para tus casos. No puede tener puntos decimales y
    necesariamente debe sumar 100.
  - Si es un problema de Karel, agrega las soluciones malas
    (`default_bad_solutions`) a `tests/tests.json`, para asegurarte de
    que tus casos les dan 0 puntos.
  - Si es un problema con más de una salida válida, agrega aquí el `validator.[lang]`.
5. Redacción. (`statements/es.markdown`)
  - Se escribe la redacción final del problema.
  - Asegurarse de que los casos de ejemplo (`examples/sample.{in,out}`)
    existen. (Si hay solución modelo, no hace falta el `.out`.)
  - Para Karel, hacer un symlink de `statements/sample.{in,out}` hacia
    `examples/sample.{in,out}`. El sistema de build rehace las imágenes
    de ejemplo basado en esos archivos: hay que borrar las imágenes generadas
    manualmente y cambiar el `es.markdown` para que use las nuevas imágenes
    (e.g. `sample.in.png`). Si hay varios casos de ejemplo, deben estar tanto
    en `examples` como en `statements`.

    Si es necesario recortar la imagen porque el mundo es muy grande, el
    symlink puede llamarse `sample.RxC.in`, donde R y C son la cantidad de
    filas y columnas a dibujarse, respectivamente.
6. Explicación (`solutions/es.markdown`)
  - Hacer un documento que explique la solución oficial.
  - Listar las observaciones importantes para poder atacar el problema.
  - Enfocarse en dar valor didáctico y si el problema es un tema conocido explicar dónde se puede aprender mas sobre este.

## Convenciones

* A menos de que las salidas sean difíciles de generar por alguna
  razón, solamente se hace commit a las entradas de los casos
  de prueba (`.in`). Los `.out` se generan automáticamente con el
  `generator.[lang]`.
* Cuando hay casos agrupados, el primer caso en el `testplan` debe
  tener el valor entero del grupo, y todos los demás 0. Por ejemplo:
```
group.1 40
group.2 0
group.3 0
```
* Los tests tienen que tener comentarios explicando qué condiciones
  están evaluando de la entrada. (Ver tests de `omips-online/arcoiris`.)
* En Karel, utilizar acentos (`algún-zumbador-en-la-mochila`, `inicia-ejecución`)
  y `si-no` en vez de `sino`.
* Las dimensiones del mundo de Karel deben ser justas para que
  quepa la parte accesible por Karel. Es decir, no basta con
  poner paredes en un área pequeña si el mundo sigue siendo de 100x100,
  sino que el `.in` debe reflejar el tamaño real de la parte del mundo
  que Karel puede visitar.
* Todos los archivos de texto deben de estar en encoding UTF-8.

## Cómo Correr los Tests Localmente

Cambiar el directorio a la raíz del proyecto.

La primera vez necesitas bajar el submódulo de
utilidades para omegaUp:

```bash
  git submodule init && git submodule update
```

Instala Python 3, [pipenv](https://github.com/pypa/pipenv),
y la versión más reciente de [Karel.js](https://github.com/omegaup/karel.js).
Después, corre

```bash
cd utils
pipenv install
pipenv run python3 generateouts.py --force
pipenv run python3 runtests.py --all
```
