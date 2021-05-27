import random
import os
import itertools as it

def pushCase(case,caseName):
    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="{width}" alto="{height}"></mundo>
        </mundos>
        <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
            <programa nombre="p1" ruta="{rute}" mundoDeEjecucion="mundo_0" xKarel="{kx}" yKarel="{ky}" direccionKarel="{dir}" mochilaKarel="{mochila}">
                <despliega tipo="POSICION"></despliega>
            </programa>
        </programas>
    </ejecucion>
    """.strip(' \t\n\r')
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, 'w') as f:
        f.write(caseString)

def makeCase(name,size):
    minWidth = 2
    maxWidth = int(100 * size)
    minHeight = 2
    maxHeight = int(100 * size)
    caseName = '{}'.format(name)
    
    h = random.randint(minHeight + int(size)*15, maxHeight)
    w = random.randint(minWidth + int(size)*15, maxWidth)
    ry1 = random.randint(1, h-1)
    rx1 = random.randint(1, w-1)
    ry2 = random.randint(2, h)
    rx2 = random.randint(2, w)
    zumbadores = 2*(w+h-2)

    direc = random.randint(1,4)
    if direc == 1: #norte
        case = {'height': h, 'width': w,'kx': w,'ky':ry1,'mochila':zumbadores,'rute':'{$2$}','dir':'NORTE'}
    elif direc == 2: #sur
        case = {'height': h, 'width': w,'kx': 1,'ky':ry2,'mochila':zumbadores,'rute':'{$2$}','dir':'SUR'}
    elif direc == 3: #este
        case = {'height': h, 'width': w,'kx': rx1,'ky':1,'mochila':zumbadores,'rute':'{$2$}','dir':'ESTE'}
    else: #oeste
        case = {'height': h, 'width': w,'kx': rx2,'ky':h,'mochila':zumbadores,'rute':'{$2$}','dir':'OESTE'}
    pushCase(case,caseName)

#(10 casos): Generados a mano (no agrupados). El 0 es el caso de ejemplo
#lit cases (20 casos): w,h<16
for i in range(10,30):
    makeCase(str(i)+".lit",0.15)
#Resto de casos (20): w,h<101
for i in range(30,50):
    makeCase(str(i)+".big",1)