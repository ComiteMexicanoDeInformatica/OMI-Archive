import random

MAXN = random.randint(1, 100000)
LIM = random.randint(1, 1000000000)
SUBTASK = 2

file = open('case.in', 'w')

def operacion(x, i):
    if SUBTASK == 1:
        return x + random.randint(0, 1)
    elif SUBTASK == 2:
        if i == 0:
            return x
    return x + random.randint(-1, 1)

n = random.randint(1, MAXN)

semilla = random.randint(1, LIM-n)
k = random.randint(-(semilla/n), (LIM-semilla)/n)

file.write(str(n)+'\n')

x = semilla
arr = []
for i in range(n):
    arr += [x]
    x += k

modified = [0] * n
ansAprox = random.randint(0, n)
for i in range(ansAprox):
    p = random.randint(0, n-1)
    if modified[p] == 0:
        x = arr[p]
        arr[p] = operacion(arr[p], p)
        modified[p] = 1

file.write(' '.join(map(str, arr)) + '\n')
