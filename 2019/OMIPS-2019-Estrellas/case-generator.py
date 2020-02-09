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
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
			<despliega tipo="UNIVERSO"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'

xs = [i+1 for i in range(10)]

for i in range(10):
    allPoints = list(it.product(xs, repeat=3))

    case = { 'beepers': [] }

    pointsCount = random.randint(2, 90)

    caseName = '{0}.norestriction-{1}'.format(i, pointsCount)

    points = random.sample(allPoints, pointsCount)

    beepers = [
        dict({'count': point[0], 'x': j+1, 'y': 1})
        for point, j in zip(points,range(pointsCount))
    ] + [
        dict({'count': point[1], 'x': j+1, 'y': 2})
        for point, j in zip(points,range(pointsCount))
    ] + [
        dict({'count': point[2], 'x': j+1, 'y': 3})
        for point, j in zip(points,range(pointsCount))
    ]

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)

    allPoints = list(it.product(xs, repeat=2))

    points = random.sample(allPoints, pointsCount)

    case = { 'beepers': [] }

    caseName = '{0}.samez-{1}'.format(i+10, pointsCount)

    z = random.randint(1, 10)

    beepers = [
        dict({'count': point[0], 'x': j+1, 'y': 1})
        for point, j in zip(points,range(pointsCount))
    ] + [
        dict({'count': point[1], 'x': j+1, 'y': 2})
        for point, j in zip(points,range(pointsCount))
    ] + [
        dict({'count': z, 'x': j+1, 'y': 3})
        for j in range(pointsCount)
    ]

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)

    case = { 'beepers': [] }

    pointsCount = random.randint(2, 10)

    caseName = '{0}.samexyz-{1}'.format(i+20, pointsCount)

    smallPoints = xs

    random.shuffle(smallPoints)

    points = smallPoints[0:pointsCount]

    beepers = [
        dict({'count': point, 'x': j+1, 'y': 1})
        for point, j in zip(points,range(pointsCount))
    ] + [
        dict({'count': point, 'x': j+1, 'y': 2})
        for point, j in zip(points,range(pointsCount))
    ] + [
        dict({'count': point, 'x': j+1, 'y': 3})
        for point, j in zip(points,range(pointsCount))
    ]

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)
