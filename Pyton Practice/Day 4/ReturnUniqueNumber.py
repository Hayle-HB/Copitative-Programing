def uniqueNumber(list)->list:
    ans = []
    for num in list:
      if num not in ans:
        ans.append(num)
        
    return ans
  
list = [5, 2, 1, 1, 5]
print(uniqueNumber(list))
  