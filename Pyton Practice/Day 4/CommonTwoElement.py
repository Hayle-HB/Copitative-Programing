def findCommon(list1, list2) -> list:
  ans = []
  
  for num in list1:
    if num in list2:
      if num not in ans:
        ans.append(num)
  return ans
def moreThanLength3(list):
  ans = []
  for i in list:
    if len(i) >= 3:
      ans.append(i)
      
  return ans

list = [1, 2, 3, 4]
list2 = [2, 2, 3, 4, 5]
listString = ["I", "am", "not", "a", "bad" , "person", "but", "that", "does", "not", "make", "me", "a", "good", "man"]

print(findCommon(list, list2))
print(listString)
print(moreThanLength3(listString), end = ' ')