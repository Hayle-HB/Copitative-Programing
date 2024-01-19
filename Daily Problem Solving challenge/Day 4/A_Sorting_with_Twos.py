def can_sort_array(n, arr):
    arr.sort()
    i = 0
    while i < n:
        if arr[i] > i:
            return "NO"
        i += 1
    return "YES"

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        result = can_sort_array(n, arr)
        print(result)

if __name__ == "__main__":
    main()
