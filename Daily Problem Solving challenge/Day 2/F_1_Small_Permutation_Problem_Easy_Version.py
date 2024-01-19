MOD = 998244353

# Function to calculate the number of good permutations
def good_permutations(n, a):
    count = [0] * (n + 1)
    for ai in a:
        count[ai] += 1

    result = 1
    current = 0

    for i in range(1, n + 1):
        current += count[i]
        result = (result * max(0, current - i)) % MOD

    return result

def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        result = good_permutations(n, a)
        print(result)

# Run the main function
if __name__ == "__main__":
    main()
