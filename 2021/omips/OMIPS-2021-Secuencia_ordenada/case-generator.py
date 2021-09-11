import random

def case(sub, N, K):
    file = open(sub+"in", "w")
    start = """<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000"></condiciones>
	<mundos>
    """
    end = """
    </mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{$2$}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="INFINITO">
			<despliega tipo="ORIENTACION"></despliega>
            <despliega tipo="AVANZA"></despliega>
		</programa>
	</programas>
</ejecucion>
    """
    file.write(start)
    sizeWorld = """\t<mundo nombre="mundo_0" ancho="100" alto="100">\n"""
    file.write(sizeWorld)

    if( 1<=K<=N): 
        #Cuanto crecera
        jump = random.randint(1,10)
        if jump > 6: jump = random.randint(1,10)
        last = random.randint(10,40)
        if K == 1: last = random.randint(50,99)
        for i in range(1,K+1):
            x = i
            y = 1
            value = min(99, last + random.randint(0, jump) )
            beeper = "\t\t\t<monton x=\"" + str(x) + "\"" + " y=\"" + str(y) + "\" zumbadores=\"" + str(value) + "\"></monton>\n"
            last = value
            file.write(beeper)
        for i in range(K+1,N+1):
            x = i
            y = 1
            value = max(1, last - random.randint(0, jump) )
            beeper = "\t\t\t<monton x=\"" + str(x) + "\"" + " y=\"" + str(y) + "\" zumbadores=\"" + str(value) + "\"></monton>\n"
            last = value
            file.write(beeper)
    else :
        print("Error file " + str(sub))
    file.write("\t\t</mundo>")
    file.write(end)
    file.close()

'''
    Como utilizarlo:
        En este caso hice que diera una secuencia que siempre sea correcta, N es el tamaño de la fila de beepers y K es donde sera el "pico"
        Cada 8 casos 4 son hechos por ti mismo y los otros 4 son aleatorios, aunque siempre vas a elegir tu el "pico" para hacerlo a tu gusto la "dificultad"

    Si quieres ajustar el jump que es el salto entre cada par consecutivo de beepers  es en la linea 25
'''



#Casos 0 a 7 primer grupo donde si es valido
for i in range(8):
    if i < 4:
        N = int(input())
    else : 
        N = random.randint(1,100)
    print("Size of the case " + str(N))
    K = int(input())    
    case("sub"+str(int(i/16))+"."+str(i)+".", N, K)

#Casos 8 a 15 segundo grupo donde no es valido 
for i in range(8, 16):
    if i < 12:
        N = int(input())
    else : 
        N = random.randint(1,100)
    print("Size of the case " + str(N))
    K = int(input())
    case("sub"+str(int(i/16))+"."+str(i)+".", N, K)

#Casos 16 a 23 segundo grupo donde si es valido y se necesitan N movimientos
for i in range(16,24):
    if i < 20:
        N = int(input())
    else : 
        N = random.randint(1,100)
    print("Size of the case " + str(N))
    K = int(input())
    case("sub"+str(int(i/16))+"."+str(i)+".", N, K)

#Casos 24 a 31 segundo grupo donde no es valido y se necesitan N movimientos
for i in range(24, 32):
    if i < 28:
        N = int(input())
    else : 
        N = random.randint(1,100)
    print("Size of the case " + str(N))
    K = int(input())
    case("sub"+str(int(i/16))+"."+str(i)+".", N, K)
