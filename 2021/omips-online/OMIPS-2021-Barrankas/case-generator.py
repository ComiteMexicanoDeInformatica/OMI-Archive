import random
import os


def pushCase(case, caseName):
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
            <mundo nombre="mundo_0" ancho="100" alto="100">
                {beepers}
                <posicionDump x="1" y="3"></posicionDump>
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


def make_case(name, size: int, sorted: bool):
    beepers = []
    n = random.randint(5 * size, min(100, 5 * size + 1))
    k = random.randint(2, n // 2)
    beepers.append({'x': 1, 'y': 1, 'count': n})
    beepers.append({'x': 2, 'y': 1, 'count': k})

    r = [random.randint(1, 99) for i in range(n + 2)]

    if sorted:
        r.sort()

    for x in range(1, n + 1):
        beepers.append({'x': x, 'y': 2, 'count': r[x - 1]})

    max_moves = None
    if 'st3' in name:
        max_moves = 8 * n

    case = {
        'beepers': "\n".join(beeperTag.format(**b) for b in beepers),
        'max_moves': max_moves,
    }
    pushCase(case, name)


# Pa que genere los mismos casos
random.seed(814167495)

# Casos ordenados
for i in range(20):
    make_case("st1_{:02}".format(i + 1), i + 1, True)
# Casos desordenanods
for i in range(20):
    make_case("st2_{:02}".format(i + 1), i + 1, False)

# Casos que importan los avanzas
for i in range(10):
    make_case("st3_{:02}".format(i + 1), i + 9, False)
