a = input()
b = input()

result = ''.join('1' if x != y else '0' for x, y in zip(a, b))

print(result)
