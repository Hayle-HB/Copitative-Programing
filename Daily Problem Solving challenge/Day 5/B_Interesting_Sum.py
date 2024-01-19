def max_beauty(n, a):
    max_left = [0] * n
    min_left = [float('inf')] * n

    max_right = [0] * n
    min_right = [float('inf')] * n

    max_val = float('-inf')

    for i in range(n):
        max_val = max(max_val, a[i])
        max_left[i] = max_val
        min_left[i] = min_left[i - 1] if i > 0 else a[i]

    max_val = float('-inf')

    for i in range(n - 1, -1, -1):
        max_val = max(max_val, a[i])
        max_right[i] = max_val
        min_right[i] = min_right[i + 1] if i < n - 1 else a[i]

    max_beauty_value = 0

    for i in range(1, n - 1):
        beauty_value = max(max_left[i - 1] - min_left[i - 1],
                           max_right[i + 1] - min_right[i + 1]) + max(a[i] - min_left[i - 1], max_right[i + 1] - a[i])
        max_beauty_value = max(max_beauty_value, beauty_value)

    return max_beauty_value


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    result = max_beauty(n, a)
    print(result)
