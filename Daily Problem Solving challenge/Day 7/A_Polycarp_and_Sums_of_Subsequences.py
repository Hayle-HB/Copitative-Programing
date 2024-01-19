def restore_array(b):
    a = [0, 0, 0]
    a[2] = b[6] - b[5]  # a3 = b[7] - b[6]
    a[1] = b[4] - a[2]  # a2 = b[5] - a3
    a[0] = b[0] - a[1]  # a1 = b[1] - a2

    return a


t = int(input())
for _ in range(t):
    b = list(map(int, input().split()))
    result = restore_array(b)
    print(*result)
