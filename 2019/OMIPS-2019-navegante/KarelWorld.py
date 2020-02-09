# encoding: utf-8

class KarelWorld:

	__directions=["NORTE","ESTE","SUR","OESTE"]
	__conditions=["POSICION","ORIENTACION","MOCHILA","UNIVERSO","MUNDO"]
	__commands=["AVANZA","GIRA_IZQUIERDA","COGE_ZUMBADOR","DEJA_ZUMBADOR"]
	
	def __init__(self):
		self.__beepers={}
		self.__horizontalWalls=set()
		self.__verticalWalls=set()
		self.__dumpPositions=set()
		self.__bitmaskConditions=0
		self.__bitmaskCommands=0
		self.__xKarel=1
		self.__yKarel=1
		self.__karelDirection=0
		self.__infinityBeeperBag= False
		self.__beeperBag=0
		self.__width=100
		self.__height=100
		self.__maxCommands=10000000
		self.__stackLength=65000
	
	""" 	Método que guarda el XML del mundo en un archivo.
	
	Args:
		fileName (str):	nombre del archivo donde se guardará el mundo.
				Si el nombre no se especifica entonces el mundo
				se guardará en el archivo default.in
	"""
	def writeWorld(self, fileName="default.in"):
		baseWorld="""<ejecucion>
	<condiciones instruccionesMaximasAEjecutar="{$maxCommands$}" longitudStack="{$stackLength$}"></condiciones>
	<mundos>
		<mundo nombre="mundo_0" ancho="{$width$}" alto="{$heigth$}">
{$beepers$}
{$walls$}
{$dumpPosition$}
		</mundo>
	</mundos>
	<programas tipoEjecucion="CONTINUA" intruccionesCambioContexto="1" milisegundosParaPasoAutomatico="0">
		<programa nombre="p1" ruta="{$2$}" mundoDeEjecucion="mundo_0" xKarel="{$xKarel$}" yKarel="{$yKarel$}" direccionKarel="{$karelDirection$}" mochilaKarel="{$beeperBag$}">
{$conditions$}
{$commands$}
		</programa>
	</programas>
</ejecucion>"""
		baseWorld=baseWorld.replace("{$maxCommands$}",str(self.__maxCommands))
		baseWorld=baseWorld.replace("{$stackLength$}",str(self.__stackLength))
		baseWorld=baseWorld.replace("{$width$}",str(self.__width))
		baseWorld=baseWorld.replace("{$heigth$}",str(self.__height))
		baseWorld=baseWorld.replace("{$xKarel$}",str(self.__xKarel))
		baseWorld=baseWorld.replace("{$yKarel$}",str(self.__yKarel))
		baseWorld=baseWorld.replace("{$karelDirection$}",self.__directions[self.__karelDirection])
		
		if self.__infinityBeeperBag :
			baseWorld=baseWorld.replace("{$beeperBag$}","INFINITO")
		else :
			baseWorld=baseWorld.replace("{$beeperBag$}",str(self.__beeperBag))
		
		dumpPositionsList=""
		for x,y in self.__dumpPositions :
			dumpBase="""\t\t\t<posicionDump x="{$x$}" y="{$y$}"></posicionDump>"""
			dumpBase=dumpBase.replace("{$x$}",str(x))
			dumpBase=dumpBase.replace("{$y$}",str(y))
			dumpPositionsList+=dumpBase+"\n"
			
		baseWorld=baseWorld.replace("{$dumpPosition$}",dumpPositionsList)
		
		beepersList=""
		for x,y in self.__beepers.keys() :
			beepersBase="""\t\t\t<monton x="{$x$}" y="{$y$}" zumbadores="{$value$}"></monton>"""
			beepersBase=beepersBase.replace("{$x$}",str(x))
			beepersBase=beepersBase.replace("{$y$}",str(y))
			if self.__beepers[(x,y)] == -1:
				beepersBase=beepersBase.replace("{$value$}","INFINITO")
			else:
				beepersBase=beepersBase.replace("{$value$}",str(self.__beepers[(x,y)]))
			beepersList+=beepersBase+"\n"
			
		baseWorld=baseWorld.replace("{$beepers$}",beepersList)
		
		wallsList=""
		for x1,x2,y1 in self.__horizontalWalls:
			wallBase="""\t\t\t<pared x1="{$x1$}" y1="{$y1$}" x2="{$x2$}"></pared>"""
			wallBase=wallBase.replace("{$x1$}",str(x1))
			wallBase=wallBase.replace("{$y1$}",str(y1))
			wallBase=wallBase.replace("{$x2$}",str(x2))
			wallsList+=wallBase+"\n"
		
		for x1,y1,y2 in self.__verticalWalls :
			wallBase="""\t\t\t<pared x1="{$x1$}" y1="{$y1$}" y2="{$y2$}"></pared>"""
			wallBase=wallBase.replace("{$x1$}",str(x1))
			wallBase=wallBase.replace("{$y1$}",str(y1))
			wallBase=wallBase.replace("{$y2$}",str(y2))
			wallsList+=wallBase+"\n"
			
		baseWorld=baseWorld.replace("{$walls$}",wallsList)
		
		conditionsList=""
		for i in range(0,5) :
			if self.__bitmaskConditions & (1<<i) :
				
				baseCondition="""\t\t\t<despliega tipo="{$condition$}"></despliega>"""
				baseCondition=baseCondition.replace("{$condition$}",self.__conditions[i])
				conditionsList+=baseCondition+"\n"
				
		baseWorld=baseWorld.replace("{$conditions$}",conditionsList)
		
		commandsList=""
		for i in range (0,4) :
			if self.__bitmaskCommands & (1<<i) :
				baseCondition="""\t\t\t<despliega tipo="{$condition$}"></despliega>"""
				baseCondition=baseCondition.replace("{$condition$}",self.__commands[i])
				commandsList+=baseCondition+"\n"
		
		baseWorld=baseWorld.replace("{$commands$}",commandsList)
		
		f = open(fileName, "w")
		f.write(baseWorld.strip())
		f.close()
	
	""" 	Método que agrega/cambia un montón de zumbadores al mundo.
		
	Args:
		x (int): 	columna de la casilla.
		y (int):	fila de la casilla.
		value (int):	cantidad de zumbadores de la casilla.
				Para especificar un montón de zumbadores INFINITO
				el valor de este parámetro debe ser -1.
	
	"""	
	def addBeepers(self,x,y,value):
		self.__beepers[(x,y)]=value
		
	""" 	Método que elimina un montón de zumbadores del mundo.
	
	Args:
		x (int): columna de la casilla.
		y (int): fila de la casilla.
		
	"""
	def removeBeepers(self,x,y):
		del self.__beepers[(x,y)]
	
	"""	Método que devuelve la cantidad de beepers en una casilla del mundo.
	
	Args:
		x (int): columna de la casilla.
		y (int): fila de la casilla.
	
	Returns:
		Cantidad de beepers en la casilla x,y.
	
	"""
	def getBeepers(self,x,y):
		return self.__beepers[(x,y)]
	
	""" 	Método que agrega una pared al mundo.
	
		Para agregar una pared al mundo se tiene que especificar una 
		casilla del mundo y una dirección.
	
		NORTE: 0
		ESTE:  1
		SUR:   2
		OESTE: 3
	
		Ej. addWall(2,3,1) agrega una pared al ESTE de la casilla 2,3.
	
	Args:
		x (int): columna de la casilla.
		y (int): fila de la casilla.
		direction (int): dirección de la pared en la casilla.
	
	"""
	def addWall(self,x,y,direction):
		if direction == 0 :
			self.__horizontalWalls.add((x-1,x,y))
		elif direction == 1 :
			self.__verticalWalls.add((x-1,y-1,y))
		elif direction == 2 :
			self.__horizontalWalls.add((x-1,x,y-1))
		else :
			self.__verticalWalls.add((x,y-1,y))

	""" 	Método que elimina una pared del mundo.
	
		Para eliminar una pared del mundo se tiene que especificar una
		casilla del mundo y una dirección.
	
		NORTE : 0
		ESTE  : 1
		SUR   : 2
		OESTE : 3
	
		Ej. addWall(2,3,1) agrega una pared al ESTE de la casilla 2,3.
	
	Args:
		x (int): columna de la casilla.
		y (int): fila de la casilla.
		direction (int): dirección de la pared en la casilla.
	
	"""
	def removeWall(self,x,y,direction):
		if direction == 0 :
			self.__horizontalWalls.remove((x-1,x,y))
		elif direction == 1 :
			self.__verticalWalls.remove((x-1,y-1,y))
		elif direction == 2 :
			self.__horizontalWalls.remove((x-1,x,y-1))
		else :
			self.__verticalWalls.remove((x,y-1,y))
	
	"""	Método que agrega una posición dump al mundo.
		Si existe al menos una posición dump la máscara de bits de las
		condiciones tendrá encendido el bit de la condición MUNDO.
	
	Args:
		x (int): columna de la casilla.
		y (int): fila de la casilla.
	
	"""
	def addDumpPosition(self,x,y) :
		self.__dumpPositions.add((x,y))
		self.__bitmaskConditions|=16
	
	"""	Método que elimina una posición dump del mundo.
		Si existe al menos una posición dump la máscara de bits de las
		condiciones tendrá encendido el bit de la condición MUNDO.
	
	Args:
		x (int): columna de la casilla.
		y (int): fila de la casilla.
		
	"""	
	def removeDumpPosition(self,x,y) :
		self.__dumpPositions.remove((x,y))
		if len(self.__dumpPositions) == 0 :
			self.__bitmaskConditions&=~16
	
	"""	Método que cambia la máscara de bits de las condiciones de
		evaluación.
		
		Valores de la máscara de bits:
		
		POSICION    : 1
		ORIENTACION : 2
		MOCHILA     : 4
		UNIVERSO    : 8
		MUNDO       : 16
		
	Args:
		bitmask (int): máscara de bits de las condiciones de evaluación.
		
	"""
	def setConditionsBitmask(self,bitmask) :
		self.__bitmaskConditions=bitmask
		if len(self.__dumpPositions) > 0 :
			self.__bitmaskConditions|=16
		else :
			self.__bitmaskConditions&=~16
	
	"""	Método que devuelve la máscara de bits actual de las condiciones
		de evaluación.
		
	Returns:
		bitmaskConditions (int): máscara de bits de las condiciones de
					 evaluación.
	
	"""	
	def getConditionsBitmask(self) :
		return self.__bitmaskConditions
		
	"""	Método que cambia la máscara de bits de las instrucciones a las
		que se contará el número de veces que se ejecutó para la evaluación.
		
		Valores de la máscara de bits:
		
		AVANZA         : 1
		GIRA_IZQUIERDA : 2
		COGE_ZUMBADOR  : 4
		DEJA_ZUMBADOR  : 8
	
	Args:
		bitmask (int):	
	
	"""
	def setCommandsBitmask(self,bitmask) :
		self.__bitmaskCommands=bitmask
	
	"""	Método que devuelve la máscara de bits actual de las instrucciones
		a las cuales se contará el número de veces que se ejecutó para la
		evaluación.
		
	Returns:
		bitmaskCommands (int):	máscara de bits de las condiciones de
					evaluación.
	
	"""	
	def getCommandsBitmask(self) :
		return self.__bitmaskCommands
	
	"""	Método que cambia la ubicación inicial de Karel.
	
		Por defecto, la ubicación inicial es la casilla 1,1.
	
	Args:
		x (int): fila de la ubicación inicial de Karel.
		y (int): columna de la ubicación inicial de Karel.
	
	"""
	def setKarelLocation(self,x,y):
		self.__xKarel=x
		self.__yKarel=y
	
	"""	Método que devuelve la ubicación inicial de Karel.
		
	Returns:
		xKarel (int):	columna de la ubicación inicial de Karel.
		yKarel (int):	fila de la ubicación inicial de Karel.
	
	"""
	def getKarelLocation(self) :
		return (self.__xKarel,self.__yKarel)
	
	"""	Método que asigna la orientación inicial de Karel.
		La orientación por defecto es al NORTE.
		
		Valores para la dirección:
		
		NORTE : 0
		ESTE  : 1
		SUR   : 2
		OESTE : 3
		
	Args:
		direction (int): dirección inicial de Karel.
	
	"""
	def setKarelDirection(self,direction) :
		self.__karelDirection=direction
	
	"""	Método que devuelve la orientación inicial de Karel.
	
	Returns:
		direction (int): entero que representa la orientación inicial de
				 Karel.
	
	"""
	def getKarelDirection(self,direction) :
		return self.__karelDirection
	
	"""	Método que asigna/elimina el valor INFINITO de la mochila.
		
		Por defecto no hay infinitos zumbadores en la mochila.
	
	Args:
		flag (bool):	True significa que al inicio habrá infinitos
				zumbadores en la mochila, False significa lo
				contrario.
	
	"""
	def setInfinityBeeperBag(self,flag)  :
		self.__infinityBeeperBag=flag
		self.__beeperBag=-1
	
	"""	Método que asigna el valor inicial de la mochila de Karel.
	
	Args:
		value (int): 	valor inicial de zumbadores en la mochila de Karel.
				Si el valor es -1 significa que al inicio habrá
				infinitos zumbadores en la mochila.
	
	"""
	def setBeeperBag(self,value) :
		self.__beeperBag=value
		if value == -1:
			self.__infinityBeeperBag = True
		else :
			self.__infinityBeeperBag = False
	
	"""	Método que devuelve la cantidad de zumbadores en la mochila.
	
	Returns:
		beeperBag (int): cantidad de zumbadores en la mochila. Si hay
				 INFINITOS el valor devuelto es -1.
	
	"""
	def getBeeperBag(self) :
		return self.__beeperBag
	
	"""	Método que asigna las dimensiones del mundo.
		
	Args:
		width (int): 	número de columnas del mundo.
		height (int):	número de filas del mundo.
	
	"""
	def setWorldDimentions(self,width,height) :
		self.__width=width
		self.__height=heigth
		
	"""	Método que devuelve las dimensiones del mundo.
	
	Returns:
		width (int): 	número de columnas del mundo.
		height (int):	número de filas del mundo.
	
	"""
	def getWorldDimentions(self) :
		return (self.__width,self.__height)
	
	"""	Método que asigna la cantidad máxima de instrucciones que pueden
		ejecutarse.
		
		Por defecto el valor es de 10000000.
		
	Args:
		maxCommands (int): cantidad máxima de instrucciones que pueden
				   ejecutarse.
	
	"""
	def setMaxCommands(self,maxCommands) :
		self.__maxCommands=maxCommands
	
	"""	Método que regresa la cantidad máxima de instrucciones que pueden
		ejecutarse.
	
	Returns:
		maxCommands (int): cantidad máxima de instrucciones que pueden
				   ejecutarse.
	
	"""	
	def getMaxCommands(self) :
		return self.__maxCommands
	
	"""	Método que asigna la longitud de la pila.
	
		Por defecto la longitud es de 65000.
	
	Args:
		stackLength (int): longitud de la pila.
	
	"""
	def setStackLength(self,stackLength) :
		self.__stackLength=stackLength

	"""	Método que devuelve la longitud de la pila.
	
	Returns:
		stackLength (int): longitud de la pila.
	
	"""
	def getStackLength(self) :
		return self.__stackLength
