def find_smallest_k_beautiful(x, k):
    current_sum = sum(map(int, str(x)))
    while current_sum % k != 0:
        x += 1
        current_sum = sum(map(int, str(x)))
    return x

def main():
    t = int(input())
    for _ in range(t):
        x, k = map(int, input().split())
        result = find_smallest_k_beautiful(x, k)
        print(result)

if __name__ == "__main__":
    main()
