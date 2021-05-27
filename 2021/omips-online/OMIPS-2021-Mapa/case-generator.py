import random
import os
import itertools as it


def pushCase(case, caseName):
    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
{beepers}
            </mundo>
        </mundos>
        <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
            <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="0">
                <despliega tipo="POSICION"></despliega>
            </programa>
        </programas>
    </ejecucion>
    """.strip(' \t\n\r')
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, 'w') as f:
        f.write(caseString)


beeperTag = '\t\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'

def makeCase(name, h, w, maxSteps):
    caseName = '{}'.format(name)

    beepers = []

    n = int(h/2)
    bs = 0

    cx = 1
    cy = 1

    while bs < n:
        d = random.randint(1,4)
        r = 0

        if d == 1:
            if cy >= h:
                continue

            ms = min(maxSteps, h-cy)
            r = random.randint(1,ms)

            if cy + r >= h:
                continue

            cy += r
        elif d == 2:
            if cx <= 1:
                continue

            ms = min(maxSteps, cx-1)
            r = random.randint(1, ms)

            if cx - r <= 0:
                continue

            cx -= r
        elif d == 3:
            if cy <= 1:
                continue

            ms = min(maxSteps, cy-1)
            r = random.randint(1,ms)

            if cy -r <= 0:
                continue

            cy -= r
        elif d == 4:
            if cx >= w:
                continue

            ms = min(maxSteps, w-cx)
            r = random.randint(1,ms)

            if cx + r >= w:
                continue

            cx += r

        beepers.append({
            'x': 1,
            'y': bs+1,
            'count': d
        })

        beepers.append({
            'x': 2,
            'y': bs+1,
            'count': r
        })
        bs += 1

    beeps = "\n".join(beeperTag.format(**b) for b in beepers)
    case = { 'beepers': beeps, 'height': h, 'width': w }

    pushCase(case, caseName)

def makeCaseST2(name, h, w, maxSteps):
    caseName = '{}'.format(name)

    beepers = []

    n = random.randint(1,4) #cuántas instrucciones
    dirs = list([1,2,3,4])
    used = set({})
    random.shuffle(dirs)

    bs = 0
    i = -1

    cx = 1
    cy = 1
    # (1 norte, 2 oeste, 3 sur, 4 este)
    while bs < n:
        r = 0
        i = (i+1)%4
        d = dirs[i]

        if d in used:
            continue

        if d == 1:
            if cy >= h:
                continue

            ms = min(maxSteps, h-cy)
            r = random.randint(1,ms)

            if cy + r >= h:
                continue

            cy += r
        elif d == 2:
            if cx <= 1:
                continue

            ms = min(maxSteps, cx-1)
            r = random.randint(1, ms)

            if cx - r <= 0:
                continue

            cx -= r
        elif d == 3:
            if cy <= 1:
                continue

            ms = min(maxSteps, cy-1)
            r = random.randint(1,ms)

            if cy -r <= 0:
                continue

            cy -= r
        elif d == 4:
            if cx >= w:
                continue

            ms = min(maxSteps, w-cx)
            r = random.randint(1,ms)

            if cx + r >= w:
                continue

            cx += r

        beepers.append({
            'x': 1,
            'y': bs+1,
            'count': d
        })

        beepers.append({
            'x': 2,
            'y': bs+1,
            'count': r
        })

        bs+=1
        used.add(d)

    beeps = "\n".join(beeperTag.format(**b) for b in beepers)
    case = { 'beepers': beeps, 'height': h, 'width': w }

    pushCase(case, caseName)

cases = 41
minWidth = 2
maxWidth = 100
minHeight = 2
maxHeight = 100
randomWidths = [random.randint(minWidth, maxWidth) for i in range(cases)]
randomHeights = [random.randint(minHeight, maxHeight) for i in range(cases)]

# Casos no agrupados.
# st1 cases (15 puntos): todos los pasos son montones de 1.
for i in range(1, 16):
    makeCase("st1_"+str(i), randomHeights[i],randomWidths[i],1)
# st2 cases (15 puntos): solo un renglón de cada orientación.
for i in range(16, 31):
    makeCaseST2("st2_"+str(i), randomHeights[i],randomWidths[i],99)
# st3 cases (70 puntos): mucho de todo.
for i in range(31, 41):
    makeCase("st3_"+str(i), randomHeights[i],randomWidths[i],99)
