import random
import os


def pushCase(case, caseName):

	baseXML = """
	<ejecucion>
		<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000">
		</condiciones>
		<mundos>
			<mundo nombre="mundo_0" ancho="{width}" alto="{height}">
				{beepers}
			</mundo>
		</mundos>
		<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
			<programa nombre="p1" ruta="{rute}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
				<despliega tipo="ORIENTACION"></despliega>
			</programa>
		</programas>
	</ejecucion>
	""".strip(' \t\n\r')
	caseString = baseXML.format(**case)
	casePath = os.path.join('cases', caseName + '.in')
	with open(casePath, 'w') as f:
		f.write(caseString)


def make_stoneless_case(name, caseNumber):
	
	coinX = 0
	coinY = 0
	beepers = ""

	if caseNumber == 1:
		coinX = 1
		coinY = random.randint(3, 99)
	elif caseNumber == 2:
		coinX = random.randint(3, 99)
		coinY = 1
	elif caseNumber == 3:
		coinX = 1
		coinY = 100
	elif caseNumber == 4:
		coinX = 100
		coinY = 1
	elif caseNumber == 5:
		coinX = 100
		coinY = 100
	elif caseNumber == 6:
		coinX = 100
		coinY = random.randint(3, 99)
	elif caseNumber == 7:
		coinX = random.randint(3, 99)
		coinY = 100
	else:
		coinX = random.randint(2, 99)
		coinY = random.randint(2, 99)

	beepers = '<monton x="' + str(coinX) + '" y="' + str(coinY) + '" zumbadores="2"></monton>'

	case = {
		'beepers': beepers,
		'width': 100,
		'height': 100,
		'rute': '{$2$}',
	}
	pushCase(case, name)

def make_diagonal_case(name, caseNumber):
	
	coinX = 0
	coinY = 0
	beepers = ""

	if caseNumber < 3:
		coinX = 100
		coinY = 100
	else:
		coinX = random.randint(3, 99)
		coinY = coinX

	beepers = '<monton x="' + str(coinX) + '" y="' + str(coinY) + '" zumbadores="2"></monton>\n'
	
	beeperTable = [[0 for x in range(101)] for y in range(101)]

	for i in range((coinX - 1) * (coinX - 1) // 2):
		x = random.randint(2, coinX - 1)
		y = random.randint(2, coinX - 1)
		beeperTable[x][y] = 1
		
	for i in range(50):
		x = random.randint(2, 100)
		y = random.randint(2, 100)
		beeperTable[x][y] = 1
		
	if (caseNumber % 2) == 1:
		x = random.randint(2, coinX - 1)
		y = x
		beeperTable[x][y] = 1
	else:
		for i in range(101):
			beeperTable[i][i] = 0
		
	for i in range(101):
		for j in range(101):
			if beeperTable[i][j] == 1 and i > 0 and j > 0 and i != coinX and j != coinY:
				beepers += '<monton x="' + str(i) + '" y="' + str(j) + '" zumbadores="1"></monton>\n'

	case = {
		'beepers': beepers,
		'width': 100,
		'height': 100,
		'rute': '{$2$}',
	}
	pushCase(case, name)

def make_8x8_case(name, caseNumber):
	
	coinX = 0
	coinY = 0
	beepers = ""

	if caseNumber < 3:
		coinX = 8
		coinY = 8
	else:
		coinX = random.randint(3, 8)
		coinY = random.randint(3, 8)

	beepers = '<monton x="' + str(coinX) + '" y="' + str(coinY) + '" zumbadores="2"></monton>\n'
	
	beeperTable = [[0 for x in range(9)] for y in range(9)]

	for i in range((coinX - 1) // 2):
		x = random.randint(2, coinX - 1)
		y = random.randint(2, coinX - 1)
		beeperTable[x][y] = 1
		
	if caseNumber == 2:
		beeperTable[2][2] = 1
		
	for i in range(5):
		x = random.randint(2, 8)
		y = random.randint(2, 8)
		beeperTable[x][y] = 1
		
	for i in range(9):
		for j in range(9):
			if caseNumber != 1 and beeperTable[i][j] == 1 and i > 0 and j > 0 and i != coinX and j != coinY:
				beepers += '<monton x="' + str(i) + '" y="' + str(j) + '" zumbadores="1"></monton>\n'

	case = {
		'beepers': beepers,
		'width': 8,
		'height': 8,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
def make_100x100_case(name, caseNumber):
	
	coinX = 0
	coinY = 0
	beepers = ""

	if caseNumber < 3:
		coinX = 100
		coinY = 100
	else:
		coinX = random.randint(3, 100)
		coinY = random.randint(3, 100)

	beepers = '<monton x="' + str(coinX) + '" y="' + str(coinY) + '" zumbadores="2"></monton>\n'
	
	beeperTable = [[0 for x in range(101)] for y in range(101)]

	for i in range((coinX - 1) // 2):
		x = random.randint(2, coinX - 1)
		y = random.randint(2, coinX - 1)
		beeperTable[x][y] = 1
		
	if caseNumber == 2:
		beeperTable[2][2] = 1
		
	if (caseNumber >= 3) and (caseNumber % 2) == 1:
		for i in range(50):
			x = random.randint(2, 100)
			y = random.randint(2, 100)
			beeperTable[x][y] = 1
	else:
		for i in range(750):
			x = random.randint(2, 100)
			y = random.randint(2, 100)
			beeperTable[x][y] = 1
		
	for i in range(101):
		for j in range(101):
			if caseNumber != 1 and beeperTable[i][j] == 1 and i > 0 and j > 0 and i != coinX and j != coinY:
				beepers += '<monton x="' + str(i) + '" y="' + str(j) + '" zumbadores="1"></monton>\n'

	case = {
		'beepers': beepers,
		'width': 100,
		'height': 100,
		'rute': '{$2$}',
	}
	pushCase(case, name)

random.seed(2021)

for i in range(1, 11):
	make_stoneless_case("sub1." + str(i), i)

for i in range(1, 7):
	make_diagonal_case("sub2." + str(i), i)

for i in range(1, 11):
	make_8x8_case("sub3." + str(i), i)

for i in range(1, 11):
	make_100x100_case("sub4." + str(i), i)