import random

#Genera casos muy faciles
for caso in range(0, 5):
    nam = 'veasy.' + str(caso) + '.in'
    N = random.randint(2, 5)
    Ka = random.randint(0, N)
    Kb = random.randint(0, N)
    cs = open(nam, 'w')
    cs.write(str(N) + ' ' + str(Ka)+ ' ' + str(Kb) + '\n')

#Genera casos faciles
for caso in range(0, 5):
    nam = 'easy.' + str(caso) + '.in'
    N = random.randint(6, 16)
    Ka = random.randint(0, N)
    Kb = random.randint(0, N)
    cs = open(nam, 'w')
    cs.write(str(N) + ' ' + str(Ka)+ ' ' + str(Kb) + '\n')
    
#Genera casos medios
for caso in range(0, 10):
    nam = 'med.' + str(caso) + '.in'
    N = random.randint(17, 32)
    Ka = random.randint(0, N)
    Kb = random.randint(0, N)
    cs = open(nam, 'w')
    cs.write(str(N) + ' ' + str(Ka)+ ' ' + str(Kb) + '\n')

#Genera casos dificiles
for caso in range(0, 10):
    nam = 'hard.' + str(caso) + '.in'
    N = random.randint(33, 200)
    Ka = random.randint(0, N)
    Kb = random.randint(0, N)
    cs = open(nam, 'w')
    cs.write(str(N) + ' ' + str(Ka)+ ' ' + str(Kb) + '\n')

#Genera casos muy dificiles
for caso in range(0, 10):
    nam = 'vhard.' + str(caso) + '.in'
    N = random.randint(201, 5000)
    Ka = random.randint(0, N)
    Kb = random.randint(0, N)
    cs = open(nam, 'w')
    cs.write(str(N) + ' ' + str(Ka)+ ' ' + str(Kb) + '\n')
