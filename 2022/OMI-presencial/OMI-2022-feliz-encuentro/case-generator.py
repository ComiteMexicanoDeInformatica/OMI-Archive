import bisect
import os
import random
import string


# Precalcula k menos el número de felices encuentros en el rango [1, k]
def computePrefixSum(text):
    prefixSum = [0, 0]
    for i in range(1, len(text)):
        prefixSum.append(prefixSum[-1] + (text[i] == text[i - 1]))
    # pylint: disable=consider-using-enumerate
    for i in range(len(prefixSum)):
        prefixSum[i] = i - prefixSum[i]
    return prefixSum


# pylint: disable=too-many-arguments
def makeCase(casePath, T, Q, text, L, R):
    with open(casePath, 'w') as f:
        f.write(f"{T} {Q}\n")
        f.write(f"{text}\n")
        for Li, Ri in zip(L, R):
            f.write(f"{Li} {Ri}\n")


def generateCase(taskNumber, caseNumber):
    # Subtarea 1: T, Q <= 1000
    if taskNumber == 1:
        T = random.randint(1, 1000)
        Q = random.randint(1, 1000)
    # T, Q <= 10^5
    else:
        T = random.randint(1, 1e5)
        Q = random.randint(1, 1e5)

    # Subtarea 2: El texto contiene únicamente las letras 'A' y 'B'
    if taskNumber == 2:
        alphabet = ['A', 'B']
        text = ''.join(random.choices(alphabet, k=T))
    # El texto contiene letras mayúsculas y números
    else:
        groupSum = 0
        groups = []
        while groupSum < T:
            # Para los primeros casos, restringe el tamaño máximo de un grupo
            # de caracteres iguales consecutivos y posteriormente relaja esta
            # condición. De esta forma, debería ser posible encontrarse tanto
            # con casos donde hay grupos pequeños como con casos donde hay
            # grupos grandes de caracteres iguales consecutivos.
            minGroupSize = min(2, T - groupSum) if caseNumber == 0 else 1
            maxGroupSize = min(2**(caseNumber + 1), T - groupSum)
            groups.append(random.randint(minGroupSize, maxGroupSize))
            groupSum += groups[-1]
        alphabet = string.ascii_uppercase + string.digits
        text = ''.join(n * random.choice(alphabet) for n in groups)

    # Subtarea 3: Li = 1 para todas las preguntas
    if taskNumber == 3:
        L = [1 for _ in range(Q)]
        R = [random.randint(1, T) for _ in range(Q)]
    # Subtarea 4: 100 > Ri - Li - Ai donde Ai es la respuesta a la i-ésima
    # pregunta
    elif taskNumber == 4:
        # Sea F[Ri] el número de felices encuentros en el rango [1, Ri].
        # Buscamos el mayor Ri para el cual
        #                  100 > Ri - Li - (F[Ri] - F[Li])
        #     100 + Li - F[Li] > Ri - F[Ri]
        # Como k - F[k] es monótona creciente, podemos encontrar Ri con una
        # búsqueda binaria.
        prefixSum = computePrefixSum(text)
        L = [random.randint(1, T) for _ in range(Q)]
        maxR = [bisect.bisect_left(prefixSum, prefixSum[L[i]] + 100, L[i] + 1)
                for i in range(Q)]
        R = [random.randint(L[i], maxR[i] - 1) for i in range(Q)]
    # Sin restricciones adicionales
    else:
        L = [random.randint(1, T) for _ in range(Q)]
        R = [random.randint(L[i], T) for i in range(Q)]

    casePath = os.path.join("cases", f"sub{taskNumber}.{caseNumber}.in")
    makeCase(casePath, T, Q, text, L, R)


if __name__ == '__main__':
    for t in range(1, 6):
        for c in range(6):
            generateCase(t, c)
