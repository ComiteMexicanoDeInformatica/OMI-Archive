import os
import random


testplan = open("testplan", "w")


def generate(amount, limitN, imposible, subtask):
    # Verificar puntajes y si van agrupados
    for i in range(amount):
        print("Subtask: ", subtask, "  Case: ", i, end=" \r")
        points = 0
        if i == 0:
            points = amount
        testplan.write(subtask+"."+str(i+1)+" "+str(points)+'\n')

        N = random.randint(2, limitN)
        K = random.randint(0, N)

        file = open("cases/"+subtask+"."+str(i+1)+".in", "w")
        file.write(str(N)+" "+str(K)+'\n')

        k = []
        lastK = -1
        for j in range(K):
            if imposible:
                k.append(random.randint(0, 1e6))
            else:
                lastK = random.randint(lastK+1, 1e6-K+j)
                k.append(lastK)

        kp = []
        lastKp = 0
        if imposible:
            for j in range(1, N+1):
                kp.append(j)
            random.shuffle(kp)
            for j in range(N-K):
                kp.pop()
        else:
            for j in range(1, K+1):
                if N == K:
                    lastKp = j
                else:
                    lastKp = random.randint(lastKp+1, N-K+j)
                kp.append(lastKp)

        ki = 0
        for j in range(N):
            if len(kp) > ki and j == kp[ki]:
                file.write(str(k[ki]))
                ki += 1
            else:
                file.write(str(random.randint(0, 1e6)))
            if j < N-1:
                file.write(" ")
        file.write('\n')

        if K:
            random.shuffle(kp)
            for j in range(K):
                file.write(str(kp[j]))
                if j < K-1:
                    file.write(" ")
            file.write('\n')

        file.close()


# Subtask 1: 25 puntos $N \leq 20$ y no hay ninguna escalera que no se pueda restaurar. -> 25 casos
generate(33, 20, False, "sub1")

# Subtask 2: 25 puntos $N \leq 1000$ -> 25 casos
generate(33, 1000, True, "sub2")

# Subtask 3: 25 puntos Sin restricciones adicionales -> 25 casos
generate(34, 1e5, True, "sub3")


testplan.close
