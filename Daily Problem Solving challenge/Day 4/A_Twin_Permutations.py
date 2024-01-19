def solve_test_case(n, a):
    b = [0] * n

    # Sort the array a in non-decreasing order
    sorted_a = sorted(enumerate(a, start=1), key=lambda x: x[1])

    # Construct the permutation b based on the sorted indices
    for i, (_, ai) in enumerate(sorted_a):
        b[i] = ai

    return b

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        result = solve_test_case(n, a)
        print(*result)

if __name__ == "__main__":
    main()
