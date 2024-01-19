n = int(input())
move = 0

while n != 0:
    a = int(input())
    b = int(input())

    while a % b != 0:
        a += 1
        move += 1

    print(move)
    move = 0
    n -= 1
