def solve(test_cases):
    results = []
    for t in test_cases:
        n, k = t[0]
        array = t[1]

        # Calculate the maximum score
        max_score = max(array[:k])

        # Iterate over possible positions for the selected k elements
        for i in range(k):
            current_sum = 0
            idx = i
            while idx < n:
                current_sum += array[idx]
                idx += k
            max_score = max(max_score, current_sum)

        results.append(max_score)

    return results


# Read the number of test cases
t = int(input())

# Read test cases and store in a list
test_cases = []
for _ in range(t):
    nk = list(map(int, input().split()))
    a = list(map(int, input().split()))
    test_cases.append((nk, a))

# Solve the problem
result = solve(test_cases)

# Print the result for each test case
for res in result:
    print(res)
