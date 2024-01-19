def ThreeSum(nums):
  if len(nums) < 3:
    return []
  ans = []
  nums.sort()
  for i in range(0, len(nums)-2):
    if i > 0 and nums[i] == nums[i-1]:
      continue
    
    left, right = i + 1, len(nums)-1
    
    while left < right:
      target = nums[left] + nums[right] + nums[i]
      if target == 0:
        ans.append([nums[i], nums[left] ,  nums[right]])
        
        while left < right and nums[left] == nums[left + 1]:
          left +=1
        while left < right and nums[right] == nums[right-1]:
          right -=1
        left += 1
        right -= 1
      elif target < 0:
        left += 1
      else:
        right -= 1
  return ans
  
  
nums = [-1,0,1,2,-1,-4]

print(ThreeSum(nums))  