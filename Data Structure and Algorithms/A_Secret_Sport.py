def determine_winner(t, test_cases):
    results = []

    for _ in range(t):
        n, s = test_cases[_]

        # Count the number of wins for each player
        wins_A = s.count('A')
        wins_B = s.count('B')

        # Check if A or B is guaranteed to be the winner
        if wins_A >= wins_B + 1:
            results.append('A')  # Player A is guaranteed to be the winner
        elif wins_B >= wins_A + 1:
            results.append('B')  # Player B is guaranteed to be the winner
        else:
            results.append('?')  # It is impossible to determine the winner

    return results

# Input
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    s = input().strip()
    test_cases.append((n, s))

# Output
results = determine_winner(t, test_cases)
for result in results:
    print(result)
