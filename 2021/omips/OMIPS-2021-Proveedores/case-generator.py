import random

def putbeeper(x, y, beepers):
    beeper = "\t\t\t<monton x=\"" + str(x) + "\"" + " y=\"" + str(y) + "\" zumbadores=\"" + str(beepers) + "\"></monton>\n"
    return beeper

def setSizeWorld(w, h):
    sizeWorld = "\t<mundo nombre=\"mundo_0\" ancho=\"" + str(w) + "\" alto=\"" + str(h) + "\">\n\""
    return sizeWorld

def case(sub):
    file = open(sub+"in", "w")
    start = """<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
    """
    end = """
    </mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{$2$}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
			<despliega tipo="MUNDO"></despliega>
		</programa>
	</programas>
</ejecucion>
    """
    file.write(start)
    print("Introduce el tamaño del mundo")
    N,M = input().split()
    N = int(N)
    M = int(M)
    sizeWorld = setSizeWorld(N,M)
    file.write(sizeWorld)
    beepers = list(range(2, N+1))
    proov = list(range(2, M+1))
    used = list()
    noTouch = set()
    print("How many reals will be")
    K = int(input())
    for i in range(K):
        x = random.choice(beepers)
        beepers.remove(x)
        y = random.choice(proov)
        proov.remove(y)
        noTouch.add(x)
        used.append( (x, y) )
        beeper = putbeeper(x, y, 1)
        file.write(beeper)
    print("How many fakes will be")
    K = int(input())
    i = 0
    while i != K:
        (x,y) = random.choice(used)
        p = random.randint(2, M+1)
        while p in noTouch:
            p = random.randint(2, M+1)
        noTouch.add(p)
        beeper = putbeeper(p, y, 1)
        file.write(beeper)
        i += 1
   
    file.write("\t\t</mundo>")
    file.write(end)
    file.close()

'''
    Como utilizarlo:
        Para utilizarlo primero se pide el caso que se cambiara
        Ingresaras primero la cantidad de columnas y luego la cantidad de filas
        Ingresas la respuesta que deseas que sea
        y por ultimo están los "fake", estos son respuestas que son de un proveedor ya contado
'''

print("Select the case that you'll change")
caso = int(input())
for i in range(caso,caso+1):
    case("sub1."+str(i)+".")


