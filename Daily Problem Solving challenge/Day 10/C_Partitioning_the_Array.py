def earn_points(t, test_cases):
    results = []
    for i in range(t):
        n, m = test_cases[i][:2]
        subarrays = test_cases[i][2:]

        # Calculate remainders for each subarray
        subarray_remainders = [set(map(lambda x: x % m, subarray)) for subarray in subarrays]

        # Count the number of unique remainders for each subarray
        subarray_counts = [len(remainders) for remainders in subarray_remainders]

        # Calculate the total points for the given test case
        total_points = 1
        for count in subarray_counts:
            total_points = (total_points * count) % (10**9 + 7)

        results.append(total_points)

    return results

def main():
    t = int(input())
    test_cases = []
    for _ in range(t):
        n, m = map(int, input().split())
        subarrays = [list(map(int, input().split()))[1:] for _ in range(m)]
        test_cases.append((n, m) + tuple(subarrays))

    results = earn_points(t, test_cases)

    for result in results:
        print(result)

if __name__ == "__main__":
    main()
