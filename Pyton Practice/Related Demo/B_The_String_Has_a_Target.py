def lexicographically_minimal_string(t, test_cases):
    results = []

    for _ in range(t):
        n, s = test_cases[_]
        min_char = min(s)
        rightmost_min_char = max(r for r, char in enumerate(s) if char == min_char)
        result = s[rightmost_min_char] + s[:rightmost_min_char] + s[rightmost_min_char + 1:]
        results.append(result)

    return results

t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    s = input()
    test_cases.append((n, s))

results = lexicographically_minimal_string(t, test_cases)
for result in results:
    print(result)
