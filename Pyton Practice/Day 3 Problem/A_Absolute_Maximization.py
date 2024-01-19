def max_difference(t, test_cases):
    for i in range(t):
        n = test_cases[i][0]
        a = test_cases[i][1]

        # Find the maximum and minimum values in the array
        max_val = max(a)
        min_val = min(a)

        # Initialize the maximum difference
        max_diff = max_val - min_val

        # Iterate through all possible swaps
        for i in range(n):
            for j in range(i + 1, n):
                # Swap the b-th bit in the binary representation of ai and aj
                ai_b = a[i]
                aj_b = a[j]

                # Calculate the new maximum and minimum values
                new_max_val = max(max_val, ai_b, aj_b)
                new_min_val = min(min_val, ai_b, aj_b)

                # Update the maximum difference
                max_diff = max(max_diff, new_max_val - new_min_val)

        print(max_diff)

# Input
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append((n, a))

# Output
max_difference(t, test_cases)
