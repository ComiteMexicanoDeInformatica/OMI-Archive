# encoding: utf-8
import KarelWorld

import random
#random.seed(10)

numDias=[10,15,25,50,75,100]
X=[1,-1,1,-1]
Y=[1,1,-1,-1]

#Casos de 17 puntos
for case in range(0,2) :
	n=random.randint(1,25)
	xOrigen=random.randint(1,50)
	yOrigen=random.randint(1,50)
	world=KarelWorld.KarelWorld()
	# Columna, fila, cantidad de beepers
	world.addBeepers(1,2,xOrigen)
	world.addBeepers(2,2,yOrigen)
	world.setInfinityBeeperBag(True)
	# Máscara para evaluar la orientación final de Karel.
	world.setConditionsBitmask(2)
	for i in range(1,n+1) :
		direccion=1
		world.addBeepers(i,1,direccion)
		if direccion == 1 :	#Norte
			yOrigen+=1
		elif direccion == 2:	#Oeste
			xOrigen-=1
		elif direccion == 3:	#Sur
			yOrigen-=1
		else :	#Este
			xOrigen+=1
	distanciaManhattan=random.randint(1,n)
	cAdyacente=random.randint(1,distanciaManhattan)
	cOpuesto=distanciaManhattan-cAdyacente
	for j in range(0,4) :
		xObjetivo=xOrigen+cAdyacente*X[j]
		yObjetivo=yOrigen+cOpuesto*Y[j]
		if 1 <= xObjetivo and xObjetivo <= 100 and 1 <= yObjetivo and yObjetivo <=100 :
			world.addBeepers(1,3,xObjetivo)
			world.addBeepers(2,3,yObjetivo)
	# Imprime el mundo en el archivo case.Norte.in
	world.writeWorld(str(case)+".Norte.in") 

for case in range(0,2) :
	n=random.randint(1,25)
	xOrigen=random.randint(1,50)
	yOrigen=random.randint(1,50)
	world=KarelWorld.KarelWorld()
	# Columna, fila, cantidad de beepers
	world.addBeepers(1,2,xOrigen)
	world.addBeepers(2,2,yOrigen)
	world.setInfinityBeeperBag(True)
	# Máscara para evaluar la orientación final de Karel.
	world.setConditionsBitmask(2)
	for i in range(1,n+1) :
		direccion=1
		world.addBeepers(i,1,direccion)
		if direccion == 1 :	#Norte
			yOrigen+=1
		elif direccion == 2:	#Oeste
			xOrigen-=1
		elif direccion == 3:	#Sur
			yOrigen-=1
		else :	#Este
			xOrigen+=1
	distanciaManhattan=n+1
	cAdyacente=random.randint(1,distanciaManhattan)
	cOpuesto=distanciaManhattan-cAdyacente
	for j in range(0,4) :
		xObjetivo=xOrigen+cAdyacente*X[j]
		yObjetivo=yOrigen+cOpuesto*Y[j]
		if 1 <= xObjetivo and xObjetivo <= 100 and 1 <= yObjetivo and yObjetivo <=100 :
			world.addBeepers(1,3,xObjetivo)
			world.addBeepers(2,3,yObjetivo)
	# Imprime el mundo en el archivo case.Norte.in
	world.writeWorld(str(case)+".Sur.in") 

#Casos de 83 puntos
case=4
for n in numDias :
	xOrigen=random.randint(1,100)
	yOrigen=random.randint(1,100)
	world=KarelWorld.KarelWorld()
	# Columna, fila, cantidad de beepers
	world.addBeepers(1,2,xOrigen)
	world.addBeepers(2,2,yOrigen)
	world.setInfinityBeeperBag(True)
	# Máscara para evaluar la orientación final de Karel.
	world.setConditionsBitmask(2)
	for i in range(1,n+1) :
		direccion=random.randint(1,4)
		world.addBeepers(i,1,direccion)
		if direccion == 1 :	#Norte
			yOrigen+=1
		elif direccion == 2:	#Oeste
			xOrigen-=1
		elif direccion == 3:	#Sur
			yOrigen-=1
		else :	#Este
			xOrigen+=1
	distanciaManhattan=random.randint(1,n)
	cAdyacente=random.randint(1,distanciaManhattan)
	cOpuesto=distanciaManhattan-cAdyacente
	for j in range(0,4) :
		xObjetivo=xOrigen+cAdyacente*X[j]
		yObjetivo=yOrigen+cOpuesto*Y[j]
		if 1 <= xObjetivo and xObjetivo <= 100 and 1 <= yObjetivo and yObjetivo <=100 :
			world.addBeepers(1,3,xObjetivo)
			world.addBeepers(2,3,yObjetivo)
	# Imprime el mundo en el archivo case.Norte.in
	world.writeWorld(str(case)+".Norte.in") 
	case+=1	

case=4
for n in numDias :
	xOrigen=random.randint(1,100)
	yOrigen=random.randint(1,100)
	world=KarelWorld.KarelWorld()
	# Columna, fila, cantidad de beepers
	world.addBeepers(1,2,xOrigen)
	world.addBeepers(2,2,yOrigen)
	world.setInfinityBeeperBag(True)
	# Máscara para evaluar la orientación final de Karel.
	world.setConditionsBitmask(2)
	for i in range(1,n+1) :
		direccion=random.randint(1,4)
		world.addBeepers(i,1,direccion)
		if direccion == 1 :	#Norte
			yOrigen+=1
		elif direccion == 2:	#Oeste
			xOrigen-=1
		elif direccion == 3:	#Sur
			yOrigen-=1
		else :	#Este
			xOrigen+=1
	distanciaManhattan=n+1
	cAdyacente=random.randint(1,distanciaManhattan)
	cOpuesto=distanciaManhattan-cAdyacente
	for j in range(0,4) :
		xObjetivo=xOrigen+cAdyacente*X[j]
		yObjetivo=yOrigen+cOpuesto*Y[j]
		if 1 <= xObjetivo and xObjetivo <= 100 and 1 <= yObjetivo and yObjetivo <=100 :
			world.addBeepers(1,3,xObjetivo)
			world.addBeepers(2,3,yObjetivo)
	# Imprime el mundo en el archivo case.Norte.in
	world.writeWorld(str(case)+".Sur.in") 
	case+=1	
