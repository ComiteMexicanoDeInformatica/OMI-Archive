import random
import os
import itertools as it
from math import *

baseXML = """
<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="{length}" alto="{length}">
{beepers}
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
			<despliega tipo="UNIVERSO"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'
cases = 19
minLength = 2
maxLength = 100
randomLengths = [random.randint(minLength, maxLength) for i in range(cases)]

for i in range(cases):
    length = randomLengths[i]
    lista = list(range(1, length+1))
    randomColumns = random.sample(lista, len(lista))

    case = { 'beepers': [], 'length': length }

    caseName = '{}'.format(i+1)

    beepers = []

    for j in range(length):
        randomRow = random.randint(1, length)
        beepers.append((dict({'count': 1, 'x': randomColumns[j], 'y': randomRow})))
    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)
