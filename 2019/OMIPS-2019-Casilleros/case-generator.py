casos = [1, 25, 37, 50, 2691, 3997, 4002, 4618, 5000]
caso = 1
for n in casos:
    mundo = """<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="10000000" longitudStack="65000">
		<comando nombre="AVANZA" maximoNumeroDeEjecuciones="5000"/>
	</condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="{0}" alto="1"></mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{1}" mundoDeEjecucion="mundo_0" xKarel="1" yKarel="1" direccionKarel="NORTE" mochilaKarel="{0}">
			<despliega tipo="UNIVERSO"></despliega>
		</programa>
	</programas>
</ejecucion>
    """.format(n, "{$2$}")

    file = open("{}.in".format(caso), "w")
    caso += 1
    file.write(mundo)
    file.close()
