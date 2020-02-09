import random
import os
import itertools as it
from math import *

baseXML = """
<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="{width}" alto="{height}">
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
cases = 19
minWidth = 2
maxWidth = 50
minHeight = 2
maxHeight = 50
randomWidths = [random.randint(minWidth, maxWidth) for i in range(cases)]
randomHeights = [random.randint(minHeight, maxHeight) for i in range(cases)]

for i in range(cases):
    h = randomHeights[i]
    w = randomWidths[i]

    case = { 'beepers': [], 'height': h, 'width': w }

    caseName = '{}'.format(i+1)

    beepers = []

    for y in range(1, h+1):
        a = 1
        if y == 1:
            a = 2
        n = int(w/2)
        l = random.randint(1,n)
        s = random.randint(a,w-l+1)
        for x in range(s, s+l):
            beepers.append((dict({'count': 1, 'x': x, 'y': y})))

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)