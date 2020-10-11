import os
import random

#Subtask 1: 20 puntos (0<=N,Q,x,y<=100) -> 20 casos
#-caso de prueba:
#   here your path
path = "/home/jose_juan__se/Documentos/Github/COMI-2020/omi/distancia/cases/"
file = open(path+"20.0.in","w")
prueba = """3 2
1 5
4 5
6 10
5 5
3 3
"""
file.write(prueba)
file.close()
for i in range(19):
    n = random.randint(1,100)
    q = random.randint(1,100)
    file = open(path+"20."+str(i+1)+".in","w")
    file.write(str(n)+" "+str(q)+'\n')
    for j in range(n+q):
        x = random.randint(0,100)
        y = random.randint(0,100)
        file.write(str(x)+" "+str(y)+'\n')
    file.close()
#-resto de casos
#Subtask 2: 35 puntos (0<=N,Q<=1000) -> 20 casos
for i in range(20):
    n = random.randint(1,1000)
    q = random.randint(1,1000)
    file = open(path+"35."+str(i)+".in","w")
    file.write(str(n)+" "+str(q)+'\n')
    for j in range(n+q):
        x = random.randint(0,1000)
        y = random.randint(0,1000)
        file.write(str(x)+" "+str(y)+'\n')
    file.close()
#Subtask 3: 45 puntos (0<=N,Q<=10^5 and 0<=x,y<=10000) -> 20 casos
for i in range(19):
    n = random.randint(1,100000)
    q = random.randint(1,100000)
    file = open(path+"45."+str(i)+".in","w")
    file.write(str(n)+" "+str(q)+'\n')
    for j in range(n+q):
        x = random.randint(0,1000)
        y = random.randint(0,1000)
        file.write(str(x)+" "+str(y)+'\n')
    file.close()
#ultimo caso especial propuesto por kishtarn555
n = 100000
q = 100000
s = 0
file = open(path+"45.19.in","w")
file.write(str(n)+" "+str(q)+'\n')
for i in range(0,100):
    for j in range(0,1000):
        file.write(str(i)+" "+str(j)+'\n')
        s+=1
for i in range(0,n+q-s):
    x = random.randint(0,1000)
    y = random.randint(0,1000)
    file.write(str(x)+" "+str(y)+'\n')
file.close()
