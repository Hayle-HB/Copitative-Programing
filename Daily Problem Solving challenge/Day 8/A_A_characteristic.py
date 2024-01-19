def generate_array(n, k):
    if k % 2 != n % 2 or k > (n - 1) * n // 2:
        return "NO"
    
    array = [1] * n
    
    num_minus_ones = (n - k) // 2
    
    for i in range(num_minus_ones):
        array[i] = -1
    
    return "YES\n" + " ".join(map(str, array))

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    result = generate_array(n, k)
    print(result)
