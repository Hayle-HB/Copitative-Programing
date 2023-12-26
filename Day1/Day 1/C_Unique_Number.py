def smallest_number_with_unique_digit_sum(target_sum):
    if target_sum > 45:
        return -1  # Not possible to have unique digits with a sum greater than 45

    current_sum = 0
    current_number = 0
    result_digits = []

    while current_sum < target_sum:
        current_number += 1
        digits = [int(digit) for digit in set(str(current_number))]  # Use set to get unique digits
        current_sum = sum(digits)
        result_digits = digits  # Store the current digits as a potential result

    if current_sum == target_sum and len(result_digits) == len(set(result_digits)):
        return int(''.join(map(str, result_digits)))
    else:
        return -1  # Not possible to have unique digits with the given sum


t = int(input())
for _ in range(t):
    num = int(input())
    result = smallest_number_with_unique_digit_sum(num)
    print(result)
