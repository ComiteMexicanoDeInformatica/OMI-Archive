import random
import os
import itertools as it
from math import *


def createBeeper(x, y):
    return dict({
        'x': x,
        'y': y,
        'count': 1
    })


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

for i in range(cases):
    caseName = '{}.in'.format(i+1)
    w = random.randint(1, 100)
    h = random.randint(1, 100)
    beepers = []

    # Ponemos k zumbadores
    k = random.randint(0, w*h)
    for j in range(k):
        x = random.randint(1, w)
        y = random.randint(1, h)
        beeper = createBeeper(x, y)
        if beeper not in beepers:
            beepers.append(beeper)

    case = {
        'width': w,
        'height': h,
        'beepers': "\n".join(beeperTag.format(**b) for b in beepers)
    }

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath, 'w') as f:
            f.write(caseString)
