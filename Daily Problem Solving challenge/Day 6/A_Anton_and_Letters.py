def count_distinct_letters(input_string):
    # Check if the input string is empty
    if input_string == "{}":
        return 0

    # Extract letters between curly braces
    letters = input_string[1:-1].split(", ")

    # Use a set to store distinct letters
    distinct_letters = set()

    # Iterate through letters and add to the set
    for letter in letters:
        distinct_letters.add(letter)

    # Return the number of distinct letters
    return len(distinct_letters)

# Read input
input_string = input().strip()

# Call the function and print the result
result = count_distinct_letters(input_string)
print(result)
