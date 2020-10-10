import random
import os
import itertools as it
from math import *
from collections import defaultdict


def addBeeper(x, y, subtask, beepers, columns, rows):
    if subtask == 'easy' and (columns[x] > 2 or rows[y] > 2):
        return False

    beeper = dict({'x': x, 'y': y, 'count': 1})
    if beeper in beepers:
        return False

    beepers.append(beeper)
    columns[x] += 1
    rows[y] += 1
    return True


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
    subtask = 'easy' if i < 10 else 'full'
    caseName = '{}_{}.in'.format(i + 1, subtask)
    w = random.randint(3, 100)
    h = random.randint(3, 100)
    columns = defaultdict(int)
    rows = defaultdict(int)
    beepers = []

    # Intentar poner tryK super vecinos
    tryK = random.randint(0, int(sqrt(w * h)))
    for k in range(tryK):
        x = random.randint(2, w - 1)
        y = random.randint(2, h - 1)
        if addBeeper(x, y, subtask, beepers, columns, rows):
            # Necesitamos asegurar los cuatro vecino, beepers, columns, rowss
            # Vecino norte
            addBeeper(x, random.randint(y + 1, h), subtask, beepers, columns,
                      rows)
            # Vecino sur
            addBeeper(x, random.randint(1, y - 1), subtask, beepers, columns,
                      rows)
            # Vecino este
            addBeeper(random.randint(1, x - 1), y, subtask, beepers, columns,
                      rows)
            # Vecino oeste
            addBeeper(random.randint(x + 1, w), y, subtask, beepers, columns,
                      rows)

    # Rellenar con zumbadores aleatorios
    empty = max(w * h - len(beepers), 1)
    randomBeepersCnt = random.randint(0, int(sqrt(empty) / 2))
    for k in range(randomBeepersCnt):
        beeper = addBeeper(random.randint(1, w), random.randint(1, h), subtask,
                           beepers, columns, rows)

    case = {
        'width': w,
        'height': h,
        'beepers': "\n".join(beeperTag.format(**b) for b in beepers)
    }

    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
