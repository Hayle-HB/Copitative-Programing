List = []

for i in range(5):
  List.append(input("Enter list: "))
  
  
NewList = []

NewList.extend(List)
for i in NewList:
  print(i, end = "  ")

NewList.sort(key = lambda x: x)