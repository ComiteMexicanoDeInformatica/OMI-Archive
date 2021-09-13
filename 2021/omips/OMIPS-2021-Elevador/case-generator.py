import random
import os


def pushCase(case, caseName):

	baseXML = """
	<ejecucion>
		<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000">
			{limit}
		</condiciones>
		<mundos>
			<mundo nombre="mundo_0" ancho="{width}" alto="{height}">
				{beepers}
			</mundo>
		</mundos>
		<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
			<programa nombre="p1" ruta="{rute}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="0">
				<despliega tipo="MUNDO"></despliega>
			</programa>
		</programas>
	</ejecucion>
	""".strip(' \t\n\r')
	caseString = baseXML.format(**case)
	casePath = os.path.join('cases', caseName + '.in')
	with open(casePath, 'w') as f:
		f.write(caseString)

def putbeeper(x, y, beepers):
    beeper = '<monton x="' + str(x) + '" y="' + str(y) + '" zumbadores="' + str(beepers) + '"></monton>\n'
    return beeper

def make_one_case(name, caseNumber):
    
    jump = random.randint(1, 20)

    if caseNumber < 4:
        jump = random.randint(1, 10)

    if caseNumber == 0:
        jump = 1

    if caseNumber == 1:
        jump = 100
    
    long = random.randint(4, 100)

    beepers = '<posicionDump x="1" y="1"></posicionDump>'

    for i in range(1, long + 1):
        beepers += putbeeper(i, 1, 1)
    
    empty_string = ""
    
    case = {
		'beepers': beepers,
		'width': 100,
		'height': jump,
		'rute': '{$2$}',
		'limit': empty_string,
	}

    pushCase(case, name)

def make_case(name, caseNumber):
	
	jump = random.randint(4, 50)
	
	if caseNumber < 4:
		jump = random.randint(30, 100)
	
	beepers = '<posicionDump x="1" y="1"></posicionDump>'

	long = random.randint(30, 100)
	
	if caseNumber < 4:
		long = 100

	for i in range(1, long + 1):
		beepers += putbeeper(i, 1, random.randint(1, jump))

	limite = ""

	if 'sub2' in name:
		limite = '<comando nombre="AVANZA" maximoNumeroDeEjecuciones="' + str( 2 * (jump + long) ) +'"/>'
	case = {
		'beepers': beepers,
		'width': 100,
		'height': jump,
		'rute': '{$2$}',
		'limit': limite,
	}

	pushCase(case, name)

random.seed(1421)

for i in range(1, 11):
	make_one_case("sub1." + str(i), i)

for i in range(1, 11):
	make_case("sub2." + str(i), i)

for i in range(1, 11):
	make_case("sub3." + str(i), i)
