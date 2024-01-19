def find_good_pair(n, a):
    # Choose i=1 and j=2
    i, j = 1, 2

    return i, j

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        i, j = find_good_pair(n, a)
        print(i, j)

if __name__ == "__main__":
    main()
