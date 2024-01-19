MOD1 = 998244353
MOD2 = 1000000007

# Function to calculate the modular exponentiation (x^y mod MOD)
def power(x, y, mod):
    result = 1
    x = x % mod
    while y > 0:
        if y & 1:
            result = (result * x) % mod
        y = y >> 1
        x = (x * x) % mod
    return result

# Function to calculate the inverse modulo (1/x mod MOD)
def mod_inverse(x, mod):
    return power(x, mod - 2, mod)

# Function to calculate the binomial coefficient (n choose k) mod MOD
def nCr(n, r, mod):
    if r == 0:
        return 1
    if r > n:
        return 0
    numerator = 1
    denominator = 1
    for i in range(r):
        numerator = (numerator * (n - i)) % mod
        denominator = (denominator * (i + 1)) % mod
    return (numerator * mod_inverse(denominator, mod)) % mod

# Function to calculate the number of good permutations
def good_permutations(n, x):
    result = 0
    for m in range(3, n + 2):
        for k in range(n):
            result = (result + nCr(m - 3, k, MOD1) * power(x, m * n + k, MOD2)) % MOD2
    return result

# Main function to process input and output
def main():
    n, x = map(int, input().split())
    result = good_permutations(n, x)
    print(result)

# Run the main function
if __name__ == "__main__":
    main()
