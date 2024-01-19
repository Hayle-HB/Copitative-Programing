n, m = map(int, input().split())

snake = []
for i in range(n):
    if i % 2 == 0:
        snake.append("#" * m)
    else:
        if i % 4 == 1:
            snake.append("." * (m - 1) + "#")
        else:
            snake.append("#" + "." * (m - 1))

for row in snake:
    print(row)
