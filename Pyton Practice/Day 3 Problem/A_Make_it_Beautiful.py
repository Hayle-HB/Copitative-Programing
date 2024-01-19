def make_beautiful_array(t, test_cases):
    for i in range(t):
        n = test_cases[i][0]
        a = test_cases[i][1]

        # Check if the array is already beautiful
        if any(a[j] == sum(a[:j]) for j in range(1, n)):
            print("YES")
            print(*a)
        else:
            # Reorder the array to make it beautiful
            a.sort()
            print("YES")
            print(*a)

# Input
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append((n, a))

# Output
make_beautiful_array(t, test_cases)
