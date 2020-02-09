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
			<posicionDump x="1" y="1"></posicionDump>
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
			<despliega tipo="MUNDO"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'

cases = 15
minColumns = 3
maxColumns = 90
minRows = 3
maxRows = 100
randomColumns = [random.randint(minColumns, maxColumns) for i in range(cases)]
randomRows = [random.randint(minRows, maxRows) for i in range(cases)]
randomColumns.sort()
randomRows.sort()

for i in range(cases):
    rows = randomRows[i]
    cols = randomColumns[i]

    lista = list(range(1, 100))

    case = { 'beepers': [] }

    caseName = '{}'.format(i+1)

    beepers = []

    patron = random.sample(lista, rows - 1)
    intrusos = {x: 0 for x in list(set(lista).symmetric_difference(patron))}

    for j in range(2, cols+2):
        intruso = random.choice(list(intrusos.keys()))

        while intrusos[intruso] == cols - 1:
            intruso = random.choice(list(intrusos.keys()))

        intrusos[intruso] += 1


        shuffledPattern = random.sample(patron + [intruso], len(patron) + 1)

        if i < 5:
            shuffledPattern.sort()

        for row, k in enumerate(shuffledPattern, start=1):
            beepers.append((dict({'count': k, 'x': j, 'y': row})))

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)
