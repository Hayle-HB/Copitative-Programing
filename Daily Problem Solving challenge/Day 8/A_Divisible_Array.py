def solve(test_cases):
    result = []
    for n in test_cases:
        # Initialize array with all elements as 1
        array = [1] * n

        # Adjust elements to satisfy conditions
        for i in range(2, n):
            array[i] = array[i - 1] * i

        # Adjust the sum to be divisible by n
        total = sum(array)
        remainder = total % n
        if remainder != 0:
            array[n - 1] += n - remainder

        result.append(array)
    return result


# Read the number of test cases
t = int(input())

# Read test cases and store in a list
test_cases = []
for _ in range(t):
    n = int(input())
    test_cases.append(n)

# Solve the problem
result = solve(test_cases)

# Print the result for each test case
for arr in result:
    print(" ".join(map(str, arr)))
