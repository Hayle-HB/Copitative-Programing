
class Solution:
    def maxScore(self, List: List[int], k: int) -> int:
      total_points = sum(List)
      n = len(List)
      
      window_sum = sum(List[:n - k])
      
      min_window_sum = window_sum
      
      for i in range(n - k, n):
          window_sum = window_sum - List[i - (n - k)] + List[i]
          min_window_sum = min(min_window_sum, window_sum)
      
      return total_points - min_window_sum
