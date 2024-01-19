def two_number_sum_in_sorted_array(nums, target):
  left_pointer, right_pointer = 0, len(nums) - 1
  
  while left_pointer < right_pointer:
    sum = nums[left_pointer] + nums[right_pointer]
    
    if sum == target:
      return nums[left_pointer] ,  nums[right_pointer]
    elif sum < target:
      left_pointer += 1
    else:
      right_pointer -= 1
      
  return None

nums = [1, 2, 3, 4, 5 , 6, 7, 8]

print(two_number_sum_in_sorted_array(nums, 15))