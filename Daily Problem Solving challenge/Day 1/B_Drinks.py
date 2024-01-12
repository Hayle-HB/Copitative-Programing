n = int(input())
percentages = list(map(int, input().split()))

# Calculate the average percentage of orange juice
average_percentage = sum(percentages) / n

print(average_percentage)
