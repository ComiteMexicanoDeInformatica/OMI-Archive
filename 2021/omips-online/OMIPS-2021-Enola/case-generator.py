import random
import os
import itertools as it


def pushCase(case, caseName):
    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="100" alto="100">
{beepers}
                <pared x1="{pared}" y1="0" y2="1"></pared>
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
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, 'w') as f:
        f.write(caseString)


beeperTag = '\t\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'
dumpTag = '\t\t\t\t<posicionDump x="{x}" y="{y}"></posicionDump>'


def makeCase(name,minLetters, maxLetters, diff):
    caseName = '{}'.format(name)
    pared = random.randint(minLetters, maxLetters)

    beepers = []
    c = set(range(1,100))
    letters = random.sample(c,pared)

    for i in range(pared):
        count = letters[i]
        beepers.append({'x': i+1, 'y': 1, 'count': count})

    dump = []
    wordLen = random.randint(1, 100 - pared)

    for i in range(wordLen):
        if diff:
            count = random.randint(1, 99)
        else:
            count = random.sample(letters,1)[0]

        beepers.append({'x': pared + i + 1, 'y': 1, 'count': count})
        dump.append({'x': pared + i + 1, 'y': 1})

    case = {
        'beepers': "\n".join(beeperTag.format(**b) for b in beepers),
        'pared': pared,
        'dump': "\n".join(dumpTag.format(**b) for b in dump)
    }
    pushCase(case, caseName)


# Casos no agrupados.
# st1 cases (23 casos): letras 2
for i in range(1, 13):
    makeCase(str(i) + "_st1", 2,2, False)
# st2 cases (60): letras <=10
for i in range(13, 32):
    makeCase(str(i) + "_st2", 1,10, False)
# st3 cases (17): pueden haber letras que no están en la llave
for i in range(33, 49):
    makeCase(str(i) + "_st3", 1,99, True)
