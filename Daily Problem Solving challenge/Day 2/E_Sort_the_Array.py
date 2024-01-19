n = int(input())
a = list(map(int, input().split()))

start, end = -1, -1

for i in range(n - 1):
    if a[i] > a[i + 1]:
        start = i
        break

if start == -1:
    print("yes\n1 1")
    exit(0)

for i in range(n - 1, start, -1):
    if a[i] < a[i - 1]:
        end = i
        break

a[start:end + 1] = reversed(a[start:end + 1])

if any(a[i] > a[i + 1] for i in range(n - 1)):
    print("no")
else:
    print("yes")
    print(start + 1, end + 1)
