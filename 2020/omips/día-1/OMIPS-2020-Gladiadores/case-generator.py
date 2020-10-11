import random
import os
import itertools as it
from math import *

def minCase(name, w,h,aZ,bZ):
    beepers = []
    dump = []
    case = { 'beepers': [], 'dump': [], 'height': h, 'width': w }

    caseName = '{}'.format(name)

    beepers.append((dict({'count': aZ, 'x': 1, 'y': 2})))
    beepers.append((dict({'count': bZ, 'x': 5, 'y': 2})))
    dump.append((dict({'x': 3, 'y': 2})))
    dump.append((dict({'x': 1, 'y': 1})))

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)
    case['dump'] = "\n".join(dumpTag.format(**d) for d in dump)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)

baseXML = """
<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="{width}" alto="{height}">
{beepers}
{dump}
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="0">
			<despliega tipo="MUNDO"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'
dumpTag = '\t\t\t<posicionDump x="{x}" y="{y}"></posicionDump>'
cases = 24
minWidth = 2
maxWidth = 49
minHeight = 2
maxHeight = 100
minStrength = 3
maxStrength = 50
randomWidths = [2 * random.randint(minWidth, maxWidth) + 1 for i in range(cases)]
randomHeights = [random.randint(minHeight, maxHeight) for i in range(cases)]

w = 5
h = 2

#Caso más pequeño. Empatan.
minCase(1,w,h,3,3)

#Caso más pequeño. Gana equipo A.
minCase(2,w,h,5,4)

#Caso más pequeño. Gana equipo B.
minCase(3,w,h,4,5)

for i in range(cases):
    h = randomHeights[i]
    w = randomWidths[i]

    case = { 'beepers': [], 'dump': [], 'height': h, 'width': w }

    caseName = '{}'.format(i+4)

    beepers = []
    dump = []

    dump.append((dict({'x': 1, 'y': 1})))

    # no de gladiadores -> h-1 * w/2 - 1
    c = int(w/2)
    team1 = range(1,c)
    team2 = range(c+3,w+1)

    for y in range(2, h+1):
        dump.append((dict({'x': c+1, 'y': y})))

        for x in team1:
            n = random.randint(minStrength, maxStrength)
            beepers.append((dict({'count': n, 'x': x, 'y': y})))

        for x in team2:
            n = random.randint(minStrength, maxStrength)
            beepers.append((dict({'count': n, 'x': x, 'y': y})))

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)
    case['dump'] = "\n".join(dumpTag.format(**d) for d in dump)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)
