# Read input values
n, k = map(int, input().split())

# Perform k subtractions
for _ in range(k):
    # If the last digit is non-zero, decrement the number by 1
    if n % 10 != 0:
        n -= 1
    # If the last digit is zero, divide the number by 10
    else:
        n //= 10

# Print the final result
print(n)
