def commonElement(list1: list, list2: list) -> list:
  ans = []
  
  for num1 in list1:
    if num1 in list2:
      ans.append(num1)
      list2.remove(num1)
  return ans

list1 = [2, 2, 3, 4]
list2 = [3, 2, 2, 6]
print(commonElement(list1, list2))