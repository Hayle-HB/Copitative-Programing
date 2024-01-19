def can_make_lower_or_equal(t, test_cases):
    results = []
    
    for i in range(t):
        n, d = test_cases[i][:2]
        arr = test_cases[i][2]
        
        max_val = max(arr)
        sorted_arr = sorted(arr)
        
        if max_val <= d:
            results.append("YES")
        elif sorted_arr[0] + sorted_arr[1] <= d or sorted_arr[-1] <= d:
            results.append("YES")
        else:
            results.append("NO")
    
    return results

# Input reading
t = int(input())
test_cases = []

for _ in range(t):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))
    test_cases.append((n, d, arr))

# Output
results = can_make_lower_or_equal(t, test_cases)
for result in results:
    print(result)
