from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]

        low, high = 0, len(nums) - 1
        start, end = -1, -1

        while low <= high:
            mid = (low + high) // 2

            if nums[mid] == target:
                start = mid
                high = mid - 1
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) // 2

            if nums[mid] == target:
                end = mid
                low = mid + 1
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        if start != -1 and end != -1:
            return [start, end]
        else:
            return [-1, -1]

sol = Solution()
myList = [1, 2, 3, 4, 4, 4, 5, 6]
answer = sol.searchRange(myList, 4)
print(answer)
