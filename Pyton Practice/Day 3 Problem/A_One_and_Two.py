t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    total_product = 1
    for num in a:
        total_product *= num

    left_product = 1
    right_product = total_product
    k_found = False

    for k in range(1, n):
        left_product *= a[k - 1]
        right_product //= a[k - 1]

        if left_product == right_product:
            print(k)
            k_found = True
            break

    if not k_found:
        print(-1)
