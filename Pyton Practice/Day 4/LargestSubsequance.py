def longest_consecutive_subsequence(list):
  return max( list.count(num for i in range(len(list)-1) if list[i] == list[i+1]))
    
    
list = [1, 2, 3, 4]

print(longest_consecutive_subsequence(list))