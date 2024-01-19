def uniqueNumber(list):
    ans = []
    for num in list:
      count = list.count(num)
      if count == 1:
        ans.append(num)
    return ans
  
list = [1 , 4, 1, 4, 5, 5, 10]

print(uniqueNumber(list))