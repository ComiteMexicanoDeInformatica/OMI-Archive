import random
import os


def pushCase(case, caseName):
    montones = '<monton x="{}" y="{}" zumbadores="1"></monton>'
    case['montones'] = """
                """.join([montones.format(x, y) for (x, y) in case['beepers']])

    case['comando_avanza'] = ""
    if case['max_moves'] is not None:
        case[
            'comando_avanza'] = '<comando nombre="AVANZA" maximoNumeroDeEjecuciones="{}"/>'.format(
                case['max_moves'])

    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000">
            {comando_avanza}
        </condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
                {montones}
            </mundo>
        </mundos>
        <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
            <programa nombre="p1" ruta="{rute}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
                <despliega tipo="UNIVERSO"></despliega>
            </programa>
        </programas>
    </ejecucion>
    """.strip(' \t\n\r')
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, 'w') as f:
        f.write(caseString)


def make_case(name, sz):
    w = random.randint(1, min(100, int(sz) * 10))
    h = random.randint(1, min(100, int(sz) * 10))

    beepers = []

    # Creamos una diagonal desde (1, w)
    x = 1
    y = h
    while x <= w and y >= 1:
        # Elegimos poner o no poner
        if random.randint(0, 1) == 1 and (x, y) not in beepers:
            beepers += [(x, y)]
        # Elegimos irnos al sur o este
        if random.randint(0, 1) == 1:
            x += 1
        else:
            y -= 1

    # Creamos una diagonal desde (w, 1)
    x = w
    y = 1
    while x >= 1 and y <= h:
        # Elegimos poner o no poner
        if random.randint(0, 1) == 1 and (x, y) not in beepers:
            beepers += [(x, y)]
        # Elegimos irnos al norte u oeste
        if random.randint(0, 1) == 1:
            x -= 1
        else:
            y += 1

    # Ponemos aleatoriamente beepers
    for _ in range(random.randint(1, w * h)):
        x = random.randint(1, w)
        y = random.randint(1, h)
        if (x, y) in beepers:
            continue
        if all([x > i or y > j for (i, j) in beepers]) or any(
            [i <= x and j <= y for (i, j) in beepers]):
            beepers += [(x, y)]

    max_moves = None
    if 'st2' in name:
        max_moves = 8 * w * h
    elif 'st3' in name:
        max_moves = 2 * w * h

    case = {
        'height': h,
        'width': w,
        'beepers': beepers,
        'max_moves': max_moves,
        'rute': '{$2$}'
    }
    pushCase(case, name)


# Pa que genere los mismos casos
random.seed(2)

# Hacemos los casos faciles
for i in range(10):
    make_case("st1_" + str(i), i + 1)

# Casos que importan los avanzas
for i in range(5):
    make_case("st2." + str(i), i + 6)

for i in range(5):
    make_case("st3." + str(i), i + 6)
