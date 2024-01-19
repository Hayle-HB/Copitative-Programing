MOD = 998244353

def count_binary_strings(n, k):
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        for j in range(1, i + 1):
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * (i - j + 1)) % MOD

    result = 0
    for j in range(1, k + 1):
        result = (result + dp[n][j]) % MOD

    return result

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        result = count_binary_strings(n, k)
        print(result)

if __name__ == "__main__":
    main()
