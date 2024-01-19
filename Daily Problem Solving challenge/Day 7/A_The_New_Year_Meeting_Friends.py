x1, x2, x3 = map(int, input().split())

coordinates = [x1, x2, x3]
coordinates.sort()

median = coordinates[1]  # The middle value after sorting

distance = abs(x1 - median) + abs(x2 - median) + abs(x3 - median)

print(distance)
