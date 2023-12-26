n = int(input())
friends_fingers = list(map(int, input().split()))

total_fingers = sum(friends_fingers)
count = 0

for i in range(1, 6):
    if (total_fingers + i) % (n + 1) != 1:
        count += 1

print(count)
