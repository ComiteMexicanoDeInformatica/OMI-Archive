import random
import os
from math import *

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
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
			<despliega tipo="MUNDO"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'
dumpTag = '\t\t\t<posicionDump x="{x}" y="{y}"></posicionDump>'

randomWidths = [random.randint(2, 40) for i in range(20)]
randomBeepers = [random.randint(1, w) for w in randomWidths]

caseParams = [
    { 'width': w
    , 'height': random.randint(max(round(ceil(b/w)), 2), 40)
    , 'beepers': b
    , 'easy': True if random.random() < .23 else False
    }
    for (w,b) in zip(randomWidths, randomBeepers)
] + [
    { 'width': 1
    , 'height': 2
    , 'beepers': 1
    , 'easy': False
    } ,
    { 'width': 1
    , 'height': 3
    , 'beepers': 1
    , 'easy': True
    } ,
    { 'width': 10
    , 'height': 2
    , 'beepers': 10
    , 'easy': False
    } ,
    { 'width': 20
    , 'height': 20
    , 'beepers': 0
    , 'easy': True # MWAHAHAHAHA
    } ,
]

for i in range(len(caseParams)):
    case = caseParams[i]

    caseName = '{0}.{1[width]}x{1[height]}-{1[beepers]}'.format(i, case)
    
    if case['easy']:
        caseName += '.emptyrows'

    N = case['beepers']

    candidates = range(1, case['width']+1)
    toHide = random.sample(candidates, N)

    possibleCoords = [{'x': x, 'y': y}
                      for x in range(1, case['width']+1)
                      for y in range(3 if case['easy'] else 1,
                                     case['height']+1)]
    coords = random.sample(possibleCoords, N)

    beepers = [
        dict({'count': toHide[i]}, **coords[i])
        for i in range(N)
    ]

    toDump = [{'x': x, 'y': y}
              for x in range(1, case['width']+1)
              for y in [1,2]]

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)
    case['dump'] = "\n".join(dumpTag.format(**c) for c in toDump)

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)
