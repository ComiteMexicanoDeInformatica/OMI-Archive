# Cómo Colaborar

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

El flujo de trabajo para hacer un problema es _estrictamente_
el siguiente. En todos los casos, se debe hacer un branch y posteriormente
un pull request conteniendo una unidad de trabajo. Es importante no
mezclar trabajo de distintos problemas en el mismo branch o pull request.

## 1. Especificación del problema

Se escribe en el `es.markdown`, pero no es la redacción final. Debe contener:

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
- El primer caso de ejemplo que se vaya a incluir en la redacción debe ir en
  `examples/sample.in` y `examples/sample.out`. Todos los demás casos de
  ejemplo deben ir en `examples/` con nombres que indiquen a qué se refiere.
  Luego, para incluirlos en la redacción, se puede usar la siguiente sintaxis:

  ```markdown
  ||examplefile
  sample
  ||description
  Aquí va la descripción del caso de ejemplo. Nota que arriba no se usó el
  nombre del directorio `examples/` ni la extensión de los archivos.
  ||examplefile
  caso_mas_grande
  ||examplefile
  caso_mas_complicado
  ||description
  No es necesario agregar una descripción en cada caso, pero se recomienda que
  se haga.
  ||end
  ```

## 2. Pruebas (`tests/`)

- Escribir pruebas que verifiquen los casos de prueba.
- En el caso de Karel, revisar **todas** las condiciones del problema y
  tener cuidado de que el `.in` contenga las condiciones de evaluación
  correctas para el problema.
- Para C++, el evaluador debe checar que la entrada sea válida y que sigue
  _exactamente_ el formato descrito, cuidando en particular los espacios en
  blanco y saltos de línea.
