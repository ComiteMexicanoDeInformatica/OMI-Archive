import random
import os
import itertools as it

def pushBeepers(beepers,case,caseName):
    baseXML = """
    <ejecucion>
        <condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
        <mundos>
            <mundo nombre="mundo_0" ancho="{width}" alto="{height}">
    {beepers}
            </mundo>
        </mundos>
        <programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
            <programa nombre="p1" ruta="{{$2$}}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
                <despliega tipo="POSICION"></despliega>
            </programa>
        </programas>
    </ejecucion>
    """.strip(' \t\n\r')

    beeperTag = '\t\t\t<monton x="{x}" y="{y}" zumbadores="{count}"></monton>'

    case['beepers'] = "\n".join(beeperTag.format(**b) for b in beepers)

    caseString = baseXML.format(**case)
    path = "--here your path--"
    casePath = os.path.join(path,'cases', caseName + '.in')

    with open(casePath, 'w') as f:
        f.write(caseString)


minWidth = 3
maxWidth = 25
minHeight = 3
maxHeight = 25

def makeCase(name, w, h, b):
    beepers = []
    if name == '20':
        case = { 'beepers': [], 'height': 5, 'width': 5 }
        caseName = '{}'.format(name)
        beepers.append((dict({'count': 1, 'x': 4, 'y': 1})))
        beepers.append((dict({'count': 1, 'x': 1, 'y': 4})))
        beepers.append((dict({'count': 1, 'x': 5, 'y': 5})))
        pushBeepers(beepers,case,caseName)
        return 
    
    if h == -1:
        h = random.randint(minHeight, maxHeight)
    if w == -1:
        w = random.randint(minWidth, maxWidth)
    
    case = { 'beepers': [], 'height': h, 'width': w }

    caseName = '{}'.format(name)
	#numero de zumbadores
    if b == -1:
        b = random.randint(min(3,h*w),min(h*w,21))

    usadas = set()
    for i in range(b):
        #solo posiciones diferentes
        while True:
            x = random.randint(1, w)   
            y = random.randint(1, h)   
            if (x,y) not in usadas:
                usadas.add((x,y))
                break
        beepers.append((dict({'count': 1, 'x': x, 'y': y})))
        
    pushBeepers(beepers,case,caseName)

#makecases(tipo,nombre,ancho(si es -1 random),alto(igual),numero de beepers(igual))
#1xm cases (10 casos): Generados a mano.
#am2b cases (10 casos):
for i in range(10,20):
    makeCase(str(i)+".am2b",-1,-1,2)
#Resto de casos (30):
for i in range(20,50):
    makeCase(str(i),-1,-1,-1)
