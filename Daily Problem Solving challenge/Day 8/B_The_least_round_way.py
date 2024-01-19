n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

# Initialize dp array to store the minimum number of trailing zeros for each cell
dp = [[0] * n for _ in range(n)]
dp[0][0] = matrix[0][0]

# Fill the first row and first column of dp array
for i in range(1, n):
    dp[0][i] = dp[0][i - 1] * matrix[0][i]
    dp[i][0] = dp[i - 1][0] * matrix[i][0]

# Fill the rest of the dp array
for i in range(1, n):
    for j in range(1, n):
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) * matrix[i][j]

# Find the least number of trailing zeros
min_zeros = len(str(dp[-1][-1])) - len(str(dp[-1][-1]).rstrip('0'))

# Find the correspondent way
i, j = n - 1, n - 1
way = []

while i > 0 or j > 0:
    if i == 0:
        way.append('R')
        j -= 1
    elif j == 0:
        way.append('D')
        i -= 1
    elif dp[i - 1][j] < dp[i][j - 1]:
        way.append('D')
        i -= 1
    else:
        way.append('R')
        j -= 1

# Reverse the way as we are backtracking
way.reverse()

# Output the result
print(min_zeros)
print(''.join(way))
