def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def find_fraction(n):
    for a in range(n//2, 0, -1):
        b = n - a
        if gcd(a, b) == 1:
            return a, b

n = int(input().strip())

a, b = find_fraction(n)
print(a, b)
