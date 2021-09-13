import os
import random


testplan = open("testplan", "w")


def generate(amount, limitN, limitFC, limitE, subtask):
    # Verificar puntajes y si van agrupados
    for i in range(amount):
        print("Subtask: ", subtask, "  Case: ", i, end=" \r")
        points = 0
        if i == 0:
            points = amount
        testplan.write(subtask+"."+str(i+1)+" "+str(points)+'\n')

        F = random.randint(3, limitFC)
        C = random.randint(3, limitFC)
        N = random.randint(1, min(limitN, F*C-1))
        E = random.randint(1, limitE)

        file = open("cases/"+subtask+"."+str(i+1)+".in", "w")
        file.write(str(N)+" "+str(F)+" "+str(C)+'\n')

        mirrorSet = set()
        for j in range(N):
            d = random.randint(0, 1)
            char = ""
            if d:
                char = "\\"
            else:
                char = "/"
            x = random.randint(1, F)
            y = random.randint(1, C)
            while tuple([x, y]) in mirrorSet:
                x = random.randint(1, F)
                y = random.randint(1, C)
            mirrorSet.add(tuple([x, y]))

            file.write(char+" "+str(x)+" "+str(y)+'\n')

        file.write(str(E)+'\n')

        for j in range(E):
            d = random.randint(0, 3)
            char = ""
            if d == 0:
                char = "N"
            elif d == 1:
                char = "S"
            elif d == 2:
                char = "E"
            elif d == 3:
                char = "O"
            x = random.randint(1, F)
            y = random.randint(1, C)
            while tuple([x, y]) in mirrorSet:
                x = random.randint(1, F)
                y = random.randint(1, C)

            file.write(char+" "+str(x)+" "+str(y)+'\n')

        file.close()


# Subtask 1: 16 puntos $N \leq 500$, $F, C \leq 100$, $E = 1$ -> 16 casos
generate(16, 500, 100, 1, "sub1")

# Subtask 2: 16 puntos $N \leq 500$, $F, C \leq 100$-> 16 casos
generate(16, 500, 100, 1e5, "sub2")

# Subtask 3: 16 puntos $N \leq 1000$, $F, C \leq 10e5$, $E = 1$ -> 16 casos
generate(16, 1000, 1e5, 1, "sub3")

# Subtask 4: 16 puntos $N \leq 1000$, $F, C \leq 10e5$ -> 16 casos
generate(16, 1000, 1e5, 1e5, "sub4")

# Subtask 5: 16 puntos $N \leq 10e5$, $F, C \leq 10e5$, $E = 1$ -> 16 casos
generate(16, 1e5, 1e5, 1, "sub5")

# Subtask 6: 20 puntos $N \leq 10e5$, $F, C \leq 10e5$ -> 20 casos
generate(20, 1e5, 1e5, 1e5, "sub6")


testplan.close
