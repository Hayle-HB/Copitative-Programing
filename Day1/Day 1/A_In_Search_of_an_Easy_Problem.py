# Read input values
n = int(input())
opinions = list(map(int, input().split()))

# Check if there is at least one person who thinks the problem is hard
if 1 in opinions:
    print("HARD")
else:
    print("EASY")
