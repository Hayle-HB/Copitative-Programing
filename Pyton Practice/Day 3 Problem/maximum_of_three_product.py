def max_product_of_three(nums):
    nums.sort()
    max_pro = max(nums[0]*nums[1]*nums[-1], nums[-2]*nums[-3]*nums[-1])
    
    return max_pro

# Test the function
numbers = [2, -5, 3, 1, -2, 6, -4, 2, 0, -3]
result = max_product_of_three(numbers)
print(result)  # Output should be 120  # (-5 * -4 * 6)
