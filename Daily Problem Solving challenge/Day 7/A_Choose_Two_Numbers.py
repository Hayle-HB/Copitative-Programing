n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

# Sort arrays a and b in ascending order
a.sort()
b.sort()

# Choose any element from array a and array b
# such that a + b doesn't belong to either a or b
print(a[-1], b[-1])
