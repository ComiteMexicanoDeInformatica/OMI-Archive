import random
import os


def pushCase(case, caseName):

	baseXML = """
	<ejecucion>
		<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000">
		</condiciones>
		<mundos>
			<mundo nombre="mundo_0" ancho="100" alto="100">
				{beepers}
				<posicionDump x="1" y="1"></posicionDump>
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


def sub1_manual_cases():
	name = 'sub1.1'
	beepers = '<monton x="1" y="1" zumbadores="3"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub1.2'
	beepers = '<monton x="1" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="10"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub1.3'
	beepers = '<monton x="1" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="11"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="12"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="13"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="14"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="17"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="16"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="15"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub1.4'
	beepers = '<monton x="1" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="50"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="97"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="97"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="50"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="50"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="97"></monton>\n'
	beepers = beepers + '<monton x="9" y="1" zumbadores="10"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub1.5'
	beepers = ''
	for i in range(1, 99):
		beepers = beepers + '<monton x="' + str(i) + '" y="1" zumbadores="11"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)

	
def sub2_manual_cases(group):
	beepersk = '<monton x="1" y="2" zumbadores="1"></monton>\n'
	name = 'sub' + str(group) + '.1'
	beepers = beepersk + '<monton x="1" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="87"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="15"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="42"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="63"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="55"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="31"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub' + str(group) + '.2'
	beepers = beepersk + '<monton x="1" y="1" zumbadores="10"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="11"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="12"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="13"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="14"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="15"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="16"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="17"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub' + str(group) + '.3'
	beepers = beepersk + '<monton x="1" y="1" zumbadores="2"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="43"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="87"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="88"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="42"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="3"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="44"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="9" y="1" zumbadores="45"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
def sub3_manual_cases():
	beepersk = '<monton x="1" y="2" zumbadores="1"></monton>\n'
	name = 'sub3.4'
	beepers = beepersk + '<monton x="1" y="1" zumbadores="23"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="23"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="24"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="25"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="24"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="24"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="25"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="25"></monton>\n'
	beepers = beepers + '<monton x="9" y="1" zumbadores="25"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	name = 'sub3.5'
	beepers = beepersk + '<monton x="1" y="1" zumbadores="3"></monton>\n'
	beepers = beepers + '<monton x="2" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="3" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="4" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="5" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="6" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="7" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="8" y="1" zumbadores="3"></monton>\n'
	beepers = beepers + '<monton x="9" y="1" zumbadores="3"></monton>\n'
	beepers = beepers + '<monton x="10" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="11" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="12" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="13" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="14" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="15" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="16" y="1" zumbadores="3"></monton>\n'
	beepers = beepers + '<monton x="17" y="1" zumbadores="3"></monton>\n'
	beepers = beepers + '<monton x="18" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="19" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="20" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="21" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="22" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="23" y="1" zumbadores="4"></monton>\n'
	beepers = beepers + '<monton x="24" y="1" zumbadores="5"></monton>\n'
	beepers = beepers + '<monton x="25" y="1" zumbadores="6"></monton>\n'
	beepers = beepers + '<monton x="26" y="1" zumbadores="6"></monton>\n'
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	
	
def make_case(name, k, unrepeated):
	if (k > 0):
		beepersk = '<monton x="1" y="2" zumbadores="' + str(k) + '"></monton>\n'
	else:
		beepersk = ''
	beepers = beepersk
	n = random.randint(50, 99)
	used = {0}
	
	for i in range(1, n + 1):
		x = random.randint(1, 99)
		while (unrepeated and x in used):
			x = random.randint(1, 99)
		used.add(x)
		beepers = beepers + '<monton x="' + str(i) + '" y="1" zumbadores="' + str(x) + '"></monton>\n'
	
	case = {
		'beepers': beepers,
		'rute': '{$2$}',
	}
	pushCase(case, name)
	

random.seed(2021)

sub1_manual_cases()
for i in range(6, 11):
	make_case("sub1." + str(i), 0, False)

sub2_manual_cases(2)
for i in range(4, 9):
	make_case("sub2." + str(i), 1, True)

sub2_manual_cases(3)
sub3_manual_cases()
for i in range(6, 11):
	make_case("sub3." + str(i), 1, False)
	
for i in range(1, 4):
	make_case("sub4." + str(i), random.randint(3, 10), True)
for i in range(4, 9):
	make_case("sub4." + str(i), random.randint(11, 20), True)
for i in range(9, 14):
	make_case("sub4." + str(i), random.randint(21, 99), True)

for i in range(1, 4):
	make_case("sub5." + str(i), random.randint(3, 10), False)
for i in range(4, 9):
	make_case("sub5." + str(i), random.randint(11, 20), False)
for i in range(9, 14):
	make_case("sub5." + str(i), random.randint(21, 99), False)
