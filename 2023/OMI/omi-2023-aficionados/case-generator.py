import os
import random
from typing import List


def print_case(file: str, N: int, favorite_teams: List[int]):
    with open(os.path.join("cases", file), "w") as f:
        f.write(f"{N}\n")
        f.write(" ".join(map(str, favorite_teams)))
        f.write("\n")


def make_case(task_number: int, case_number: int):
    MAXN = 1e5
    MAXAi = 1000

    if task_number == 1:
        # Subtarea 1. N <= 30
        MAXN = 30
    elif task_number == 2:
        # Subtarea 2. N <= 500
        MAXN = 500
    elif task_number == 3:
        # Subtarea 3. N <= 1000, ai <= 10
        MAXN = 1000
        MAXAi = 10
    elif task_number == 4:
        # Subtarea 4. Sin restricciones adicionales.
        pass
    else:
        raise ValueError(f"Invalid task number {task_number}")

    N = random.randint(2, MAXN)
    favorite_teams = [random.randint(1, MAXAi) for _ in range(N)]
    print_case(f"sub{task_number}.{case_number}.in", N, favorite_teams)


if __name__ == '__main__':
    points_per_task = [15, 20, 25, 40]
    with open("testplan", "w") as testplan:
        for t, points in enumerate(points_per_task):
            for c in range(5):
                make_case(t + 1, c + 1)
                testplan.write(f"sub{t + 1}.{c + 1} {points}\n")
                points = 0
