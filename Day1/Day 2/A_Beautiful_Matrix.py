def beautiful_matrix(matrix):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == 1:
                return abs(2 - i) + abs(2 - j)

matrix = [list(map(int, input().split())) for _ in range(5)]

for i in range(5):
    for j in range(5):
        if matrix[i][j] == 1:
            target_i, target_j = 2, 2
            result = abs(target_i - i) + abs(target_j - j)

print(result)
