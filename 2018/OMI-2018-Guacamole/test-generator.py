import random


primos = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
          31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
          73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
          127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
          179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
          233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
          283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
          353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
          419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
          467, 479, 487, 491, 499]


def reallyRandom():
    n = random.randint(1, 3)
    num = 1
    for i in range(n):
        num *= random.choice(primos)
    return random.randint(-1000000000, 1000000000) % (num * random.choice([-1, 1]))


for caso in range(25):
    n = 100
    m = 100
    st = 'case' + str(caso) + '.in'
    if caso < 10:
        n = random.randint(1, 100)
        m = random.randint(1, 100)

    w = open(st, 'w')
    T = random.randint(1, 500)
    w.write(str(n) + ' ' + str(m) + ' ' + str(T) + '\n')
    for i in range(n):
        line = str(random.randint(1, T) % random.randint(1, T) + 1)
        for j in range(m - 1):
            line += ' ' + str(random.randint(1, T) % random.randint(1, T) + 1)
        line += '\n'
        w.write(line)

    for i in range(n):
        line = str(random.randint(1, T) % random.randint(1, T) + 1)
        for j in range(m - 1):
            line += ' ' + str(random.randint(1, T) % random.randint(1, T) + 1)
        line += '\n'
        w.write(line)

    for i in range(n):
        line = str(reallyRandom())
        for j in range(m - 1):
            line += ' ' + str(reallyRandom())
        line += '\n'
        w.write(line)