- Las pruebas tienen que considerar los límites especiales que pueden
  existir para las distintas subtareas. Esto se logra dándole nombres de
  archivo a los casos conteniendo el identificador de su subtarea, para
  poder distinguir a qué subtarea pertenecen.
  [Aquí hay un ejemplo.](https://github.com/ComiteMexicanoDeInformatica/OMI-2018/tree/master/omi/Convertidor)
- En este punto se agrega el `settings.json` y el problema a
  `problems.json`. El alias del problema **no** se determina hasta que se
  escribe la redacción final. Puedes usar el alias temporal `dummy-omi`
  mientras tanto.
- Crear un archivo `tests/tests.json` indicando qué validador se usará para
  los casos de prueba. El archivo lleva este contenido:
  ```json
  {
    "solutions": [],
    "inputs": {
      "filename": "[validador].[lang]"
    }
  }
  ```
- A partir de aquí, los pull requests deben pasar las pruebas automáticas para
  poder ser integrados.

  Tanto para Karel como para C++ hay bibliotecas que simplifican el trabajo:
  revisa ejemplos de otros problemas de OMIs anteriores para ver cómo usarlas.

## 3. Solución oficial

- La solución oficial debe guardarse en la ruta `solutions/solution.[lang]`.
  Cuando esté lista la solución oficial, se puede trabajar tanto en soluciones
  como en casos al mismo tiempo.
- Agrega la solucion a `tests/tests.json`:
  ```json
  {
    "solutions": [
      {
        "filename": "../solutions/solution.[lang]",
        "verdict": "AC"
      }
    ],
    "inputs": {
      "filename": "[validador].[lang]"
    }
  }
  ```
- Si la solución oficial se puede usar para auto-generar las salidas de los
  casos (los `.out`), puedes borrar todos los archivos `.out` del problema y
  después agregar un archivo llamado `.gitignore` en la raíz del problema con
  el contenido:
  ```
  **/*.out
  # Si el problema es de Karel, también son necesarias las siguientes tres
  # líneas:
  cases/*.png
  examples/sample.*.png
  statements/sample.*.png
  ```

## 4. Otras soluciones (`solutions`)

- Agrega tu solución en `solutions/[sol].[lang]`, así como en
  `tests/tests.json`, con el veredicto o puntaje esperado.
  Para soluciones parciales en lugar de `verdict` debes agregar `score_range`
  con el rango de puntos (entre 0 y 1) que esperas para esa solución. Si es
  un score definido, pon el mismo score en las dos posiciones. Por ejemplo,
  si tienes una solución que esperas que dé 20 puntos, debes agregar:
  ```json
  "solutions": [
    {
      "filename": "../solutions/[partial].[lang]",
      "score_range": [0.2, 0.2]
    }
  ]
  ```

## 5. Casos (`cases`)

- Escribe casos ya sea manualmente o autogenerados, siguiendo la especificación
  de la entrada. No olvides agruparlos de ser necesario, y si hay subtareas, de
  incluir en su nombre el identificador de la subtarea.
- En caso de que los `.in` de tus casos sean autogenerados, incluye el código
  que los generó en la raíz del problema, con el nombre
  `case-generator.[lang]`.
- Si la solución oficial no se puede utilizar para auto-generar los archivos
  `.out`, hay que generarlos manualmente y agregarlos:
  - Los problemas que tienen un validador personalizado pueden tener `.out`
    vacíos si el validador no necesita información más allá del `.in` original
    y la salida del concursante para generar el veredicto. También se puede
    poner información en el `.out` que le puede ayudar al validador. Por
    ejemplo, la cota superior / inferior conocida de lo que se desea optimizar.
  - Para los problemas interactivos, como el `Main.[lang]` típicamente hace las
    veces del validador, la misma información aplica.
  - Si generar los archivos `.out` toma mucho tiempo o es necesario generarlos
    a mano por cualquier razón, hay que agregar el código que los generó en la
    raíz del problema, con el nombre `output-generator.[lang]`.
- Haz un `testplan` para tus casos. No puede tener puntos decimales y
  necesariamente debe sumar 100.
- Si es un problema de Karel, agrega las soluciones malas
  (`default_bad_solutions`) a `tests/tests.json`, para asegurarte de que tus
  casos les dan 0 puntos.
- Si es un problema con más de una salida válida, agrega en la raiz el
  `validator.[lang]` y cambia en `settings.json` la sección de `validator`:
  ```json
  "validator": {
    "name": "custom",
    "limits": {
      "TimeLimit": 1000
    }
  }
  ```
- Si es un problema interactivo, pueden consultar la [documentación de
  libinteractive](https://omegaup.com/libinteractive/es/writing/) y usar el
  problema
  [`OMI-2019-Mobius`](https://github.com/ComiteMexicanoDeInformatica/OMI-Archive/tree/master/2019/OMI-2019-Mobius)
  como plantilla para empezar. Lo importante es tener la carpeta `interactive/`
  con un archivo `[ModuleName].idl`, un archivo `Main.cpp` con el programa juez
  oficial y un archivo `Main.distrib.cpp` que es el programa juez que se va a
  compartir con los concursantes (por si el juez oficial tiene secretos, o
  pistas de cómo se resuelve el problema). También hay que cambiar en
  `settings.json` la sección de `interactive`:
  ```json
  "interactive": {
    "ModuleName": "[ModuleName]"
  }
  ```

## 6. Redacción (`statements/es.markdown`)

- Se escribe la redacción final del problema.
- Asegurarse de que los casos de ejemplo (`examples/sample.{in,out}`, etc.)
  existen y se están usando con la sintaxis `||examplefile` en la redacción.
  - Si hay solución oficial y esta puede generar el `.out`, no hace falta el
    `.out`.
- Para Karel, hacer un symlink de `statements/sample.{in,out}` hacia
  `examples/sample.{in,out}`. El sistema de build rehace las imágenes de
  ejemplo basado en esos archivos: hay que borrar las imágenes generadas
  manualmente y cambiar el `es.markdown` para que use las nuevas imágenes (e.g.
  `sample.in.png`). Si hay varios casos de ejemplo, deben estar tanto en
  `examples` como en `statements`.

  Si es necesario recortar la imagen porque el mundo es muy grande, el symlink
  puede llamarse `sample.RxC.in`, donde `R` y `C` son la cantidad de filas y
  columnas a dibujarse, respectivamente.

## 7. Explicación (`solutions/es.markdown`)

- Hacer un documento que explique la solución oficial.
  - Si existen soluciones parciales para subtareas, también hay que
    explicarlas.
- Listar las observaciones importantes para poder atacar el problema.
- Para embeber soluciones en la explicación, se puede usar la siguiente
  sintaxis (asumiendo que la solución existe en el archivo
  `solutions/subtarea_1.cpp`):

  ```markdown
  <details><summary>Solución para la subtarea fácil (~4 puntos)</summary>

  {{subtarea_1.cpp}}

  </details>
  ```

- Enfocarse en dar valor didáctico y si el problema es un tema conocido
  explicar dónde se puede aprender mas sobre este.

# Convenciones

- A menos de que la solución oficial no pueda usarse para generar las salidas
  (ver la sección de [Casos (`cases/`)](#5-casos-cases), sólamente se hace
  commit a las entradas de los casos de prueba (`.in`). Los `.out` se generan
  automáticamente con la solución oficial.
- Cuando hay casos agrupados, el primer caso en el `testplan` debe tener el
  valor entero del grupo, y todos los demás 0. Por ejemplo:

  ```
  group.1 40
  group.2 0
  group.3 0
  ```

- Los tests tienen que tener comentarios explicando qué condiciones están
  evaluando de la entrada.
- En Karel, utilizar acentos (`algún-zumbador-en-la-mochila`,
  `inicia-ejecución`) y `si-no` en vez de `sino`.
- Las dimensiones del mundo de Karel deben ser justas para que quepa la parte
  accesible por Karel. Es decir, no basta con poner paredes en un área pequeña
  si el mundo sigue siendo de 100x100. El `.in` debe reflejar el tamaño real
  de la parte del mundo que Karel puede visitar. (`kareltest` tiene la rutina
  `assertTightWorldSize()` para verificar esta condición.)
- Todos los archivos de texto deben de estar en encoding UTF-8, con fin de
  línea estilo UNIX (`\n` o `LF`, nunca `\r\n` o `CRLF`).
- Debes correr el linter antes de mandar un PR para asegurarnos que el estilo
  sea consistente y fácil de leer. Para correrlo localmente puedes ejecutar:

  ```shell
  ./utils/lint fix --all
  ```

# Cómo Correr los Tests Localmente

Cambiar el directorio a la raíz del proyecto.

La primera vez necesitas bajar el submódulo de utilidades para omegaUp:

```shell
git submodule init && git submodule update
```

Instala Python 3, [pipenv](https://github.com/pypa/pipenv), y la versión más
reciente de [Docker](https://docs.docker.com/get-docker/).

Después, corre

```shell
./utils/lint fix --all
cd utils
pipenv install
pipenv run python3 runtests.py --all
```
