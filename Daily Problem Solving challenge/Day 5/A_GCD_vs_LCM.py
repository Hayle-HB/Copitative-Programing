import math

def find_numbers(n):
    # Start with minimum values
    a, b, c, d = 1, 1, 1, 1

    # Iterate until the conditions are satisfied
    while a + b + c + d != n or math.gcd(a, b) != math.lcm(c, d):
        # Increment values
        if a + b + c + d < n:
            if a == b:
                b += 1
            elif c == d:
                d += 1
            else:
                a += 1
        else:
            if a == b:
                c += 1
            elif c == d:
                b += 1
            else:
                d += 1

    return a, b, c, d

# Input number of test cases
t = int(input())

for _ in range(t):
    # Input value of n
    n = int(input())

    # Find and print the numbers
    result = find_numbers(n)
    print(*result)
