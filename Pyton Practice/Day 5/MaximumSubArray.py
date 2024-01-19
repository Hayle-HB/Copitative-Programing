def maxSubarrayWithEqualOddEven(arr):
    n = len(arr)

    # Initialize variables for max sum and starting index of max subarray
    max_sum = 0
    start = -1

    # Create arrays to store counts of odd and even numbers up to each index
    odd_count = [0] * n
    even_count = [0] * n

    # Initialize counts for the first element
    if arr[0] % 2 == 0:
        even_count[0] = 1
    else:
        odd_count[0] = 1

    # Populate counts arrays and find max subarray
    
    for i in range(1, n):
        if arr[i] % 2 == 0:
            even_count[i] = even_count[i - 1] + 1
            odd_count[i] = odd_count[i - 1]
        else:
            even_count[i] = even_count[i - 1]
            odd_count[i] = odd_count[i - 1] + 1

        if even_count[i] == odd_count[i]:
            max_sum = i + 1
            start = 0

        for j in range(0, i):
            if even_count[i] == even_count[j] + odd_count[i] - odd_count[j]:
                if i - j + 1 > max_sum:
                    max_sum = i - j + 1
                    start = j + 1

    # Print the maximum subarray
    print("Maximum Subarray with Equal Odd and Even Numbers:")
    print(arr[start:start + max_sum])
    return max_sum

# Example usage:
arr = [2, 2, 5, 1, 6, 3, 1, 2, 3]
result = maxSubarrayWithEqualOddEven(arr)
print("Length of Maximum Subarray:", result)
