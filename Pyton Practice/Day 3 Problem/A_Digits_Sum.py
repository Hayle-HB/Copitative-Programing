def count_interesting_numbers(t, test_cases):
    results = []

    for n in test_cases:
        count = 0
        x = 1

        while x <= n:
            sum_x = sum(map(int, str(x)))
            sum_x_plus_1 = sum(map(int, str(x + 1)))

            if sum_x_plus_1 < sum_x:
                count += 1

            x += 1

        results.append(count)

    return results


# Input reading
t = int(input())
test_cases = [int(input()) for _ in range(t)]

# Calculate and print results
results = count_interesting_numbers(t, test_cases)
for result in results:
    print(result)
