def minimize_path_length(t, testcases):
    results = []
    for _ in range(t):
        n, a = testcases[_]
        a_sorted = sorted(enumerate(a, 1), key=lambda x: x[1])

        path_length = 0
        path = []

        for i in range(0, 2 * n, 2):
            point1, x1 = a_sorted[i]
            point2, x2 = a_sorted[i + 1]
            path_length += abs(x1 - x2)
            path.append((point1, point2))

        results.append((path_length, path))

    return results

# Input reading and function calling
t = int(input())
testcases = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    testcases.append((n, a))

results = minimize_path_length(t, testcases)

# Output results
for res in results:
    print(res[0])
    for point in res[1]:
        print(point[0], point[1])
