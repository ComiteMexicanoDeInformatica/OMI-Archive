import random
import os
import itertools as it

def pushCase(case,caseName):
    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000">
			{moves}
		</condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="100" alto="100">
				{beepers}
				{dumps}
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
		
    baseXMLout = """
	<resultados>
		<mundos>
			<mundo nombre="mundo_0">
				<linea fila="1" compresionDeCeros="true">{answer}</linea>
			</mundo>
		</mundos>
		<programas>
			<programa nombre="p1" resultadoEjecucion="FIN PROGRAMA"/>
		</programas>
	</resultados>	
	""".strip(' \t\n\r')
    caseString = baseXMLout.format(**case)
    casePath = os.path.join('cases', caseName + '.out')
    with open(casePath, 'w') as fout:
        fout.write(caseString)

def makeCase(name, size, different, limit):
	n = (size * 10) + random.randint(0, 9)
	beepers = ""
	dumps = ""
	answer = ""
	if (limit == 0):
		moves = '<comando nombre="AVANZA" maximoNumeroDeEjecuciones="' + str(2 * n) + '"/>'
	else:
		moves = ''
	repeated = set()
	
	valores = []
	maximo = 0

	for i in range(1, n + 1):
		while True:
			z = random.randint(1, 99)
			if (not different or z not in repeated):
				if (different):
					repeated.add(z)
				beepers = beepers + '\n<monton x="' + str(i) + '" y="1" zumbadores="' + str(z) + '"></monton>'
				dumps = dumps + '\n<posicionDump x="' + str(i) + '" y="1"></posicionDump>'
				valores.append(z)
				if z > maximo:
					maximo = z
				break

	x = len(valores)
			
			
	for i in range(1, n + 1):
		if valores[i - 1] == maximo:
			answer += '(' + str(i) + ') 1 '
			
	case = {'beepers': beepers, 'dumps': dumps, 'moves': moves, 'answer': answer, 'rute':'{$2$}'}
	pushCase(case, name)

# 10 casos por subtask
for g in range(1, 5):
	for i in range(1,11):
		makeCase("sub" + str(g) + "." + str(i), i - 1, g < 3, g % 2)
