n = int(input())
gifts = list(map(int, input().split()))

result = [0] * n

for i in range(n):
    result[gifts[i] - 1] = i + 1

print(*result)
