import random
from datetime import datetime

def actual_time():
    return f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}]"

# Generate cases according to the subtasks list
def generate_task(amount, score, testplan, subtask_name, limit_NM, unique):
    for i in range(amount):

        case_name = f"{subtask_name}.{i + 1}.in"
        print(f"{actual_time()} Generating case ({case_name[:-3]})")

        with open(f"cases/{case_name}", "w") as case_data:
            rand_n = random.randint(1, limit_NM)
            rand_m = random.randint(1, limit_NM)
            rand_r = random.randint(1, rand_n)

            case_data.write(f"{rand_n} {rand_m} {rand_r}\n")
            rand_a, rand_b = 0, 0

            if unique:
                while rand_a == rand_b:
                    rand_a = random.randint(3, rand_n)
                    rand_b = random.randint(1, rand_a)

                case_data.write(f"{rand_a} {rand_b}\n")
                rand_m -= 1

            for j in range(rand_m):
                rand_a, rand_b = 0, 0
                while rand_a == rand_b:
                    rand_b = random.randint(3, rand_n)
                    rand_a = random.randint(1, rand_b)
                case_data.write(f"{rand_a} {rand_b}\n")

        print(f"{actual_time()} Adding ({case_name[:-3]}) to the testplan")
        testplan.write(f"{case_name[:-3]} ")

        if i == 0:
            testplan.write(f"{score}\n")
        else:
            testplan.write("0\n")

with open("testplan", "w") as testplan:

    generate_task(10, 12, testplan, "sub1", int(1e3), False)
    generate_task(10, 24, testplan, "sub2", int(1e5), False)
    generate_task(10, 12, testplan, "sub3", int(1e3), True)
    generate_task(10, 24, testplan, "sub4", int(1e5), True)
    generate_task(10, 28, testplan, "sub5", int(1e5), True)

# EOF -------o