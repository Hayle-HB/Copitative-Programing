def min_operations(n, arr):
    max_val = max(arr)
    total_ops = 0
    
    for i in range(n):
        total_ops += max_val - arr[i]
    
    return total_ops

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        
        result = min_operations(n, arr)
        print(result)

if __name__ == "__main__":
    main()
