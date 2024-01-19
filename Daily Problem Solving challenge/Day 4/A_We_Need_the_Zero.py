# Function to find the value of x for each test case
def find_x(t, test_cases):
    results = []

    for _ in range(t):
        n = test_cases[_][0]
        a = test_cases[_][1]

        # Iterate through all possible values of x (0 to 2^8 - 1)
        for x in range(1 << 8):
            b = [ai ^ x for ai in a]

            # Check if XOR of all elements in b is equal to 0
            if all(x == 0 for x in b):
                results.append(x)
                break
        else:
            # If no x is found, append -1
            results.append(-1)

    return results


# Input parsing
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append((n, a))

# Find and print the results
results = find_x(t, test_cases)
for result in results:
    print(result)
