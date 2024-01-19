t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    max_blank_space = 0
    current_blank_space = 0

    for num in arr:
        if num == 0:
            current_blank_space += 1
        else:
            max_blank_space = max(max_blank_space, current_blank_space)
            current_blank_space = 0

    max_blank_space = max(max_blank_space, current_blank_space)
    print(max_blank_space)
