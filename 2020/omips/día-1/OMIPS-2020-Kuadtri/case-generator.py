import os
import itertools as it
from numpy import random

baseXML = """
<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="{length}" alto="{length}">
            <monton x="1" y="1" zumbadores="{beepers}"></monton>
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
            <despliega tipo="POSICION"></despliega>
		</programa>
	</programas>
</ejecucion>
""".strip(' \t\n\r')

cases = 14

for i in range(cases):
    caseName = '{}.in'.format(i + 6)
    n = int(random.choice(6, 1, p=[0.05, 0.1, 0.05, 0.25, 0.25, 0.3]) + 1)

    length = 2**n
    beepers = int(random.randint((4**n - 1) / 3, 4 * (4**n - 1) / 3))

    case = {'length': length, 'beepers': beepers}
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
