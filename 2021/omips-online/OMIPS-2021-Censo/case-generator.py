import random
import os
import itertools as it

def pushCase(case,caseName,montones,paredes,dumps):
    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
    {montones}
    {paredes}
    {dumps}
            </mundo>
        </mundos>
        <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
            <programa nombre="p1" ruta="{rute}" mundoDeEjecucion="mundo_0" xKarel="{xkarel}" yKarel="{ykarel}" direccionKarel="{dir}" mochilaKarel="{moch}">
                <despliega tipo="MUNDO"></despliega>
            </programa>
        </programas>
    </ejecucion>
    """.strip(' \t\n\r')
    montonesTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'

    case['montones'] = "\n".join(montonesTag.format(**b) for b in montones)
    
    paredesTag = '\t\t\t<pared x1="{x}" y1="{y}" y2="{y1}"></pared>'

    case['paredes'] = "\n".join(paredesTag.format(**b) for b in paredes)
    
    dumpsTag = '\t\t\t<posicionDump x="{x}" y="{y}"></posicionDump>'

    case['dumps'] = "\n".join(dumpsTag.format(**b) for b in dumps)
    
    caseString = baseXML.format(**case)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, 'w') as f:
        f.write(caseString)

def getDumps(h):
    dumps = []
    for i in range(1,h+1):
        dumps.append((dict({'x': 1, 'y': i})))
    return dumps

def getParedes(h,w):
    pared = []
    for i in range(1,w):
        full = 1
        for j in range(0,h):
            wall = random.randint(0,2)
            if wall != 0:
                pared.append((dict({'x': i, 'y': j,'y1':j+1})))
            else:
                full = 0
        if full == 1:
            pared.pop()
    return pared

def getMontones(h,w,monmax, zummax, option):
    if option == 3:
        monmax = 1
    montones = []
    a = 1
    b = h+1
    if option == 2:
        a = random.randint(1,h)
        b = a+1
    for i in range(a,b): #recorriendo filas
        numMon = random.randint(0,monmax)
        numZum = random.randint(0,zummax)
        j = 1
        s = set()
        s.clear()
        while numMon > 0 and numZum:
            p = random.randint(0,10)
            if p > 7 and (j not in s): # poner monton
                if option == 1:
                    cuantos = 1
                else:
                    cuantos = random.randint(1,numZum)
                numZum -= cuantos
                montones.append((dict({'x': j, 'y': i,'count':cuantos})))
                s.add(j)
                numMon-=1
            j+=1
            if j == w+2:
                j = 1
    return montones



def makeCase(name,z,option):
    mochila = "0"
    if z == 1:
        mochila = "INFINITO"
    #tamaño mapa-----
    h = random.randint(2, 100)
    w = random.randint(2, 100)
    #------------------
    caseName = '{}'.format(name)
    #cualquier lugar cualquier dirección---
    xk = random.randint(2, w)
    yk = random.randint(2, h)
    di = random.randint(1, 4)
    if di == 1:
        di = "NORTE"
    elif di == 2:
        di = "OESTE"
    elif di == 3:
        di = "SUR"
    else:
        di = "ESTE"        
    #------------------
    montones = getMontones(h,w,w,99,option)
    paredes = getParedes(h,w)
    dumps = getDumps(h)
    case = {'height': h, 'width': w, 'montones': montones,'paredes': paredes,'dumps': dumps, 'rute': "{$2$}", 'xkarel': xk, 'ykarel': yk, 'dir': di, 'moch':mochila}
    pushCase(case,caseName,montones,paredes,dumps)

#50pts sin zumbadores i = 0
#50pts con zumbadores inf
for i in range(2):
    #makecase(nombre, zu,option)
    for j in range(10): #todos los montones son a lo mas de tamaño 1 
        extension = "st1."
        if i == 1:
            extension = "st5."
        makeCase(extension+str(j),i,1)
    for j in range(10):#Solo hay un reglon con zumbadores 
        extension = "st2."
        if i == 1:
            extension = "st6."
        makeCase(extension+str(j),i,2)
    for j in range(10):#A lo mas solo hay un monton por reglon 
        extension = "st3."
        if i == 1:
            extension = "st7."
        makeCase(extension+str(j),i,3)
    for j in range(20):# casos sin restricciones, EL st4.0.in ES EL CASO DE EJEMPLO
        extension = "st4."
        if i == 1:
            extension = "st8."
        makeCase(extension+str(j),i,0)

''' Caso de ejemplo
<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="5" alto="5">
			<monton x="1" y="1" zumbadores="1"></monton>
			<monton x="4" y="1" zumbadores="1"></monton>
			<monton x="1" y="2" zumbadores="1"></monton>
			<monton x="5" y="2" zumbadores="1"></monton>
			<monton x="2" y="3" zumbadores="1"></monton>
			<monton x="3" y="3" zumbadores="2"></monton>
			<monton x="5" y="3" zumbadores="1"></monton>
			<monton x="4" y="5" zumbadores="99"></monton>
			<pared x1="3" y1="0" y2="1"></pared>
			<pared x1="4" y1="0" y2="1"></pared>
			<pared x1="1" y1="1" y2="2"></pared>
			<pared x1="2" y1="1" y2="2"></pared>
			<pared x1="4" y1="1" y2="2"></pared>
			<pared x1="1" y1="2" y2="3"></pared>
			<pared x1="3" y1="2" y2="3"></pared>
			<pared x1="4" y1="2" y2="3"></pared>
			<pared x1="1" y1="3" y2="4"></pared>
			<pared x1="2" y1="3" y2="4"></pared>
			<pared x1="4" y1="3" y2="4"></pared>
			<pared x1="2" y1="4" y2="5"></pared>
			<posicionDump x="1" y="1"></posicionDump>
			<posicionDump x="1" y="2"></posicionDump>
			<posicionDump x="1" y="3"></posicionDump>
			<posicionDump x="1" y="4"></posicionDump>
			<posicionDump x="1" y="5"></posicionDump>
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{$2$}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="0">
			<despliega tipo="MUNDO"></despliega>
		</programa>
	</programas>
</ejecucion>
'''