# Read input value
n = int(input())

# Initialize a variable to count rooms with free space
rooms_with_space = 0

# Iterate through each room
for _ in range(n):
    # Read the number of people already living and the room's capacity
    p, q = map(int, input().split())
    
    # Check if there is free space for both George and Alex
    if q - p >= 2:
        rooms_with_space += 1

# Print the result
print(rooms_with_space)
