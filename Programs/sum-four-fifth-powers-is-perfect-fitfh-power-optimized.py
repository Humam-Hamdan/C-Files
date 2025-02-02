from collections import defaultdict
import time


def find_solutions(upper_limit):
    # Store FIRST valid (c,d) for each sum
    sum_cd = {}
    for c in range(1, upper_limit + 1):
        c5 = c**5
        for d in range(1, c + 1):
            s = c5 + d**5
            if s not in sum_cd:  # Store only first occurrence
                sum_cd[s] = (c, d)

    solutions = []
    for a in range(1, upper_limit + 1):
        a5 = a**5
        for b in range(1, a + 1):
            s_ab = a5 + b**5
            e_max = int((s_ab + 2*b**5)**0.2) + 2
            for e in range(1, e_max + 1):
                target = e**5 - s_ab
                if target in sum_cd:
                    c, d = sum_cd[target]
                    if c <= b and d <= c:
                        solutions.append((a, b, c, d, e))
    return solutions
