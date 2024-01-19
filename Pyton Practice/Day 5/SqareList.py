def square_numbers(numbers):
    squares = [num ** 2 for num in numbers]
    return squares

input_numbers = [1, 2, 3, 4, 5]
result = square_numbers(input_numbers)
print(f"The squares of the numbers are: {result}")
