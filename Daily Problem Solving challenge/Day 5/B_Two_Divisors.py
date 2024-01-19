# Function to find the number x given divisors a and b
def find_x(a, b):
    # x is the product of a and b
    x = a * b
    return x

# Function to solve the problem for multiple test cases
def solve_test_cases(t, test_cases):
    results = []
    for i in range(t):
        a, b = test_cases[i]
        x = find_x(a, b)
        results.append(x)
    return results

# Input reading
t = int(input())  # Number of test cases
test_cases = []   # List to store test cases
for _ in range(t):
    a, b = map(int, input().split())
    test_cases.append((a, b))

# Solve the problem for the given test cases
results = solve_test_cases(t, test_cases)

# Output the results
for x in results:
    print(x)
