def min_difference(t, test_cases):
    results = []

    for case in test_cases:
        n, m = case[0], case[1]
        words = case[2:]

        min_diff = float('inf')

        for i in range(n - 1):
            for j in range(i + 1, n):
                diff = 0
                for k in range(m):
                    diff += min(abs(ord(words[i][k]) - ord(words[j][k])), 26 - abs(ord(words[i][k]) - ord(words[j][k])))
                min_diff = min(min_diff, diff)

        results.append(min_diff)

    return results


# Input reading
t = int(input())
test_cases = []

for _ in range(t):
    n, m = map(int, input().split())
    words = [input().strip() for _ in range(n)]
    test_cases.append([n, m] + words)

# Calculate and print results
results = min_difference(t, test_cases)
for result in results:
    print(result)
