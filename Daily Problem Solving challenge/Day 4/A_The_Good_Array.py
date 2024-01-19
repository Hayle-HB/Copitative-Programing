import math

def min_ones_in_good_array(n, k):
    min_ones = float('inf')

    for ones in range(1, n + 1):
        for i in range(1, n + 1):
            if math.ceil(i / k) <= ones and math.ceil((n - i + 1) / k) <= ones:
                min_ones = min(min_ones, ones)

    return min_ones

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        result = min_ones_in_good_array(n, k)
        print(result)

if __name__ == "__main__":
    main()
