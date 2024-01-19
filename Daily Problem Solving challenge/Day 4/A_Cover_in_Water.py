def minimal_actions_to_fill(t, test_cases):
    results = []
    
    for _ in range(t):
        n, s = test_cases[_]
        
        # Count the number of empty cells with both neighbors filled
        actions = sum(1 for i in range(1, n - 1) if s[i] == '.' and s[i-1] == '#' and s[i+1] == '#')
        
        results.append(actions)
    
    return results

# Input processing
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    s = input()
    test_cases.append((n, s))

# Calculate and output the results
results = minimal_actions_to_fill(t, test_cases)

for res in results:
    print(res)
