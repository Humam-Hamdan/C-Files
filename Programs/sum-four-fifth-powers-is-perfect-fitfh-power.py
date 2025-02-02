import time


def find_solutions(upper_limit):
    """
    Brute-force search for all solutions to a^5 + b^5 + c^5 + d^5 = e^5
    where 1 <= d <= c <= b <= a <= upper_limit

    Args:
        upper_limit (int): Maximum value for a in the search

    Returns:
        list: All found solutions as tuples (a, b, c, d, e)
    """
    solutions = []

    # Iterate through all a values from 1 to upper_limit
    for a in range(1, upper_limit + 1):
        a5 = a ** 5  # Precompute a^5 once per a

        # b ranges from 1 to a (maintain b <= a)
        for b in range(1, a + 1):
            b5 = b ** 5  # Precompute b^5 once per b

            # c ranges from 1 to b (maintain c <= b)
            for c in range(1, b + 1):
                c5 = c ** 5  # Precompute c^5 once per c

                # d ranges from 1 to c (maintain d <= c)
                for d in range(1, c + 1):
                    d5 = d ** 5  # Precompute d^5 once per d

                    # Calculate total sum of fifth powers
                    total = a5 + b5 + c5 + d5

                    # Calculate potential e by taking 5th root and rounding
                    e = round(total ** (1/5))

                    # Verify two conditions to avoid false positives:
                    # 1. e must be positive (edge case for total=0)
                    # 2. e^5 must exactly match the total sum
                    if e > 0 and e ** 5 == total:
                        solutions.append((a, b, c, d, e))

    return solutions


if __name__ == "__main__":
    print("Euler vs Fermat Solver (Complete Brute-Force)")
    upper_limit = int(input("Enter search limit: "))

    start_time = time.time()
    solutions = find_solutions(upper_limit)
    elapsed = time.time() - start_time

    print(f"\nFound {len(solutions)} solutions:")
    for i, (a, b, c, d, e) in enumerate(solutions, 1):
        print(f"Solution {i}:")
        print(f"a={a}, b={b}, c={c}, d={d}")
        print(f"e={e}\n")

    print(f"Time taken: {elapsed:.2f} seconds")
