import os
import random


testplan = open("testplan", "w")


def generate(points, amount, limitN, subtask):
	# Verificar puntajes y si van agrupados
	for i in range(amount):
		print("Subtask: ", subtask, "  Case: ", i, end=" \r")
		if i == 0:
			testplan.write(subtask+"."+str(i+1)+" "+str(points)+'\n')
		else:
			testplan.write(subtask + "." + str(i + 1) + " 0\n")

		N = random.randint(limitN // 2, limitN)
		
		fijos = []
		k = 0
		while (k < N):
			k = random.randint(k + 1, N)
			if k <= N:
				fijos.append(k)
			
		K = len(fijos)

		file = open("cases/"+subtask+"."+str(i+1)+".in", "w")
		file.write(str(N)+" "+str(K)+'\n')

		escalera = []
		for i in range(N):
			escalera.append(i)
			
		for fijo in fijos:
			escalera[fijo - 1] = fijo * 10
			
		for i in range(K):
			if i == 0:
				prev = 0
				ini = 0
			else:
				prev = escalera[fijos[i - 1] - 1]
				ini = fijos[i - 1]
			fin = fijos[i] - 2
				
			val = 0
			signo = 1
			if ini <= fin:
				for pos in range(ini, fin):
					delta = random.randint(0, escalera[fijos[i] - 1] - prev)
					delta *= signo
					signo *= -1
					val += delta
					if val < 0:
						val = 0
					escalera[pos] = val
					prev = val // (fin - ini + 1)
			ult = fijos[i]
		
		st = ""
		for escalon in escalera:
			st += str(escalon) + " ";
		file.write(st + "\n")

		st = ""
		for fijo in fijos:
			st += str(fijo) + " ";
		file.write(st + "\n")

		file.close()
		
def generate_invalid(firstcase, subtask):
	
	# Espacio insuficiente entre escalones fijos
	testplan.write(subtask + "." + str(firstcase) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase) + ".in", "w")
	file.write("10 3\n5 3 6 8 10 9 6 12 15 3\n3 5 8\n")
	file.close()
	
	# Escalones fijos desordenados
	testplan.write(subtask + "." + str(firstcase + 1) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 1) + ".in", "w")
	file.write("10 3\n5 3 10 8 6 9 6 14 15 3\n3 5 8\n")
	file.close()
	
	# Espacio insuficiente entre el primer fijo y el inicio
	testplan.write(subtask + "." + str(firstcase + 2) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 2) + ".in", "w")
	file.write("10 3\n5 3 1 10 6 9 6 14 15 3\n3 5 8\n")
	file.close()
	

def generate_defaults(firstcase, subtask):
	
	# Cero escalones fijos
	testplan.write(subtask + "." + str(firstcase) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase) + ".in", "w")
	file.write("5 0\n4 3 1 2 3\n")
	file.close()
	
	# Un escalon fijo en medio
	testplan.write(subtask + "." + str(firstcase + 1) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 1) + ".in", "w")
	file.write("10 1\n1 3 5 6 12 9 8 10 13 15\n4\n")
	file.close()
	
	# Un escalon fijo al inicio
	testplan.write(subtask + "." + str(firstcase + 2) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 2) + ".in", "w")
	file.write("10 1\n1 3 5 6 12 9 8 10 13 15\n1\n")
	file.close()
	
	# Un escalon fijo al final
	testplan.write(subtask + "." + str(firstcase + 3) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 3) + ".in", "w")
	file.write("10 1\n1 3 5 6 12 9 8 10 13 15\n10\n")
	file.close()
	
	# Dos fijos, al inicio y en medio
	testplan.write(subtask + "." + str(firstcase + 4) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 4) + ".in", "w")
	file.write("10 2\n1 3 5 6 12 9 8 10 13 15\n1 4\n")
	file.close()
	
	# Dos fijos, en medio y al final
	testplan.write(subtask + "." + str(firstcase + 5) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 5) + ".in", "w")
	file.write("10 2\n1 3 5 6 12 9 8 10 13 15\n4 10\n")
	file.close()
	
	# Dos fijos, al inicio y al final
	testplan.write(subtask + "." + str(firstcase + 6) + " 0\n")
	file = open("cases/" + subtask + "." + str(firstcase + 6) + ".in", "w")
	file.write("10 2\n1 3 5 6 12 9 8 10 13 15\n1 10\n")
	file.close()
	


# Subtask 1: 25 puntos $N \leq 20$ y no hay ninguna escalera que no se pueda restaurar. -> 25 casos
generate(23, 25, 20, "sub1")
generate_defaults(21, "sub1")

# Subtask 2: 25 puntos $N \leq 1000$ -> 25 casos
generate(37, 25, 1000, "sub2")
generate_invalid(26, "sub2")
generate_defaults(29, "sub2")

# Subtask 3: 25 puntos Sin restricciones adicionales -> 25 casos
generate(40, 25, 1e5, "sub3")
generate_invalid(26, "sub3")
generate_defaults(29, "sub3")


testplan.close
