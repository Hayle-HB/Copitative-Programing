from builtins import set

x = [5, 2, 3, 4, 5]
y = [3, 4, 5, 5, 7]

z = [common for common in x if common in y]
z = set(z)

print(z)
