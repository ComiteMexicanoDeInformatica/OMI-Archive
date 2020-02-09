import random
import os
import itertools as it
from math import *

baseXML = """
<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="100" alto="100">
{beepers}
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="0">
			<despliega tipo="UNIVERSO"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'

cases = 10
minColumns = 2
maxColumns = 50
minRows = 1
maxRows = 75
randomRows = [random.randint(minRows, maxRows) for i in range(cases)]
randomRows.sort()

def crea_archivo(case, beepers, name):
    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)

def crea_ductos (rows, cols):
    beepers = []
    countHuachicoleados = random.randint(1, rows - 1)
    huachicoleados = random.sample(list(range(1, rows + 1)), countHuachicoleados)

    for j in range(rows):
        elementos = cols[j]

        left = random.randint(1, 50)

        if (j in huachicoleados):
            right = left + random.randint(5, 15)
        else:
            right = left + random.randint(0, 4)

        rangoDucto = list(range(left, right + 1))
        ducto = random.choices(rangoDucto, k = elementos)

        for x, elemento in enumerate(ducto, start=1):
            beepers.append((dict({'count': elemento, 'x': x, 'y': j+1})))

    return beepers

for i in range(cases):
    if (i == 0):
        #un caso que haya al menos un ducto de 100 elementos
        case = { 'beepers': [] }

        caseName = '{}'.format(cases+1)

        rows = 50
        randomColumns = [random.randint(minColumns, maxColumns) for i in range(rows-1)]
        shuffledColumns = random.sample(randomColumns + [100], rows)

        beepers = crea_ductos(rows, shuffledColumns)

        crea_archivo(case, beepers, caseName)

        #un caso con 100 ductos
        case = { 'beepers': [] }

        caseName = '{}'.format(cases+2)

        rows = 100
        randomColumns = [random.randint(minColumns, 10) for i in range(rows)]
        shuffledColumns = random.sample(randomColumns, rows)

        beepers = crea_ductos(rows, shuffledColumns)

        crea_archivo(case, beepers, caseName)

    case = { 'beepers': [] }

    caseName = '{}'.format(i+1)

    beepers = []

    rows = randomRows[i]
    randomColumns = [random.randint(minColumns, maxColumns) for i in range(rows)]
    shuffledColumns = random.sample(randomColumns, rows)

    beepers = crea_ductos(rows, shuffledColumns)

    crea_archivo(case, beepers, caseName)
