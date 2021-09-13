import random

def putbeeper(x, y, beepers):
    beeper = "\t\t\t<monton x=\"" + str(x) + "\"" + " y=\"" + str(y) + "\" zumbadores=\"" + str(beepers) + "\"></monton>\n"
    return beeper

def setSizeWorld(w, h):
    sizeWorld = "\t<mundo nombre=\"mundo_0\" ancho=\"" + str(w) + "\" alto=\"" + str(h) + "\">\n"
    return sizeWorld

def case(sub, xS, yS):
    file = open(sub+"in", "w")
    start = """<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
    """
    end = """
    </mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
    """
    
    startK = "<programa nombre=\"p1\" ruta=\"{$2$}\" mundoDeEjecucion=\"mundo_0\" xKarel=\"" + str(xS) + "\" yKarel=\"" + str(yS) +"\" direccionKarel=\"NORTE\" mochilaKarel=\"INFINITO\">"
    
    end2 = """
			<despliega tipo="MUNDO"></despliega>
		</programa>
	</programas>
</ejecucion>
    """
    file.write(start)
    N = random.randint(yS+5, 100)
    M = random.randint(xS+5, 100)
    sizeWorld = setSizeWorld(M,N)
    file.write(sizeWorld)
    x = random.randint(xS, M)
    y = random.randint(yS, N)
    beeper = putbeeper(x, y, 1)
    file.write(beeper)
    file.write("\t\t\t<posicionDump x=\"1\" y=\"1\"></posicionDump>\n")
    file.write("\t\t</mundo>")
    file.write(end)
    file.write(startK)
    file.write(end2)
    file.close()

'''
    Como utilizarlo:
        nada mas es correr el code
'''

for i in range(22,23):
    if i < 11:
        case("sub1."+str(i)+".", 1, 1)
    else :
        print("Inicio de karel")
        x = random.randint(10,45)
        y = random.randint(10,45)
        case("sub2."+str(i)+".", x, y)


