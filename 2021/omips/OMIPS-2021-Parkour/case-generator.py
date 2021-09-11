import random
import os


def pushCase(case, caseName):
    montones = '<monton x="{}" y="{}" zumbadores="{}"></monton>'
    case['montones'] = """
                """.join([montones.format(x, y, zumbadores) for (x, y, zumbadores) in case['beepers']])

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
                <posicionDump x="1" y="1"></posicionDump>
                {montones}
            </mundo>
        </mundos>
        <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
            <programa nombre="p1" ruta="{rute}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
                <despliega tipo="MUNDO"></despliega>
            </programa>
        </programas>
    </ejecucion>
    """.strip(' \t\n\r')
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, 'w') as f:
        f.write(caseString)


def make_case(name):
    beepers = []
    salto = 1 if 'sub1' in name else random.randint(1, 15)
    beepers += [(1, 2, salto)]

    x = 1
    anterior = 0
    zumbador = 0
    maximo = random.randint(1, 99)
    while zumbador < maximo:
        zumbador = random.randint(anterior + 1, min(anterior + 2 * salto, maximo) if 'sub2' in name else maximo)
        while len(beepers) == 1 and zumbador == maximo:
            zumbador = random.randint(anterior + 1, min(anterior + 2 * salto, maximo) if 'sub2' in name else maximo)
        anterior = zumbador
        beepers += [(x, 1, zumbador)]
        x += 1

    case = {
        'beepers': beepers,
        'max_moves': (4 * (len(beepers) - 1) + 2) if 'sub4' in name else None,
        'rute': '{$2$}',
    }
    pushCase(case, name)


# 99 zumbadores
def especial_case_99(name):
    beepers = []
    beepers += [(1, 2, 1)]
    for i in range(1, 100):
        beepers += [(i, 1, i)]
    case = {
        'beepers': beepers,
        'max_moves': (4 * (len(beepers) - 1) + 2) if 'sub4' in name else None,
        'rute': '{$2$}',
    }
    pushCase(case, name)


random.seed(2)

for i in range(1, 6):
    make_case("sub1." + str(i))

for i in range(1, 6):
    make_case("sub2." + str(i))

for i in range(1, 11):
    make_case("sub3." + str(i))

for i in range(1, 11):
    make_case("sub4." + str(i))

especial_case_99("sub1.99")
especial_case_99("sub4.99")
