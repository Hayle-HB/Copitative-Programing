t = int(input())

for _ in range(t):
    expression = input()

    a, b = map(int, expression.split('+'))

    result = a + b
    print(result)
