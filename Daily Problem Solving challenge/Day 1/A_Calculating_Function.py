n = int(input())

# If n is even, f(n) is n/2
# If n is odd, f(n) is -(n+1)/2
result = n // 2 if n % 2 == 0 else -(n + 1) // 2

print(result)
